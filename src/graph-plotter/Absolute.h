#ifndef ABSOLUTE_H_
#define ABSOLUTE_H_
#include "Function.h"
#include <cmath>

class Absolute: public Function
{
public:
	Absolute(Function *function): function_(function) {};
	float evaluate(float x) const override {return fabsf(function_->evaluate(x));}
private:
	Function *function_;
};

#endif