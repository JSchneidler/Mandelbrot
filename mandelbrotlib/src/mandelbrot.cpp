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
	uint64_t iterations(std::complex<double> point, double threshold, uint64_t max_iterations)
	{
		uint64_t iterations = 0;

		std::complex<double> z {};
		while (iterations < max_iterations && std::abs(z) < threshold)
		{
			z = z*z + point;
			++iterations;
		}

		return iterations;
	}

	t_mandelbrot_grid evaluate(uint64_t resolution, double threshold, uint64_t max_iterations)
	{
		t_mandelbrot_grid grid {resolution, std::vector<uint64_t>(resolution, 0)};

		// Incremental difference between neighboring cells
		double increment = 1.0 / resolution;

		double imaginary, real;
		for (uint64_t i = 0; i < resolution; i++) // Rows
		{
			imaginary = (i * increment) - 0.5;
			for (uint64_t j = 0; j < resolution; j++) // Columns
			{
				real = (j * increment) - 1.5;
				std::complex<double> point{ real, imaginary };
				grid[j][i] = iterations(point, threshold, max_iterations);
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
				Color color = getColor(grid[i][j]);
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
	/*
	unsigned char red = 255 * (iterations / 25);
	Color color{ red, 0, 0 };

	return color;
	*/

	Color red{ 255, 0, 0 };
	Color black{ 0, 0, 0 };
	if (iterations <= 24) return red;
	else return black;
}