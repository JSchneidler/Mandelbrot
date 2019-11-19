#pragma once

#include <wx/wx.h>
#include <complex>

const uint64_t DEFAULT_RESOLUTION = 480;
const double DEFAULT_THRESHOLD = 2;
const uint64_t DEFAULT_MAX_ITERATIONS = 25;

const uint16_t LEFT_PANEL_WIDTH = 150;

class App : public wxApp
{
public:
	virtual bool OnInit();
};
