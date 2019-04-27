#ifndef _ROADWAY_H__
#define _ROADWAY_H__
using namespace std;
#include "Lane.h"

class Roadway {
	private:
		Lane northbound;
		Lane southbound;
		Lane eastbound;
		Lane westbound;

	public:
		Roadway(TrafficLight lightns, TrafficLight lightew, int length);
		bool isIntersection();
		bool crossSafely();
		void goStraight();
		void turnRight();
		bool safeToMove();
};

#endif
