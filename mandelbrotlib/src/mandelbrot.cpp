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

	uint64_t* evaluate(double threshold, uint64_t max_iterations, ComplexNumber center, double scale, uint64_t resolution)
	{
		return 0;
	}
}