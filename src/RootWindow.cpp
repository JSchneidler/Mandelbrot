#include "RootWindow.hpp"
#include "App.hpp"
#include "Config.hpp"

const wxSize DEFAULT_SIZE = wxSize(DEFAULT_RESOLUTION + LEFT_PANEL_WIDTH, DEFAULT_RESOLUTION);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Mandelbrot v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, DEFAULT_SIZE, (wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER))
	, parent(new wxPanel(this, wxID_ANY))
	, left_panel(new LeftPanel(parent, DEFAULT_RESOLUTION))
	, canvas(new Canvas(parent, DEFAULT_RESOLUTION))
	, mandelbrot()
{
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 0, wxALL | wxEXPAND);
	hbox->Add(canvas, wxALL | wxEXPAND, wxALL | wxEXPAND);

	parent->SetSizer(hbox);
	this->Center();

	mandelbrot.evaluate(DEFAULT_RESOLUTION,	DEFAULT_THRESHOLD, DEFAULT_MAX_ITERATIONS);
	canvas->drawRGBData(mandelbrot.getRGBData(), DEFAULT_RESOLUTION);
}

void RootWindow::setParameters(const uint64_t resolution, const double threshold, const uint64_t max_iterations)
{
	mandelbrot.evaluate(resolution, threshold, max_iterations);

	SetSize(wxSize(resolution + LEFT_PANEL_WIDTH, resolution));
	canvas->drawRGBData(mandelbrot.getRGBData(), resolution);
}
