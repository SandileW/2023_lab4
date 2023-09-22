#include "Exponential.h"

float Exponential::evaluate(float x) const
{
	return A_*pow(exp(1), b_*x);
}

