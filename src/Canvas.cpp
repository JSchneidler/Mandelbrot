#include "Canvas.hpp"
#include "App.hpp"

wxColor getColor(uint64_t iterations);

Canvas::Canvas(wxPanel* parent, const uint64_t resolution)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(resolution, resolution), wxBORDER_SUNKEN)
	, image()
{
	Center();
	Connect(wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
}

void Canvas::drawRGBData(std::vector<unsigned char> grid, uint64_t resolution)
{
	image = wxImage(resolution, resolution, grid.data(), true);
	Refresh();
}

void Canvas::OnPaint(wxPaintEvent&)
{
	wxPaintDC dc(this);
	wxGraphicsContext *gc = wxGraphicsContext::Create(dc);

	if (gc && image.IsOk())
	{
		wxGraphicsBitmap bitmap = gc->CreateBitmapFromImage(image);
		gc->DrawBitmap(bitmap, 0, 0, image.GetWidth(), image.GetHeight());
	}

	delete gc;
}
