#include "mandelbrot.hpp"

namespace Mandelbrot
{
	uint64_t iterations(uint64_t max_iterations, ComplexNumber& c, double threshold)
	{
		uint64_t iterations = 0;

		ComplexNumber* z = new ComplexNumber(0, 0);
		while (iterations < max_iterations && z->getAbsoluteValue() < threshold)
		{
			z->multiply(*z)->add(c);
			++iterations;
		}

		if (iterations == max_iterations) return 0;
		return iterations;
	}

	uint64_t* evaluate(double threshold, uint64_t max_iterations, ComplexNumber& center, double scale, uint64_t resolution)
	{
		return 0;
	}
}