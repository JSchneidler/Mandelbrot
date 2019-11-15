#include "Canvas.hpp"
#include "App.hpp"

wxColor getColor(uint64_t iterations);

Canvas::Canvas(wxPanel* parent, const uint64_t resolution)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(resolution, resolution), wxBORDER_SUNKEN)
	, parent(parent)
	, bitmap(1, 1, true)
	, resolution(resolution)
{
	Center();
	Connect(wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
}

void Canvas::setResolution(const uint64_t resolution)
{
	this->resolution = resolution;
}

void Canvas::setRGBData(t_rgb_grid grid)
{
	wxImage image = wxImage(DEFAULT_GRID_WIDTH, DEFAULT_GRID_WIDTH, grid.data(), true);
	bitmap = wxBitmap(image);
	Refresh();
}

void Canvas::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	dc.DrawBitmap(bitmap, 0, 0, false);
}
