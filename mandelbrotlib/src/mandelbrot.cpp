#include "mandelbrot.hpp"
#include <iostream>
#include <cmath>

Color getColor(uint64_t iterations, uint64_t max_iterations)
{
	Color color{ 0, 0, 0 };
	if (iterations != max_iterations) color.g = 255 * ((double) iterations / max_iterations);
	return color;
}

uint64_t iterations(std::complex<double> point, double threshold, uint64_t max_iterations)
{
	uint64_t iterations = 0;

	std::complex<double> z{};
	while (iterations < max_iterations && std::abs(z) < threshold)
	{
		z = z * z + point;
		++iterations;
	}

	return iterations;
}

namespace Mandelbrot {
	t_mandelbrot_grid evaluate(const uint64_t resolution, const double threshold, const uint64_t max_iterations)
	{
		auto grid = t_mandelbrot_grid{ resolution, std::vector<uint64_t>(resolution, 0) };

		// Incremental difference between neighboring cells
		double increment = 1.0 / resolution;

		double imaginary, real;
		for (uint64_t i = 0; i < resolution; i++) // Rows
		{
			imaginary = (i * increment) - 0.5;
			for (uint64_t j = 0; j < resolution; j++) // Columns
			{
				real = (j * increment) - 1.5;
				grid.at(j).at(i) = iterations(std::complex<double>{ real, imaginary }, threshold, max_iterations);
			}
		}

		return grid;
	}

	std::vector<unsigned char> getRGBData(const t_mandelbrot_grid grid, const uint64_t max_iterations)
	{
		std::vector<unsigned char> rgb{};

		uint64_t grid_size = grid.size();
		for (uint64_t i = 0; i < grid_size; i++) // Rows
		{
			for (uint64_t j = 0; j < grid_size; j++) // Columns
			{
				Color color = getColor(grid.at(i).at(j), max_iterations);
				rgb.push_back(color.r);
				rgb.push_back(color.g);
				rgb.push_back(color.b);
			}
		}

		return rgb;
	}
}