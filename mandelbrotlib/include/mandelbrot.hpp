#pragma once

#include "complex_number.hpp"
#include <stdint.h>
#include <vector>

typedef std::vector<std::vector<uint64_t>> t_mandelbrot_grid;

namespace Mandelbrot
{
	uint64_t iterations(const uint64_t max_iterations, const ComplexNumber c, const double threshold);
	t_mandelbrot_grid evaluate(const double threshold, const uint64_t max_iterations, const ComplexNumber center, const double scale, const uint64_t resolution);
}