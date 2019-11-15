#pragma once

#include <wx/wx.h>
#include "LeftPanel.hpp"
#include "Canvas.hpp"
#include "complex_number.hpp"

class RootWindow : public wxFrame
{
public:
	RootWindow();

	void setParameters(const double threshold, const uint64_t max_iterations, const ComplexNumber center, const double scale, const uint64_t resolution);

private:
	wxPanel* parent;
	LeftPanel* left_panel;
	Canvas* canvas;
};

