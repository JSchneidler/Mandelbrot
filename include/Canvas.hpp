#pragma once

#include <wx/wx.h>
#include <cstdint>
#include <vector>

class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint64_t resolution);

	void drawRGBData(std::vector<unsigned char> grid, uint64_t resolution);
	void OnPaint(wxPaintEvent& event);

private:
	wxImage image;
};

