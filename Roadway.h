#ifndef _ROADWAY_H__
#define _ROADWAY_H__
using namespace std;
#include "Lane.h"
#include "TrafficLight.h"

class Roadway {
	public:
		Lane *northbound;
		Lane *southbound;
		Lane *eastbound;
		Lane *westbound;

		Roadway(TrafficLight lightns, TrafficLight lightew, int length);
		bool isIntersection();
		void goStraight();
		void turnRight();
		bool safeToMove();
};

#endif
