#include "Mandelbrot.h"

Mandelbrot::Mandelbrot(const uint16_t resolution, const uint64_t c)
	: resolution(resolution)
	, c(c)
{
	execute();
}

const uint16_t Mandelbrot::getResolution() const
{
	return resolution;
}

void Mandelbrot::setResolution(const uint16_t resolution)
{
	this->resolution = resolution;
}

const uint64_t Mandelbrot::getC() const
{
	return c;
}

void Mandelbrot::setC(const uint64_t c)
{
	this->c = c;
}

void Mandelbrot::execute()
{
	reset();
}

void Mandelbrot::reset()
{

}
