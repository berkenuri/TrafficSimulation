#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <vector>

using namespace std;

// listing of all vehicle types
enum class VehicleType {
    car,
    suv,
    truck,
    undefined
};

// listing of all possible directions vehicles can move
enum class Direction {
    north,
    south,
    east,
    west
};

class Vehicle {
       
    public:

        // default constructor
        Vehicle();
        
        // copy constructor
        Vehicle(const Vehicle& other);
       
        // constructor
        Vehicle(VehicleType vehicleName, 
                int frontX, int frontY, 
                int backX, int backY, 
                Direction moveDirection, bool rightTurn); 
        
        // deconstructor
        ~Vehicle();

        // gets the name of the vehicle
        VehicleType getName();
        
        // gets the front x and y coordinates of the vehicle
        int getFrontXPos();
        int getFrontYPos();
        vector<int> getFrontPos();
        
        // gets the back x and y coordiantes of the vehicle
        int getBackXPos();
        int getBackYPos(); 
        vector<int> getBackPos();

        // sets the front or back x-y coordinates of the vehicle
        void setFrontPos(int x, int y);
        void setBackPos(int x, int y);

        // returns the size of the vehicle
        int getSize();

        // makes the vehicle move one unit to the direction it is supposed to advance
        void go();

        // returns true if the vehicle is going to turn right in the intersection
        bool turnsRight();

        //returns the direction of the vehicle 
        Direction getDirection();

    private:

        // data fields of the vehicle
        VehicleType name;
        int size;
        int frontXPos;
        int frontYPos;
        int backXPos;
        int backYPos;
        Direction direction;
        bool turnRight;
        


};

#endif
