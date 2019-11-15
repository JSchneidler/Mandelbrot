#include "RootWindow.hpp"
#include "App.hpp"
#include "Config.hpp"

const wxSize DEFAULT_SIZE = wxSize(DEFAULT_GRID_WIDTH + LEFT_PANEL_WIDTH, DEFAULT_GRID_WIDTH);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Mandelbrot v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, DEFAULT_SIZE, (wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER))
	, parent(new wxPanel(this, wxID_ANY))
	, left_panel(new LeftPanel(parent, DEFAULT_GRID_WIDTH))
	, canvas(new Canvas(parent, DEFAULT_GRID_WIDTH))
{
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 0, wxALL | wxEXPAND);
	hbox->Add(canvas, wxALL | wxEXPAND, wxALL | wxEXPAND);

	parent->SetSizer(hbox);
	this->Center();

	canvas->setRGBData(Mandelbrot::getRGBData(Mandelbrot::evaluate(
		DEFAULT_THRESHOLD,
		DEFAULT_MAX_ITERATIONS,
		DEFAULT_CENTER,
		DEFAULT_SCALE,
		DEFAULT_RESOLUTION
	)));
}

void RootWindow::setParameters(const double threshold, const uint64_t max_iterations, const std::complex<double> center, const double scale, const uint64_t resolution)
{
	const uint64_t grid_width = resolution * 2 + 1;

	SetSize(wxSize(grid_width + LEFT_PANEL_WIDTH, grid_width));
	canvas->setResolution(grid_width);
	canvas->setRGBData(Mandelbrot::getRGBData(Mandelbrot::evaluate(threshold, max_iterations, center, scale, resolution)));
}
