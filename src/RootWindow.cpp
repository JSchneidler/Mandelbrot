#include "RootWindow.hpp"
#include "App.hpp"
#include "Config.hpp"

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

	canvas->drawGrid(Mandelbrot::getRGBData(Mandelbrot::evaluate(
		DEFAULT_RESOLUTION,
		DEFAULT_THRESHOLD,
		DEFAULT_MAX_ITERATIONS
	)), DEFAULT_RESOLUTION);
}

void RootWindow::setParameters(const uint64_t resolution, const double threshold, const uint64_t max_iterations)
{
	t_rgb_grid grid = Mandelbrot::getRGBData(Mandelbrot::evaluate(resolution, threshold, max_iterations));

	SetSize(wxSize(resolution + LEFT_PANEL_WIDTH, resolution));
	canvas->drawGrid(grid, resolution);
}
