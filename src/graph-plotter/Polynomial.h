#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
#include <vector>
#include <cmath>
#include "Function.h"
using std::vector;

class Polynomial: public Function
{
public:
	Polynomial(vector<float> coefficients): coefficients_(coefficients) {};

	float evaluate(float x) const override;

private:
	vector<float> coefficients_;
};

#endif