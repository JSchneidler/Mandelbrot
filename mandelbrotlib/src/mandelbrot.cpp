#include "mandelbrot.hpp"
#include <iostream>

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
		t_mandelbrot_grid grid = t_mandelbrot_grid(resolution, std::vector<uint64_t>(resolution, 0));
		// Incremental difference between neighboring cells
		double increment = scale / resolution;

		// Get index of center cell
		uint64_t center = (resolution / 2) - 1;

		return grid;
	}
}