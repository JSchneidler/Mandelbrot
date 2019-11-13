#include <gtest/gtest.h>
#include "mandelbrot.hpp"
#include "complex_number.hpp"

void printGrid (t_mandelbrot_grid grid);

TEST(MandelbrotTest, iterations)
{
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{-1}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{-0.5}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{0}, 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{1}, 2), 2);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber{-1, 1}, 2), 3);
}

TEST(MandelbrotTest, evaluate)
{
    const uint64_t resolution = 5;
	t_mandelbrot_grid grid = Mandelbrot::evaluate(2, 5, ComplexNumber{5, 3}, 10, resolution);

	// Check size of grid
	ASSERT_EQ(grid.size(), resolution);
	ASSERT_EQ(grid.at(0).size(), resolution);

    printGrid(grid);
	// Check grid values
	// ASSERT_EQ(grid.at(0), 5);
}

void printGrid (t_mandelbrot_grid grid)
{
    for (uint64_t i = 0; i < grid.size(); i++)
    {
        for (uint64_t j = 0; j < grid.at(i).size(); j++)
        {
            std::cout << grid.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}