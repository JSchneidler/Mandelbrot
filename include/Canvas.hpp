#pragma once

#include <wx/wx.h>
#include "mandelbrot.hpp"


class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint64_t resolution);

	void setRGBData(t_rgb_grid grid);
	void setResolution(const uint64_t resolution);
	void OnPaint(wxPaintEvent& event);

private:
	wxPanel* parent;
	wxBitmap bitmap;
	uint64_t resolution;
};

