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

ComplexNumber ComplexNumber::operator+ (ComplexNumber const other)
{
	return ComplexNumber(this->getReal() + other.getReal(), this->getImaginary() + other.getImaginary());
}

ComplexNumber ComplexNumber::operator+= (ComplexNumber const other)
{
	*this = *this + other;
}

ComplexNumber ComplexNumber::operator- (ComplexNumber const other)
{
	return ComplexNumber(this->getReal() - other.getReal(), this->getImaginary() - other.getImaginary());
}

ComplexNumber ComplexNumber::operator-= (ComplexNumber const other)
{
	*this = *this - other;
}

ComplexNumber ComplexNumber::operator* (ComplexNumber const other)
{
	// (x + yi) * (u + vi) = (xu - yv) + (xv + yu)i
	// See https://www2.clarku.edu/faculty/djoyce/complex/mult.html
	double xu = this->getReal() * other.getReal();
	double yv = this->getImaginary() * other.getImaginary();
	double xv = this->getReal() * other.getImaginary();
	double yu = this->getImaginary() * other.getReal();
	return ComplexNumber(xu - yv, xv + yu);
}

ComplexNumber ComplexNumber::operator*= (ComplexNumber const other)
{
	*this = *this * other;
}