#include "Canvas.hpp"

Canvas::Canvas(wxPanel* parent, const uint16_t resolution)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(resolution, resolution), wxBORDER_SUNKEN)
	, parent(parent)
{
	this->Center();
}
