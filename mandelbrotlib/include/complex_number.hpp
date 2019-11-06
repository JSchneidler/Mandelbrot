#pragma once

class ComplexNumber
{
public:
	ComplexNumber(const double real, const double imaginary);

	const double getReal() const;
	const double getImaginary() const;
	const double getAbsoluteValue() const;

	ComplexNumber* operator+ (ComplexNumber const& other);
	ComplexNumber* operator* (ComplexNumber const& other);

private:
	const double real;
	const double imaginary;
};