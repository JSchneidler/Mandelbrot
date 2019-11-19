#pragma once

#include <wx/wx.h>
#include <cstdint>
#include <complex>

const uint64_t DEFAULT_RESOLUTION = 720;
const double DEFAULT_THRESHOLD = 2;
const uint64_t DEFAULT_MAX_ITERATIONS = 50;

const uint16_t LEFT_PANEL_WIDTH = 150;

class App : public wxApp
{
public:
	virtual bool OnInit();
};
