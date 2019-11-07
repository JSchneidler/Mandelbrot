#include <gtest/gtest.h>
#include "complex_number.hpp"

TEST(ComplexNumberTest, addOverload)
{
    ComplexNumber c1 {2, 2.5};
    ComplexNumber c2 {2, 2.5};
    ComplexNumber c3 = c1 + c2;

    ASSERT_EQ(c3.getReal(), 4.0);
    ASSERT_EQ(c3.getImaginary(), 5.0);
}

TEST(ComplexNumberTest, addEquals)
{
    ComplexNumber c1 {3, 8.5};
    ComplexNumber c2 {4, 0.5};
    c1 += c2;

    ASSERT_EQ(c1.getReal(), 7.0);
    ASSERT_EQ(c1.getImaginary(), 9.0);
}

TEST(ComplexNumberTest, subtractOverload)
{
    ComplexNumber c1 {12, 9.5};
    ComplexNumber c2 {4, 4.5};
    ComplexNumber c3 = c1 - c2;

    ASSERT_EQ(c3.getReal(), 8.0);
    ASSERT_EQ(c3.getImaginary(), 5.0);
}

TEST(ComplexNumberTest, subtractEquals)
{
    ComplexNumber c1 {3, 8.5};
    ComplexNumber c2 {4, 0.5};
    c1 -= c2;

    ASSERT_EQ(c1.getReal(), -1.0);
    ASSERT_EQ(c1.getImaginary(), 8.0);
}

TEST(ComplexNumberTest, multiplyOverload)
{
    ComplexNumber c1 {3, 10};
    ComplexNumber c2 {8, 2};
    ComplexNumber c3 = c1 * c2;

    ASSERT_EQ(c3.getReal(), 4.0);
    ASSERT_EQ(c3.getImaginary(), 86.0);
}

TEST(ComplexNumberTest, multiplyEquals)
{
    ComplexNumber c1 {-8, 20};
    ComplexNumber c2 {3, 0};
    c1 *= c2;

    ASSERT_EQ(c1.getReal(), -24.0);
    ASSERT_EQ(c1.getImaginary(), 60.0);
}

TEST(ComplexNumberTest, absoluteValue)
{
    ComplexNumber c1 {-3, 12.3};

    ASSERT_FLOAT_EQ(c1.getAbsoluteValue(), 12.660568707605515);
}