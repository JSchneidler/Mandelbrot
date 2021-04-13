#pragma once

#include <complex>
#include <cstdint>
#include <vector>

typedef std::vector<std::vector<uint64_t>> t_mandelbrot_grid;

struct Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

namespace Mandelbrot
{
	t_mandelbrot_grid evaluate(const uint64_t resolution, const double threshold, const uint64_t max_iterations);
	std::vector<unsigned char> getRGBData(const t_mandelbrot_grid grid, const uint64_t max_iterations);
};