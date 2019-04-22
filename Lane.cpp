#include "Lane.h"

Lane::Lane(TrafficLight light, int length)
{
	this->light = light;
	this->length = length;
	vector<Vehicle*> lane(length*2 +2, nullptr); 
}

bool Lane::isSpace()
{
	// Check if last section in lane has null pointer
	// If it does, then there is room for another vehicle in the lane
	// If the last section points to a vehicle, there is no room for
	// the new vehicle

	if (lane[length-1] == nullptr)
		return true;
	return false;
}

void Lane::addVehicle(Vehicle* vptr)
{
	lane[length-1] = vptr;
}

void Lane::removeVehicle()
{
	// We can only remove a vehicle when the only reference to it
	// is in the first section of the vector
	lane[0] = nullptr;
}


