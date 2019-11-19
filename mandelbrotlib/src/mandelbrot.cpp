#include "mandelbrot.hpp"
#include <iostream>
#include <cmath>


t_mandelbrot_grid Mandelbrot::getGrid()
{
	return grid;
}

void Mandelbrot::evaluate(uint64_t resolution, double threshold, uint64_t max_iterations)
{
	grid = t_mandelbrot_grid{ resolution, std::vector<uint64_t>(resolution, 0) };
	this->max_iterations = max_iterations;

	// Incremental difference between neighboring cells
	double increment = 1.0 / resolution;

	double imaginary, real;
	for (uint64_t i = 0; i < resolution; i++) // Rows
	{
		imaginary = (i * increment) - 0.5;
		for (uint64_t j = 0; j < resolution; j++) // Columns
		{
			real = (j * increment) - 1.5;
			grid[j][i] = iterations(std::complex<double>{ real, imaginary }, threshold, max_iterations);
		}
	}
}

std::vector<unsigned char> Mandelbrot::getRGBData()
{
	std::vector<unsigned char> rgb{};

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

uint64_t Mandelbrot::iterations(std::complex<double> point, double threshold, uint64_t max_iterations)
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

Color Mandelbrot::getColor(uint64_t iterations)
{
	Color color{ 0, 0, 0 };
	if (iterations != max_iterations) color.g = 255 * ((double) iterations / max_iterations);
	return color;
}