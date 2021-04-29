#include "RootWindow.hpp"
#include "App.hpp"
#include "Config.hpp"

wxDEFINE_EVENT(wxEVT_gridUpdate, wxThreadEvent);
wxBEGIN_EVENT_TABLE(RootWindow, wxFrame)
	EVT_THREAD(wxEVT_gridUpdate, RootWindow::onGridUpdate)
	EVT_CLOSE(RootWindow::onClose)
wxEND_EVENT_TABLE()

const wxSize DEFAULT_SIZE = wxSize(DEFAULT_RESOLUTION + LEFT_PANEL_WIDTH, DEFAULT_RESOLUTION);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Mandelbrot v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, DEFAULT_SIZE, (wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER))
	, parent(new wxPanel(this, wxID_ANY))
	, left_panel(new LeftPanel(parent, DEFAULT_RESOLUTION))
	, canvas(new Canvas(parent, DEFAULT_RESOLUTION))
{
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 0, wxALL | wxEXPAND);
	hbox->Add(canvas, wxALL | wxEXPAND, wxALL | wxEXPAND);

	parent->SetSizer(hbox);
	this->Center();

	setParameters(DEFAULT_RESOLUTION,	DEFAULT_THRESHOLD, DEFAULT_MAX_ITERATIONS);
}

void RootWindow::setParameters(const uint64_t new_resolution, const double new_threshold, const uint64_t new_max_iterations)
{
	resolution = new_resolution;
	threshold = new_threshold;
	max_iterations = new_max_iterations;

	if (CreateThread(wxTHREAD_JOINABLE) != wxTHREAD_NO_ERROR)
	{
		wxLogError("Could not create worker thread!");
		return;
	}

	if (GetThread()->Run() != wxTHREAD_NO_ERROR)
	{
		wxLogError("Could not run worker thread!");
		return;
	}
}

void RootWindow::onGridUpdate(wxThreadEvent&)
{
	wxCriticalSectionLocker lock(gridCS);
	SetSize(wxSize(resolution + LEFT_PANEL_WIDTH, resolution));
	canvas->drawRGBData(Mandelbrot::getRGBData(grid, max_iterations), resolution);
}

void RootWindow::onClose(wxCloseEvent&)
{
	if (GetThread() && GetThread()->IsRunning())
		GetThread()->Wait();

	Destroy();
}

wxThread::ExitCode RootWindow::Entry()
{
	wxCriticalSectionLocker lock(gridCS);
	grid = Mandelbrot::evaluate(resolution,	threshold, max_iterations);
	wxQueueEvent(this, new wxThreadEvent(wxEVT_THREAD, wxEVT_gridUpdate));
	return (wxThread::ExitCode) 0;
}