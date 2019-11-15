#pragma once

#include <wx/wx.h>
#include "mandelbrot.hpp"


class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint64_t resolution);

	void setGrid(t_mandelbrot_grid grid);
	void OnPaint(wxPaintEvent& event);

private:
	wxPanel* parent;
	t_mandelbrot_grid grid;
};

