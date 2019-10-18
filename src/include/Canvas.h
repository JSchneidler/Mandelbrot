#pragma once

#include <wx/wx.h>
#include "Mandelbrot.h"


class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint16_t resolution);

private:
	wxPanel* parent;
};

