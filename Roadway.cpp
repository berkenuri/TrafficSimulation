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

bool Roadway::isIntersection(Vehicle v)
{
	int size = v.getSize();
	switch(v.getDirection())
	{
		case Direction::north:
			if (v.getFrontYPos() >= length or v.getFrontYPos() <= length + 2 + size)
			{
				return true;
			}
		case Direction::south:
			if (v.getFrontYPos() >= length - size or v.getFrontYPos() <= length + 1)
			{
				return true;
			}
		case Direction::east:
			if (v.getFrontXPos() >= length or v.getFrontXPos() <= length + 2 + size)
			{
				return true;
			}
		case Direction::west:
			if(v.getFrontXPos() >= length - size or v.getFrontXPos() <= length + 1)
			{
				return true;
			}
	}
	return false;
}

