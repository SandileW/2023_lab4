#ifndef DASHEDLINESTYLE_H_
#define DASHEDLINESTYLE_H_

#include "LineStyle.h"

class DashedLineStyle : public LineStyle
{
public:
	DashedLineStyle(Colour colour, shared_ptr<Display> display_ptr):
		  LineStyle(colour,display_ptr), points_drawn(0)
		  {}
	virtual void plotLine(PointPair end_points) override;
private:
	const unsigned int POINT_PAIRS_PER_LINE = 50;
	int points_drawn;
	bool drawable();
};

#endif