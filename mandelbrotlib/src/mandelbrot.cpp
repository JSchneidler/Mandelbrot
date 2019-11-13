#include "mandelbrot.hpp"
#include <iostream>
#include <cmath>

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
		uint64_t center_cell = ceil(resolution / 2.0) - 1;

		std::cout << resolution << std::endl;
		std::cout << increment << std::endl;
		std::cout << center_cell << std::endl;

		double imaginary, real;
		for (uint64_t i = 0; i < resolution; i++)
		{
			imaginary = center.getImaginary() + ((center_cell - i) * increment);
			for (uint64_t j = 0; j < resolution; j++)
			{
				real = center.getReal() - ((center_cell - j) * increment);
				grid.at(i).at(j) = iterations(max_iterations, ComplexNumber(real, imaginary), threshold);
				printf("(%.2f, %.2fi) ", real, imaginary);
			}
			std::cout << std::endl;
		}

		return grid;
	}
}