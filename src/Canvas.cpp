#include "Canvas.hpp"

wxColor getColor(uint64_t iterations);

Canvas::Canvas(wxPanel* parent, const uint64_t resolution)
	: wxPanel(parent, -1, wxPoint(-1, -1), wxSize(resolution, resolution), wxBORDER_SUNKEN)
	, parent(parent)
	, grid(0, std::vector<uint64_t> (0))
{
	Center();
	Connect(wxEVT_PAINT, wxPaintEventHandler(Canvas::OnPaint));
}

void Canvas::setGrid(t_mandelbrot_grid grid)
{
	this->grid = grid;
	Refresh();
}

void Canvas::OnPaint(wxPaintEvent& event)
{
	wxPaintDC dc(this);

	dc.SetPen(wxPen(*wxBLACK));

	const uint64_t grid_size = grid.size();
	uint64_t iterations, last_iterations = 0;
	for (uint64_t i = 0; i < grid_size; i++)
	{
		for (uint64_t j = 0; j < grid_size; j++)
		{
			iterations = grid[i][j];
			if (iterations != last_iterations) dc.SetPen(wxPen(getColor(iterations)));
			last_iterations = iterations;

			dc.DrawPoint(wxPoint(j, i));
		}
	}
}

wxColor getColor(uint64_t iterations)
{
	switch (iterations)
	{
		case 1:
			return *wxRED;
		case 2:
			// Orange
			return wxColor(255, 165, 0);
		case 3:
			return *wxYELLOW;
		case 4:
			return *wxGREEN;
		default:
			return *wxBLACK;
	}
}
