#include "DashedLineStyle.h"

void DashedLineStyle::plotLine(PointPair end_points)
{
	if(drawable())
	{
		auto display = getDisplay();
		display->drawLine(end_points, getColour());
	}

	points_drawn++;
}

bool DashedLineStyle::drawable()
{
	return points_drawn%(POINT_PAIRS_PER_LINE) < POINT_PAIRS_PER_LINE/2;
}
