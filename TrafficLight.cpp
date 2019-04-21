#ifndef _TRAFFICLIGHT_H__
#define _TRAFFICLIGHTH__

TrafficLight::TrafficLight(){
	// Default constructor 
	gLength = -1; 
	yLength = -1;
	rLength = -1;
	currentState = DEFAULT;
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
		case NORTH_SOUTH:
		if(currentTime >= 0 && currentTime < gLength){
			currentState = GREEN;
		}
		else if(currentTime >= gLength && currentTime < halfCycle){
			currentState = YELLOW;
		}
		else if(currentTime >= halfCycle && currentTime < cycleTime){
			currentState = RED;
		}
			break;
		case EAST_WEST: 
		if(currentTime >= halfCycle && currentTime < halfCycle + gLength){
			currentState = GREEN;
		}
		else if(currentTime >= halfCycle + gLength && currentTime < cycleTime){
			currentState = YELLOW;
		}
		else if(currentTime >= 0 && currentTime < halfCycle){
			currentState = RED;
		}
			break;
		case DEAFAULT:
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
		case NORTH_SOUTH:
		if(currentState == GREEN){
			return gLength - 1 - currentTime;
		}
		else if(currentState == YELLOW){
			return halfCycle - 1 - currentTime;
		}
		else if(currentState == RED){
			return cycleTime - 1 - currentTime;
		}
		case EAST_WEST:
		if(currentState == GREEN){
			return halfCycle + gLength - 1 - currentTime;
		}
		else if(currentState == YELLOW){
			return cycleTime - 1 - currentTime;
		}
		else if(currentState == RED){
			return halfCycle - 1 - currentTime;
		}
	}
}

#endif
