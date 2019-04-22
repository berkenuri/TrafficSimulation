#include "TrafficLight.h"

TrafficLight::TrafficLight(){
	// Default constructor 
	gLength = -1; 
	yLength = -1;
	rLength = -1;
	currentState = Color::defaultColor;
	cycleTime = -1;
}

TrafficLight::TrafficLight(int green, int yellow, int red, Color state, Direction direct){
	// Creates an instance of TrafficLigth with pass by value arguments
	gLength = green;
	yLength = yellow;
	rLength = red;
	currentState = state;
	cycleTime = 2 * (green + yellow + red);
}

TrafficLight::TrafficLight(const TrafficLight& other){
	// Copy constructor
	gLength = other.gLength;
	yLength = other.yLength;
	rLength = other.rLength;
	currentState = other.currentState;
	myDirection = other.myDirection;
	cycleTime = other.cycleTime;
}

TrafficLight::~TrafficLight(){
	// Destructor
}

Color TrafficLight::getColor(){
	// Return the current color of the TrafficLight
	return currentState;
}

void TrafficLight::updateState(int time){
	// Update the state of the TrafficLight given the current time of the simulation
	int currentTime = time % cycleTime;
	int halfCycle = cycleTime / 2;

	switch(myDirection){
		case Direction::north_south:
			if(currentTime >= 0 && currentTime < gLength){
				currentState = Color::green;
			}
			else if(currentTime >= gLength && currentTime < halfCycle){
				currentState = Color::yellow;
			}
			else if(currentTime >= halfCycle && currentTime < cycleTime){
				currentState = Color::red;
			}
			break;
		case Direction::east_west: 
			if(currentTime >= halfCycle && currentTime < halfCycle + gLength){
				currentState = Color::green;
			}
			else if(currentTime >= halfCycle + gLength && currentTime < cycleTime){
				currentState = Color::yellow;
			}
			else if(currentTime >= 0 && currentTime < halfCycle){
				currentState = Color::red;
			}
				break;
		case Direction::defaultDirection:
		// Do nothing
			break;
	}
}

int TrafficLight::getTimeRemaining(int time){
	// Return the time remaining before the color changes given the current state of 
    // the TrafficLight and the current time of the simulation
	int currentTime = time % cycleTime;
	int halfCycle = cycleTime / 2; 

	switch(myDirection){
		case Direction::north_south:
			if(currentState == Color::green){
				return gLength - 1 - currentTime;
			}
			else if(currentState == Color::yellow){
				return halfCycle - 1 - currentTime;
			}
			else if(currentState == Color::red){
				return cycleTime - 1 - currentTime;
			}
		case Direction::east_west:
			if(currentState == Color::green){
				return halfCycle + gLength - 1 - currentTime;
			}
			else if(currentState == Color::yellow){
				return cycleTime - 1 - currentTime;
			}
			else if(currentState == Color::red){
				return halfCycle - 1 - currentTime;
			}
		case Direction::defaultDirection:
		// Do nothing
			break;
	}
}
