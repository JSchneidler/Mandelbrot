#pragma once

#include <wx/wx.h>
#include "mandelbrot.hpp"


class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint16_t resolution);

private:
	wxPanel* parent;
};

