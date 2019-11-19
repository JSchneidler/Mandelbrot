#pragma once

#include <wx/wx.h>
#include <cstdint>
#include <complex>
#include "LeftPanel.hpp"
#include "Canvas.hpp"
#include "mandelbrot.hpp"

class RootWindow : public wxFrame
{
public:
	RootWindow();

	void setParameters(const uint64_t resolution, const double threshold, const uint64_t max_iterations);

private:
	wxPanel* parent;
	LeftPanel* left_panel;
	Canvas* canvas;
	Mandelbrot mandelbrot;
};

