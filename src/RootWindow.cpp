#include "RootWindow.hpp"
#include "App.hpp"
#include "Config.hpp"

const wxSize DEFAULT_SIZE = wxSize(DEFAULT_RESOLUTION + 100, DEFAULT_RESOLUTION);

RootWindow::RootWindow()
	: wxFrame(NULL, wxID_ANY, wxString::Format(wxT("Mandelbrot v%d.%d"), VERSION_MAJOR, VERSION_MINOR), wxDefaultPosition, DEFAULT_SIZE, (wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER))
	, parent(new wxPanel(this, wxID_ANY))
	, mandelbrot(new Mandelbrot(DEFAULT_RESOLUTION, DEFAULT_C))
	, left_panel(new LeftPanel(parent, DEFAULT_RESOLUTION))
	, canvas(new Canvas(parent, DEFAULT_RESOLUTION))
{
	wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
	hbox->Add(left_panel, 0, wxALL | wxEXPAND);
	hbox->Add(canvas, wxALL | wxEXPAND, wxALL | wxEXPAND);

	parent->SetSizer(hbox);
	this->Center();
}

void RootWindow::setParameters(const uint16_t resolution, const uint64_t c)
{
	if (resolution == mandelbrot->getResolution() && c == mandelbrot->getC()) return;

	SetClientSize(wxSize(resolution + 100, resolution));

	mandelbrot->setResolution(resolution);
	mandelbrot->setC(c);
	mandelbrot->execute();
}
