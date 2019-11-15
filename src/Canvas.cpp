#include "Canvas.hpp"

wxColor getColor(uint64_t iterations);

Canvas::Canvas(wxPanel* parent, const uint64_t resolution)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(resolution, resolution), wxBORDER_SUNKEN)
	, parent(parent)
	, bitmap(1, 1, true)
{
	Center();
	Connect(wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
}

void Canvas::setRGBData(t_rgb_grid grid)
{
	wxImage image = wxImage(720, 720, grid.data(), true);
	bitmap = wxBitmap(image);
	Refresh();
}

void Canvas::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);
	dc.DrawBitmap(bitmap, 0, 0, false);
}
