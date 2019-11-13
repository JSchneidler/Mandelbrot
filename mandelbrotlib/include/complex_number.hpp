#pragma once

class ComplexNumber
{
public:
	ComplexNumber(const double real = 0, const double imaginary = 0);

	const double getReal() const;
	const double getImaginary() const;
	const double getAbsoluteValue() const;

	ComplexNumber operator+ (ComplexNumber const other);
	ComplexNumber operator+= (ComplexNumber const other);
	ComplexNumber operator- (ComplexNumber const other);
	ComplexNumber operator-= (ComplexNumber const other);
	ComplexNumber operator* (ComplexNumber const other);
	ComplexNumber operator*= (ComplexNumber const other);

private:
	double real;
	double imaginary;
};