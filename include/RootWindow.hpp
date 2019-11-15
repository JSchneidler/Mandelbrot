#pragma once

#include <wx/wx.h>
#include <complex>
#include "LeftPanel.hpp"
#include "Canvas.hpp"

class RootWindow : public wxFrame
{
public:
	RootWindow();

	void setParameters(const double threshold, const uint64_t max_iterations, const std::complex<double> center, const double scale, const uint64_t resolution);

private:
	wxPanel* parent;
	LeftPanel* left_panel;
	Canvas* canvas;
};

