#include "DottedLineStyle.h"

void DottedLineStyle::plotLine(PointPair end_points)
{
	if(drawable())
	{
		auto display = getDisplay();
		display->drawLine(end_points, getColour());
	}

	points_drawn++;
}

bool DottedLineStyle::drawable()
{
	return points_drawn%(POINT_PAIRS_PER_LINE) == 0;
}
