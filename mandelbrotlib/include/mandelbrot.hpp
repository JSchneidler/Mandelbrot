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

class Mandelbrot
{
public:
	void evaluate(const uint64_t resolution, const double threshold, const uint64_t max_iterations);
	std::vector<unsigned char> getRGBData();
	t_mandelbrot_grid getGrid();

private:
	t_mandelbrot_grid grid;
	uint64_t max_iterations;

	uint64_t iterations(const std::complex<double> point, const double threshold, const uint64_t max_iterations);
	Color getColor(uint64_t iterations);
};