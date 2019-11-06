#pragma once

#include <wx/wx.h>
#include "LeftPanel.hpp"
#include "Canvas.hpp"
#include "mandelbrot.hpp"

class RootWindow : public wxFrame
{
public:
	RootWindow();

	void setParameters(const uint16_t resolution, const uint64_t c);

private:
	Mandelbrot* mandelbrot;
	wxPanel* parent;
	LeftPanel* left_panel;
	Canvas* canvas;

	void redraw();
};

