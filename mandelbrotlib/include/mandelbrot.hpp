#pragma once

#include <complex>
#include <stdint.h>
#include <vector>

typedef std::vector<std::vector<uint64_t>> t_mandelbrot_grid;
typedef std::vector<unsigned char> t_rgb_grid;

namespace Mandelbrot
{
	uint64_t iterations(const std::complex<double> point, const double threshold, const uint64_t max_iterations);
	t_mandelbrot_grid evaluate(const uint64_t resolution, const double threshold, const uint64_t max_iterations);
	t_rgb_grid getRGBData(t_mandelbrot_grid grid);
}