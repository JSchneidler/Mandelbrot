#include "complex_number.hpp"
#include <cmath>

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
	return sqrt(pow(real, 2) + pow(imaginary, 2));
}

ComplexNumber* ComplexNumber::add(ComplexNumber const& other)
{
	real += other.getReal();
	imaginary += other.getImaginary();

	return this;
}

ComplexNumber* ComplexNumber::subtract(ComplexNumber const& other)
{
	real -= other.getReal();
	imaginary -= other.getImaginary();

	return this;
}

ComplexNumber* ComplexNumber::multiply(ComplexNumber const& other)
{
	real *= other.getReal();
	imaginary *= other.getImaginary();

	return this;
}

ComplexNumber* ComplexNumber::operator+ (ComplexNumber const& other)
{
	return new ComplexNumber(this->getReal() + other.getReal(), this->getImaginary() + other.getImaginary());
}

ComplexNumber* ComplexNumber::operator- (ComplexNumber const& other)
{
	return new ComplexNumber(this->getReal() - other.getReal(), this->getImaginary() - other.getImaginary());
}

ComplexNumber* ComplexNumber::operator* (ComplexNumber const& other)
{
	return new ComplexNumber(this->getReal() * other.getReal(), this->getImaginary() * other.getImaginary());
}
