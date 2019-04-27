#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"

// default constructor
Vehicle::Vehicle() {}

// deconstructor
Vehicle::~Vehicle() {}

// copy constructor
Vehicle::Vehicle(const Vehicle& other) {

    name = other.name;
    size = other.size;
    frontXPos = other.frontXPos;
    frontYPos = other.frontYPos;
    backXPos = other.backXPos;
    backYPos = other.backYPos;
    direction = other.direction;
    turnRight = other.turnRight;
}

// constructor
Vehicle::Vehicle(VehicleType vehicleName, 
                int frontX, int frontY, 
                int backX, int backY, 
                Direction moveDirection, bool rightTurn) {

    name = vehicleName;

    // sets the size of the vehicle depending on its type
    if (vehicleName == VehicleType::car) 
        size = 2;
    else if (vehicleName == VehicleType::suv)
        size = 3;
    else if (vehicleName == VehicleType::truck)
        size = 4;
    else
        size = 0;

    frontXPos = frontX;
    frontYPos = frontY;
    backXPos = backX;
    backYPos = backY;
    direction = moveDirection;
    turnRight = rightTurn;
}

// returns the name of the vehicle
VehicleType Vehicle::getName() {

    return name;
}

// returns the front x coordinate of the vehicle
int Vehicle::getFrontXPos() {

    return frontXPos;
}

// returns the front y coordinate of the vehicle
int Vehicle::getFrontYPos() {

    return frontYPos;
}

// returns the front x and y coordinates of the vehicle
vector<int> Vehicle::getFrontPos() {

    vector<int> frontCoordinates;

    frontCoordinates.push_back(frontXPos);
    frontCoordinates.push_back(frontYPos);

    return frontCoordinates;
}

// returns the back x coordinate of the vehicle
int Vehicle::getBackXPos() {

    return backXPos;
}

// returns the back y coordinates of the vehicle
int Vehicle::getBackYPos() {

    return backYPos;
}

// gets the back x and y coordinates of the vehicle
vector<int> Vehicle::getBackPos() {

    vector<int> backCoordinates;

    backCoordinates.push_back(backXPos);
    backCoordinates.push_back(backYPos);

    return backCoordinates;

}

// sets the front x-y coordinates of the vehicle
void Vehicle::setFrontPos(int x, int y) {

    frontXPos = x;
    frontYPos = y;
}
   
// sets the back x-y coordinates of the vehicle
void Vehicle::setBackPos(int x, int y) {

    backXPos = x;
    backYPos = y;
}

// returns the size of the vehicle
int Vehicle::getSize() {

    return size;
}

// returns true if the vehicle is turning right, false otherwise
bool Vehicle::turnsRight() {

    return turnRight;
}
 
// moves the vehicle one unit to the direction it is supposed to advance
void Vehicle::go() {
    
    if (direction == Direction::north) {

        frontYPos += 1;
        backYPos += 1;
    }

    else if (direction == Direction::south) {

        frontYPos -= 1;
        backYPos -= 1;
    }

    else if (direction == Direction::west) {

        frontXPos -= 1;
        backXPos -= 1;
    }

    else {

        frontXPos += 1;
        backXPos += 1;
    }
}

// returns the direction of the vehicle 
Direction Vehicle::getDirection() {

    return direction;
}


#endif 
