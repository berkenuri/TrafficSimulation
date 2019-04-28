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
}

/*
 *This method determines if there is enough space in the lane to 
 add another vehicle. It does this by checking if the current last 
 vehicle in the lane is occupying the last spot in the lane. If it is,
 then there is no room for a new vehicle.
 */
bool Lane::isSpace(Vehicle v)
{
	int size = v.getSize();
	// Gets last vehicle in lane
	Vehicle last_vehicle = lane.back();

	// Checks if last vehicle occupies the last position in the lane.
	// It does this by checking the coordinates of the last vehicle.
	switch(last_vehicle.getDirection())
	{
		case Direction::north:
			if (last_vehicle.getBackYPos() < size)
			{
				return false;
			}
		case Direction::south:
			if (last_vehicle.getBackYPos() > length*2 + 1 - size)
			{
				return false;
			}
		case Direction::east:
			if (last_vehicle.getBackXPos() < size)
			{
				return false;
			}
		case Direction::west:
			if (last_vehicle.getBackXPos() >= length*2 + 1 - size)
			{
				return false;
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
	if (isSpace(v))
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
	int tn = 0;
	// Determines the number of time steps needed to 
	// make it through the intersection
	if (v.turnsRight())
	{
		tn = size + 1;
	}
	else
	{
		tn = size + 3;
	}
	// If the light is yellow, the vehicle has until the 
	// light changes to go through the intersection
	if (light.getColor() == Color::yellow)
	{
		if(tn < light.getTimeRemaining(t))
		{
			return false;
		}
	}
	// If the light is green, the vehicle has until the light turns 
	// yellow plus the time that the light will be yellow
	else if (light.getColor() == Color::green)
	{
		if (tn < light.getTimeRemaining(t) + tyellow)
		{
			return false;
		}
	}
	return true;
}

/*
 *This method determines if a vehicle can move. It checks if there is a space in front of the vehicle. 
 It also checks if the light is green or yellow.
 */
bool Lane::isSafeToMove(Vehicle v, int i)
{
	if (i == 0)
	{
		return true;
	}
	Vehicle previous_vehicle = lane[i-1];
	switch (previous_vehicle.getDirection())
	{
		case Direction::north:
			if (previous_vehicle.getBackYPos() - 1 == v.getFrontYPos())
			{
				return false;
			}
		case Direction::south:
			if (previous_vehicle.getBackYPos() + 1 == v.getFrontYPos())
			{
				return false;
			}
		case Direction::east:
			if (previous_vehicle.getBackXPos() - 1 == v.getFrontXPos())
			{
				return false;
			}
		case Direction:: west:
			if (previous_vehicle.getBackXPos() + 1 == v.getFrontXPos())
			{
				return false;
			}
	}
	return true;
}

