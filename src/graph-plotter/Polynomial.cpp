#include "Polynomial.h"

float Polynomial::evaluate(float x) const
{
	auto y_val = 0.0f;

	auto raise_to = coefficients_.size() - 1;

	for(auto &i:coefficients_)
	{
		y_val += i*pow(x, raise_to);
		raise_to--;
	}

	return y_val;
}
