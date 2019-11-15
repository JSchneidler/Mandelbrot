#include "RootWindow.hpp"
#include "App.hpp"
#include "Config.hpp"

const wxSize DEFAULT_SIZE = wxSize(720 + LEFT_PANEL_WIDTH, 720);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Mandelbrot v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, DEFAULT_SIZE, (wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER))
	, parent(new wxPanel(this, wxID_ANY))
	, left_panel(new LeftPanel(parent, 720))
	, canvas(new Canvas(parent, 720))
{
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 0, wxALL | wxEXPAND);
	hbox->Add(canvas, wxALL | wxEXPAND, wxALL | wxEXPAND);

	parent->SetSizer(hbox);
	this->Center();

	canvas->setGrid(Mandelbrot::evaluate(
		DEFAULT_THRESHOLD,
		DEFAULT_MAX_ITERATIONS,
		DEFAULT_CENTER,
		DEFAULT_SCALE,
		DEFAULT_RESOLUTION
	));
}

void RootWindow::setParameters(const double threshold, const uint64_t max_iterations, const ComplexNumber center, const double scale, const uint64_t resolution)
{
	t_mandelbrot_grid grid = Mandelbrot::evaluate(threshold, max_iterations, center, scale, resolution);
	canvas->setGrid(grid);
}
