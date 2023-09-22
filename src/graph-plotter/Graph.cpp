#include "Graph.h"
#include "Points.h"

void Graph::plot(DataPoints data_points, LineStyle& line_plotter)
{
    display_->clear();

	data_points.transformToDisplayCoordinateSystem(display_->getWidth(), display_->getHeight());
	auto point_pairs = data_points.getAsPointPairs();
	for (const auto& point_pair : point_pairs)
	{
		line_plotter.plotLine(point_pair);
	}

	display_->update();
	display_->pause();
}
