#include "complex_number.hpp"

ComplexNumber::ComplexNumber(const double real, const double imaginary)
	: real(real)
	, imaginary(imaginary)
{}

const double ComplexNumber::getReal() const
{
	return real;
}

const double ComplexNumber::getImaginary() const
{
	return imaginary;
}

const double ComplexNumber::getAbsoluteValue() const
{
	return real;
}

ComplexNumber* ComplexNumber::operator+ (ComplexNumber const& other)
{
	return this;
}

ComplexNumber* ComplexNumber::operator* (ComplexNumber const& other)
{
	return this;
}
