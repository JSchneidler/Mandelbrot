#include <gtest/gtest.h>
#include "mandelbrot.hpp"
#include "complex_number.hpp"

TEST(MandelbrotTest, iterations)
{
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{-1}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{-0.5}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{0}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{1}, 2), 2);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{-1, 1}, 2), 3);
}

TEST(MandelbrotTest, execute)
{
	t_mandelbrot_grid grid = Mandelbrot::evaluate(2, 5, ComplexNumber(), 1, 5);

	// Check size of grid
	ASSERT_EQ(grid.size(), 5);
	ASSERT_EQ(grid.at(0).size(), 5);
}