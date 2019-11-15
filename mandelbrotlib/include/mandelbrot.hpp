#pragma once

#include <complex>
#include <stdint.h>
#include <vector>

typedef std::vector<std::vector<uint64_t>> t_mandelbrot_grid;
typedef std::vector<unsigned char> t_rgb_grid;

namespace Mandelbrot
{
	uint64_t iterations(const uint64_t max_iterations, const std::complex<double> c, const double threshold);
	t_mandelbrot_grid evaluate(const double threshold, const uint64_t max_iterations, const std::complex<double> center, const double scale, const uint64_t resolution);
	t_rgb_grid getRGBData(t_mandelbrot_grid grid);
}