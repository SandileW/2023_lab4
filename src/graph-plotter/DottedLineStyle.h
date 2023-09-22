#ifndef DOTTEDLINESTYLE_H_
#define DOTTEDLINESTYLE_H_

#include "LineStyle.h"

class DottedLineStyle: public LineStyle
{
public:
	DottedLineStyle(Colour colour, shared_ptr<Display> display_ptr):
		  LineStyle(colour,display_ptr), points_drawn(0)
		  {}
	virtual void plotLine(PointPair end_points) override;
private:
	const unsigned int POINT_PAIRS_PER_LINE = 10;
	int points_drawn;
	bool drawable();
};

#endif