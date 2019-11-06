#include <gtest/gtest.h>
#include "mandelbrot.hpp"
#include "complex_number.hpp"

TEST(MandelbrotTest, iterations)
{
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber(-1), 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber(-0.5), 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber(0), 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber(-1, 1), 2), 0);
    ASSERT_EQ(Mandelbrot::iterations(5, ComplexNumber(1), 2), 0);
}