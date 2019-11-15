#pragma once

#include <wx/wx.h>
#include "complex_number.hpp"

const uint64_t DEFAULT_RESOLUTION = 720;
const ComplexNumber DEFAULT_CENTER { 5, 3 };
const double DEFAULT_SCALE = 5;
const double DEFAULT_THRESHOLD = 2;
const uint64_t DEFAULT_MAX_ITERATIONS = 5;

const uint16_t LEFT_PANEL_WIDTH = 150;

class App : public wxApp
{
public:
	virtual bool OnInit();
};
