#pragma once

#include <wx/wx.h>
#include <complex>

const uint64_t DEFAULT_RESOLUTION = 480;
const uint64_t DEFAULT_GRID_WIDTH = DEFAULT_RESOLUTION * 2 + 1;
const std::complex<double> DEFAULT_CENTER { 5, 3 };
const double DEFAULT_SCALE = 5;
const double DEFAULT_THRESHOLD = 2;
const uint64_t DEFAULT_MAX_ITERATIONS = 5;

const uint16_t LEFT_PANEL_WIDTH = 150;

class App : public wxApp
{
public:
	virtual bool OnInit();
};
