#pragma once

#include <wx/wx.h>
#include <cstdint>
#include <vector>

class Canvas : public wxPanel
{
public:
	Canvas(wxPanel* parent, const uint64_t resolution);

	void drawRGBData(const std::vector<unsigned char> grid, const uint64_t resolution);
	void OnPaint(wxPaintEvent& event);

private:
	wxImage image;
};

