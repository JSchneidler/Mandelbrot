#pragma once

#include <wx/wx.h>
#include "LeftPanel.h"
#include "Canvas.h"
#include "Mandelbrot.h"

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

