#pragma once

#include <wx/wx.h>
#include "mandelbrot.hpp"


class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint64_t resolution);

	void drawGrid(t_rgb_grid grid, uint64_t resolution);
	void OnPaint(wxPaintEvent& event);

private:
	wxPanel* parent;
	wxBitmap bitmap;
};

