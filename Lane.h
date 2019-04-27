#ifndef _LANE_H__
#define _LANE_H__

#include "TrafficLight.h"
#include "Vehicle.h"

using namespace std;

class Lane {
	private:
		TrafficLight light;
		vector<Vehicle> lane;
		int length;
		bool isSpace();
	public:
		Lane(TrafficLight light, int length);
		~Lane();
		void addVehicle(Vehicle v);
		void removeVehicle();
		bool crossSafely(Vehicle v, int t, int tyellow);
		bool isSafeToMove(Vehicle v, int index);
};

#endif
