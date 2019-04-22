#ifndef _LANE_H__
#define _LANE_H__
#include "TrafficLight.h"
#include "Vehicle.h"
using namespace std;
#include <vector>;

class Lane {
	private:
		TrafficLight light;
		vector<Vehicle> lane;
		int length;
	public:
		Lane(TrafficLight light, int length);
		void addVehicle();
		bool isSpace();
		void removeVehicle();

};

#endif
