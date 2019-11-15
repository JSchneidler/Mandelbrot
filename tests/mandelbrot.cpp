#include <gtest/gtest.h>
#include <complex>
#include "mandelbrot.hpp"

TEST(MandelbrotTest, iterations)
{
    ASSERT_EQ(Mandelbrot::iterations(5, std::complex<double>{-1}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, std::complex<double>{-0.5}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, std::complex<double>{0}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, std::complex<double>{1}, 2), 2);
    ASSERT_EQ(Mandelbrot::iterations(5, std::complex<double>{-1, 1}, 2), 3);
}

TEST(MandelbrotTest, evaluate)
{
    const uint64_t resolution = 5;
	t_mandelbrot_grid grid = Mandelbrot::evaluate(2, 5, std::complex<double>{5, 3}, 10, resolution);

	// Check size of grid
	ASSERT_EQ(grid.size(), resolution * 2 + 1);
	ASSERT_EQ(grid[0].size(), resolution * 2 + 1);

	// Check grid values
	t_mandelbrot_grid expected_grid{ resolution * 2 + 1, std::vector<uint64_t>(resolution * 2 + 1, 1) };
	grid[3][0] = 1;

	ASSERT_EQ(grid, expected_grid);
}