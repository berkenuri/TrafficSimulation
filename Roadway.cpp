#include "Roadway.h"
#include "Lane.h"
using namespace std;

Roadway::Roadway(TrafficLight lightns, TrafficLight lightew, int length)
{
	northbound = Lane(lightns, length);
	southbound = Lane(lightns, length);
	eastbound = Lane(lightew, length);
	westbound = Lane(lightew, length);
}

