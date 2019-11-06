#pragma once

class ComplexNumber
{
public:
	ComplexNumber(const double real, const double imaginary = 0);

	const double getReal() const;
	const double getImaginary() const;
	const double getAbsoluteValue() const;
	ComplexNumber* add(ComplexNumber const& other);
	ComplexNumber* subtract(ComplexNumber const& other);
	ComplexNumber* multiply(ComplexNumber const& other);

	ComplexNumber* operator+ (ComplexNumber const& other);
	ComplexNumber* operator- (ComplexNumber const& other);
	ComplexNumber* operator* (ComplexNumber const& other);

private:
	double real;
	double imaginary;
};