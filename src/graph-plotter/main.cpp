#include "Graph.h"
#include "Sinusoid.h"
#include "Sampler.h"
#include "Display.h"
#include "SolidLineStyle.h"
#include "Points.h"
#include "DashedLineStyle.h"
#include "DottedLineStyle.h"
#include "Polynomial.h"
#include "Exponential.h"
#include "Absolute.h"
#include <memory>


using std::shared_ptr;
using std::make_shared;

const float PI = 3.14159265359;
//the sampling points are too distant apart
int main()
{
	// setup Graph with Display
	const auto WIDTH = 800;
	const auto HEIGHT = 600;
	auto display = make_shared<Display>(WIDTH, HEIGHT);
	auto graph = Graph{display};

	// create sine and cosine functions
	auto amplitude = 1.0f;
	auto frequency = 1.0f;
	auto phase = 0.0f;
	auto sine_function = Sinusoid{amplitude, frequency, phase};
	auto cosine_function = Sinusoid{amplitude, frequency, phase + PI/2};

	// generate range and plot graphs
	auto range = Range{0, 6*PI};
	auto solid_red = SolidLineStyle{Colour::Red, display};
	graph.plot(generateDataPoints(sine_function, range), solid_red);

	auto solid_blue = SolidLineStyle{Colour::Blue, display};
	graph.plot(generateDataPoints(cosine_function, range), solid_blue);

	auto dashed_green = DashedLineStyle{Colour::Green, display};
	graph.plot(generateDataPoints(sine_function, range), dashed_green);

	auto dotted_green = DottedLineStyle{Colour::Green, display};
	graph.plot(generateDataPoints(sine_function, range), dotted_green);

	// create polynomial and expomential function
	auto polynomial = Polynomial{{1,2,1}};
	auto exponential = Exponential{1,1.5};

	// generate range and plot graphs
	range = Range{-3, 1.5};
	graph.plot(generateDataPoints(polynomial, range), solid_red);
	graph.plot(generateDataPoints(exponential, range), solid_blue);

	// generate an absolute plot
	polynomial = Polynomial{{1,-3,-4}};
	range = Range{-4,7};
	auto solid_green = SolidLineStyle{Colour::Green, display};
	auto absolute_polynomial = Absolute{&polynomial};
	graph.plot(generateDataPoints(absolute_polynomial,range),solid_green);

	return 0;
}







