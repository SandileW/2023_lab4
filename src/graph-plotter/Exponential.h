#ifndef EXPONENTIAL_H_
#define EXPONENTIAL_H_
#include "Function.h"
#include <cmath>

class Exponential: public Function
{
public:
	Exponential(float A, float b): A_(A), b_(b) {};

	float evaluate(float x) const override;

private:
	float A_;
	float b_;
};

#endif