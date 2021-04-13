#include <gtest/gtest.h>
#include <vector>
#include "mandelbrot.hpp"

TEST(MandelbrotTest, evaluate)
{
    const uint64_t resolution = 5;
	Mandelbrot mandelbrot{};

	mandelbrot.evaluate(resolution, 2, 10);

	// Check grid values
	t_mandelbrot_grid expected_grid{ resolution, std::vector<uint64_t>(resolution, 0) };
	expected_grid[0] = {3, 5, 7, 7, 5};
	expected_grid[1] = {4, 7, 10, 10, 7};
	expected_grid[2] = {5, 10, 10, 10, 10};
	expected_grid[3] = {5, 10, 10, 10, 10};
	expected_grid[4] = {8, 10, 10, 10, 10};

	ASSERT_EQ(mandelbrot.getGrid(), expected_grid);
}

TEST(MandelbrotTest, getRGBData)
{
    const uint64_t resolution = 5;
	Mandelbrot mandelbrot{};

	mandelbrot.evaluate(resolution, 2, 10);

	// Check RGB values
	std::vector<unsigned char> expected_rgb_data{
		0, 76, 0, 0, 127, 0, 0, 178, 0, 0, 178, 0, 0, 127, 0,
		0, 102, 0, 0, 178, 0, 0, 0, 0, 0, 0, 0, 0, 178, 0,
		0, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	ASSERT_EQ(mandelbrot.getRGBData(), expected_rgb_data);
}