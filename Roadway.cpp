#include "Roadway.h"
#include "Lane.h"
using namespace std;

Roadway::Roadway(TrafficLight lightns, TrafficLight lightew, int length)
{
	northbound = new Lane(&lightns, length);
	southbound = new Lane(&lightns, length);
	eastbound = new Lane(&lightew, length);
	westbound = new Lane(&lightew, length);
	this->length = length;
}

Roadway::~Roadway() 
{
}
/*
bool Roadway::isIntersection(Vehicle v)
{
	int size = v.getSize();
	switch(v.getDirection())
	{
		case Direction::north:
			if (v.getFrontYPos() >= length and v.getFrontYPos() <= length + 2 + size)
			{
				return true;
			}
		case Direction::south:
			if (v.getFrontYPos() >= length - size and v.getFrontYPos() <= length + 1)
			{
				return true;
			}
		case Direction::east:
			if (v.getFrontXPos() >= length and v.getFrontXPos() <= length + 2 + size)
			{
				return true;
			}
		case Direction::west:
			if(v.getFrontXPos() >= length - size and v.getFrontXPos() <= length + 1)
			{
				return true;
			}
	}
	return false;
}
*/
bool Roadway::isIntersection(Vehicle* v)
{
	switch (v->getDirection())
	{
		case Direction::north:
			if (v->getFrontYPos() == length)
			{
				return true;
			}
			break;
		case Direction::south:
			if (v->getFrontYPos() == length + 1)
			{
				return true;
			}
			break;
		case Direction::east:
			if (v->getFrontXPos() == length)
			{
				return true;
			}
			break;
		case Direction::west:
			if (v->getFrontXPos() == length + 1)
			{
				return true;
			}
			break;
	}
	return false;

}

