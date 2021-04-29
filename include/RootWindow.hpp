#pragma once

#include <wx/wx.h>
#include <cstdint>
#include <complex>
#include "LeftPanel.hpp"
#include "Canvas.hpp"
#include "mandelbrot.hpp"

wxDECLARE_EVENT(wxEVT_gridUpdate, wxThreadEvent);

class RootWindow : public wxFrame, wxThreadHelper
{
public:
	RootWindow();
	~RootWindow() {};

	void setParameters(const uint64_t resolution, const double threshold, const uint64_t max_iterations);
	void onGridUpdate(wxThreadEvent&);
	void onClose(wxCloseEvent&);

protected:
	virtual wxThread::ExitCode Entry();

	t_mandelbrot_grid grid;
	wxCriticalSection gridCS;

	wxDECLARE_EVENT_TABLE();

private:
	wxPanel* parent;
	LeftPanel* left_panel;
	Canvas* canvas;

	uint64_t resolution;
	double threshold;
	uint64_t max_iterations;
};
