#pragma once

#include <stdint.h>

class Mandelbrot
{
public:
	Mandelbrot(const uint16_t resolution, const uint64_t c);

	const uint16_t getResolution() const;
	void setResolution(const uint16_t resolution);
	const uint64_t getC() const;
	void setC(const uint64_t c);
	void execute();

private:
	uint16_t resolution;
	uint64_t c;

	void reset();
};

