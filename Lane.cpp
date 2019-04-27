#include "Lane.h"

/*
 *Constructor for the Lane class. Takes the length of the lane and the corresponding
 traffic light as parameters.
 */
Lane::Lane(TrafficLight light, int length)
{
	this->light = light;
	this->length = length;
	//vector<Vehicle*> lane(length*2 +2, nullptr);
	vector<Vehicle> lane; 
}

/*
 *This method determines if there is enough space in the lane to 
 add another vehicle. It does this by checking if the current last 
 vehicle in the lane is occupying the last spot in the lane. If it is,
 then there is no room for a new vehicle.
 */
bool Lane::isSpace()
{
	// Gets last vehicle in lane
	last_vehicle = *lane.back();
	dir = last_vehicle.getDirection();
	// Checks if last vehicle occupies the last position in the lane.
	// It does this by checking the coordinates of the last vehicle.
	switch(dir)
	{
		case Direction::north
		{
			if (last_vehicle.getBackYPos() <= 0)
			{
				return false;
			}
		}
		case Direction::south
		{
			if (last_vehicle.getBackYPos() >= length*2 + 2)
			{
				return false;
			}
		}
		case Direction::east
		{
			if (last_vehicle.getBackXPos() <= 0)
			{
				return false;
			}
		}
		case Direction::west
		{
			if (last_vehicle.getBackXPos() >= length*2 + 2)
			{
				return false;
			}
		}
	}
	return true;
}

/*
 *This method adds a vehicle to a lane if there is space. The vehicle is added to the 
 end of the lane.
 */
void Lane::addVehicle(Vehicle v)
{
	if (isSpace())
	{
		lane.push_back(v);
	}
}
/*
 *This method removes the first vehicle in the lane from the lane. This method will 
 be called when the vehicle reaches the end of the lane.
 */
void Lane::removeVehicle()
{
	// Remove first vehicle in list
	
	lane.erase(lane.begin());
}

/*
 *This method determines if a vehicle just before the intersection can make 
 it through the intersection safely, before the light turns red.
 The time necessary for the vehicle to travel completely through
 the intersection is different depending on whether the vehicle is
 turning right or going straight.
 */
bool Lane::crossSafely(Vehicle v, int t, int tyellow)
{
	int size = v.getSize();
	// Determines the number of time steps needed to 
	// make it through the intersection
	if (v.isRightTurn())
	{
		tn = size + 1;
	}
	else
	{
		tn = size + 3;
	}
	// If the light is yellow, the vehicle has until the 
	// light changes to go through the intersection
	if (light.getColor() == "Yellow")
	{
		if(tn < light.getRemaining(t))
		{
			return false;
		}
	}
	// If the light is green, the vehicle has until the light turns 
	// yellow plus the time that the light will be yellow
	else if (light.getColor() == "Green")
	{
		if (tn < light.getRemaining(t) + tyellow)
		{
			return false;
		}
	}
	return true;
}

