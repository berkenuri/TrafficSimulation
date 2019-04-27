#include "Roadway.h"
#include "Lane.h"
using namespace std;

Roadway::Roadway(TrafficLight lightns, TrafficLight lightew, int length)
{
	northbound = new Lane(lightns, length);
	southbound = new Lane(lightns, length);
	eastbound = new Lane(lightew, length);
	westbound = new Lane(lightew, length);
}

