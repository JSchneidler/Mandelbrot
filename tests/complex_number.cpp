#include <gtest/gtest.h>
#include "complex_number.hpp"

TEST(ComplexNumberTest, addOverload)
{
    ComplexNumber c1 {2, 2.5};
    ComplexNumber c2 {2, 2.5};
    ComplexNumber* c3 = c1 + c2;

    ASSERT_EQ(c3->getReal(), 4.0);
    ASSERT_EQ(c3->getImaginary(), 5.0);
}

TEST(ComplexNumberTest, add)
{
    ComplexNumber c1 {3, 8.5};
    ComplexNumber c2 {4, 0.5};
    c1.add(c2);

    ASSERT_EQ(c1.getReal(), 7.0);
    ASSERT_EQ(c1.getImaginary(), 9.0);
}

TEST(ComplexNumberTest, subtractOverload)
{
    ComplexNumber c1 {12, 9.5};
    ComplexNumber c2 {4, 4.5};
    ComplexNumber* c3 = c1 - c2;

    ASSERT_EQ(c3->getReal(), 8.0);
    ASSERT_EQ(c3->getImaginary(), 5.0);
}

TEST(ComplexNumberTest, subtract)
{
    ComplexNumber c1 {3, 8.5};
    ComplexNumber c2 {4, 0.5};
    c1.subtract(c2);

    ASSERT_EQ(c1.getReal(), -1.0);
    ASSERT_EQ(c1.getImaginary(), 8.0);
}

TEST(ComplexNumberTest, multiplyOverload)
{
    ComplexNumber c1 {3, 10.5};
    ComplexNumber c2 {2, 0.5};
    ComplexNumber* c3 = c1 * c2;

    ASSERT_EQ(c3->getReal(), 6.0);
    ASSERT_EQ(c3->getImaginary(), 5.25);
}

TEST(ComplexNumberTest, multiply)
{
    ComplexNumber c1 {-8, 20.0};
    ComplexNumber c2 {3, 0.75};
    c1.multiply(c2);

    ASSERT_EQ(c1.getReal(), -24.0);
    ASSERT_EQ(c1.getImaginary(), 15.0);
}

TEST(ComplexNumberTest, absoluteValue)
{
    ComplexNumber c1 {-3, 12.3};

    ASSERT_FLOAT_EQ(c1.getAbsoluteValue(), 12.660568707605515);
}