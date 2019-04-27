#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include <vector>

using namespace std;

enum class VehicleType {
    car,
    suv,
    truck,
    undefined
};

enum class Direction {
    north,
    south,
    east,
    west
};

class Vehicle {
       
    public:

        Vehicle();
        
        Vehicle(const Vehicle& other);
       
        Vehicle(VehicleType vehicleName, 
                int frontX, int frontY, 
                int backX, int backY, 
                Direction moveDirection, bool rightTurn); 
        
        ~Vehicle();

        VehicleType getName();
        
        int getFrontXPos();
        int getFrontYPos();
        vector<int> getFrontPos();
        
        int getBackXPos();
        int getBackYPos(); 
        vector<int> getBackPos();

        void setFrontPos(int x, int y);
        void setBackPos(int x, int y);

        int getSize();

        void go();

        bool turnsRight();

    private:

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
