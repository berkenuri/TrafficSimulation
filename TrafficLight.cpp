#ifndef _TRAFFICLIGHT_H__
#define _TRAFFICLIGHTH__

TrafficLight::TrafficLight(){
	// Default constructor 
	gLength = -1; 
	yLength = -1;
	rLength = -1;
	currentState = DEFAULT;
}

TrafficLight::TrafficLight(int green, int yellow, int red, Color state){
	// Creates an instance of TrafficLigth with pass by value arguments
	gLength = green;
	yLength = yellow;
	rLength = red;
	currentState = state;
}

TrafficLight::TrafficLight(const TrafficLight& other){
	// Copy constructor
	gLength = other.gLength;
	yLength = other.yLength;
	rLength = other.rLength;
	currentState = other.currentState;
}

TrafficLight::~TrafficLight(){
	// Destructor
}







#endif
