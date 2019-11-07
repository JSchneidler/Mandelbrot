#pragma once

#include <stdint.h>
#include "complex_number.hpp"

namespace Mandelbrot
{
	uint64_t iterations(const uint64_t max_iterations, const ComplexNumber c, const double threshold);
	uint64_t* evaluate(const double threshold, const uint64_t max_iterations, const ComplexNumber center, const double scale, const uint64_t resolution);
}