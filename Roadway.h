#ifndef _ROADWAY_H__
#define _ROADWAY_H__
using namespace std;
#include "Lane.h"
#include "TrafficLight.h"

class Roadway {
	private:
		Lane northbound;
		Lane southbound;
		Lane eastbound;
		Lane westbound;

	public:
		Roadway(TrafficLight ns, TrafficLight ew, int length);
		bool isIntersection();
		void goStraight();
		void turnRight();
		bool safeToMove();
};

#endif
