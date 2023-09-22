#ifndef FUNCTION_H_
#define FUNCTION_H_

class Function
{
public:
	virtual ~Function() {};
	virtual float evaluate(float x) const = 0;
};

#endif