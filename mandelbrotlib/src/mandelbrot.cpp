#include "mandelbrot.hpp"
#include <iostream>
#include <cmath>

struct Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

Color getColor(uint64_t iterations);

namespace Mandelbrot
{
	uint64_t iterations(uint64_t max_iterations, ComplexNumber c, double threshold)
	{
		uint64_t iterations = 0;

		ComplexNumber z {0, 0};
		while (iterations < max_iterations && z.getAbsoluteValue() < threshold)
		{
			z *= z;
			z += c;
			++iterations;
		}

		if (iterations == max_iterations) return 0;
		return iterations;
	}

	t_mandelbrot_grid evaluate(double threshold, uint64_t max_iterations, ComplexNumber center, double scale, uint64_t resolution)
	{
		uint64_t grid_size = (resolution * 2) + 1;
		t_mandelbrot_grid grid {grid_size, std::vector<uint64_t>(grid_size, 0)};

		// Incremental difference between neighboring cells
		double increment = scale / resolution;

		double imaginary, real;
		for (uint64_t i = 0; i < grid_size; i++) // Rows
		{
			imaginary = center.getImaginary() + ((resolution - i) * increment);
			for (uint64_t j = 0; j < grid_size; j++) // Columns
			{
				real = center.getReal() - ((resolution - j) * increment);
				grid[i][j] = iterations(max_iterations, ComplexNumber(real, imaginary), threshold);
			}
		}

		return grid;
	}

	t_rgb_grid getRGBData(t_mandelbrot_grid grid)
	{
		t_rgb_grid rgb {};

		uint64_t grid_size = grid.size();
		for (uint64_t i = 0; i < grid_size; i++) // Rows
		{
			for (uint64_t j = 0; j < grid_size; j++) // Columns
			{
				Color color = getColor(grid[j][i]);
				rgb.push_back(color.r);
				rgb.push_back(color.g);
				rgb.push_back(color.b);
			}
		}

		return rgb;
	}
}

Color getColor(uint64_t iterations)
{
	Color color;

	switch (iterations)
	{
		case 1:
			color = Color{ 0, 0, 0 };
			break;
		case 2:
			color = Color{ 0, 255, 0 };
			break;
		case 3:
			color = Color{ 255, 255, 0 };
			break;
		case 4:
			color = Color{ 255, 165, 0 };
			break;
		default:
			color = Color{ 255, 0, 0 };
			break;
	}

	return color;
}