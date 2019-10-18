#pragma once

#include <wx/wx.h>

const uint16_t DEFAULT_RESOLUTION = 720;
const uint64_t DEFAULT_C = 10;

class App : public wxApp
{
public:
	virtual bool OnInit();
};
