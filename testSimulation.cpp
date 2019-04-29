#include "Vehicle.h"
#include "TrafficLight.h"
#include "Roadway.h"
#include "Animator.h"
#include "VehicleBase.h"

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <array>
#include <random>

using namespace std;

int main(int argc, char *argv[]) {

 	ifstream in; 
	in.open(argv[1]);
	
    // If input file format is incorrect, let the user know 
    if(in.bad()) {

        cout << "Bad Input File Format" << endl;
  	}
  	else {
            
        string line;

		// Create a vector to store the doubles read in from the input file
        vector<double> var;
            
        // While there is another line of input to read
        while (getline(in, line)) {          
            string label;
            stringstream linestream(line);            
            // Read the label, which is the whitespace after the ':'
            getline(linestream, label, ' ');         
            double value;            
            // Read the double at the end of the input line
            linestream >> value;

            var.push_back(value);
        }

        // Assign values read from input to local variables within the scope of the else statement
        int maximum_simulated_time = var[0];
        int number_of_sections_before_intersection = var[1];
        int green_north_south = var[2];
        int yellow_north_south = var[3];
        int green_east_west = var[4];
        int yellow_east_west = var[5];
        // The north and south bound lanes will experience a red light when the east and west 
        // lanes have green or yellow signals
        int red_north_south = green_east_west + yellow_east_west;
        // The east and west bound lanes will experience a red light when the north and south 
        // lanes have green or yellow signals
        int red_east_west = green_north_south + yellow_north_south;
        double prob_new_vehicle_northbound = var[6];
        double prob_new_vehicle_southbound = var[7];
        double prob_new_vehicle_eastbound = var[8];
        double prob_new_vehicle_westbound = var[9];
        double proportion_of_cars = var[10];
        double proportion_of_SUVs = var[11];
        double proportion_of_trucks = 1 - (proportion_of_cars + proportion_of_SUVs);
        double prob_right_turn_cars = var[12];
        double prob_left_turn_cars = var[13];
        double prob_right_turn_SUVs = var[14];
        double prob_left_turn_SUVs = var[15];
        double prob_right_turn_trucks = var[16];
        double prob_left_turn_trucks = var[17];

        Animator::MAX_VEHICLE_COUNT = 9999;  // vehicles will be displayed with four digits
        Animator anim(number_of_sections_before_intersection);

        // t will represent current time in the simulation starting at time zero
        int t = 0;

        // Create four instances of TrafficLight for each lane/direction

        // North and south lanes will alwyas start with green 
        TrafficLight *northLight = new TrafficLight(green_north_south, yellow_north_south, red_north_south, Color::green, TrafficLightDirection::north_south);
        TrafficLight *southLight = new TrafficLight(*northLight);
        // East and west lanes will always start with red
        TrafficLight *eastLight = new TrafficLight(green_east_west, yellow_east_west, red_east_west, Color::red, TrafficLightDirection::east_west);
        TrafficLight *westLight = new TrafficLight(*eastLight);


        // Create an instance of Roadway that will internally create four instances of Lane

        Roadway *road = new Roadway(*northLight, *eastLight, number_of_sections_before_intersection);

        int initialSeed = 8675309;
        // Creating an instance of the Mersenne Twister 19937 Generator
        mt19937 generator (initialSeed); 
        // Floating point type between 0.0 and 1.1
        uniform_real_distribution<double> rand_double(0.0, 1.0);

        // This while loop will execute until time runs out (the current time is equal to the maximum simulated time)
	    // maximum_simulated_time
	    char dummy;
        while(t < maximum_simulated_time){

        	// Update the state of each TrafficLight every clock tick 
        	northLight->updateState(t);
        	southLight->updateState(t); 
        	eastLight->updateState(t);
        	westLight->updateState(t);

        	double newVehicle = rand_double(generator);

            int totalLaneLength = (number_of_sections_before_intersection * 2) + 2; // The total length of one lane will be the number of sections before the intersection multiplied two and added to two (the length of the intersection)

            bool turnRightCar = false;      // Boolean value indicating whether or not the car will turn right
            bool turnRightSUV = false;      // Boolean value indicating whether or not the SUV will turn right
            bool turnRightTruck = false;    // Boolean value indicating whether or not the truck will turn right
            if(newVehicle >= 0.0 && newVehicle < prob_right_turn_cars){
                turnRightCar = true;
            }
            if(newVehicle >= 0.0 && newVehicle < prob_right_turn_SUVs){
                turnRightSUV = true;
            }
            if(newVehicle >= 0.0 && newVehicle < prob_right_turn_trucks){
                turnRightTruck = true;
            }
        	
            Vehicle v;
        	if(newVehicle >=  0.0 && newVehicle < prob_new_vehicle_northbound){
        		// Create a new Vehicle northbound
                if(newVehicle >= 0.0 && newVehicle < proportion_of_cars){
                    // Create a car northbound where the size is hardcoded as 2
                    v = Vehicle(VehicleType::car, number_of_sections_before_intersection + 2, 1, number_of_sections_before_intersection + 2, 0, Direction::north, turnRightCar);
                }
                else if(newVehicle > proportion_of_cars && newVehicle < proportion_of_SUVs){
                    // Create a new SUV northbound where the size is hardcoded as 3
                    v = Vehicle(VehicleType::suv, number_of_sections_before_intersection + 2, 2, number_of_sections_before_intersection + 2, 0, Direction::north, turnRightSUV);
                }
                else if(newVehicle > proportion_of_SUVs && newVehicle < proportion_of_SUVs + proportion_of_trucks){
                    // Create a new truck northbound where the size is hardcoded as 4
                    v = Vehicle(VehicleType::truck, number_of_sections_before_intersection + 2, 3, number_of_sections_before_intersection + 2, 0, Direction::north, turnRightTruck);
                }
		v.setIDNumber(t);
                road->northbound->addVehicle(v); // Add the new Vehicle to the northbound lane. If there is no space, it will not be added
        	}

        	else if(newVehicle >= prob_new_vehicle_northbound && newVehicle < prob_new_vehicle_southbound){
        		// Create a new Vehicle southbound. 
               if(newVehicle >= 0.0 && newVehicle < proportion_of_cars){
                   // Create a car northbound where the size is hardcoded as 2
                    v = Vehicle(VehicleType::car, number_of_sections_before_intersection + 1, totalLaneLength - 2, number_of_sections_before_intersection + 1, totalLaneLength - 1, Direction::south, turnRightCar);
                }
                else if(newVehicle > proportion_of_cars && newVehicle < proportion_of_SUVs){
                    // Create a new SUV northbound where the size is hardcoded as 3
                    v = Vehicle(VehicleType::suv, number_of_sections_before_intersection + 1, totalLaneLength - 3, number_of_sections_before_intersection + 1, totalLaneLength - 1, Direction::south, turnRightSUV);
                }
                else if(newVehicle > proportion_of_SUVs && newVehicle < proportion_of_SUVs + proportion_of_trucks){
                    // Create a new truck northbound where the size is hardcoded as 4
                    v = Vehicle(VehicleType::truck, number_of_sections_before_intersection + 1, totalLaneLength - 4, number_of_sections_before_intersection + 1, totalLaneLength - 1, Direction::south, turnRightTruck);
                }
		v.setIDNumber(t);
                road->southbound->addVehicle(v); // Add the new Vehicle to the westbound lane. If there is no space, it will not be added

            }
        	else if(newVehicle >= prob_new_vehicle_southbound && newVehicle < prob_new_vehicle_eastbound){
        		// Create a new Vehicle eastbound
                if(newVehicle >= 0.0 && newVehicle < proportion_of_cars){
                    // Create a car eastbound where the size is hardcoded as 2
                    v = Vehicle(VehicleType::car, 1, number_of_sections_before_intersection + 1, 0, number_of_sections_before_intersection + 1, Direction::east, turnRightCar);
                }
                else if(newVehicle > proportion_of_cars && newVehicle < proportion_of_SUVs){
                    // Create a new SUV eastbound where the size is hardcoded as 3
                    v = Vehicle(VehicleType::suv, 2, number_of_sections_before_intersection + 1, 0, number_of_sections_before_intersection + 1, Direction::east, turnRightSUV);
                }
                else if(newVehicle > proportion_of_SUVs && newVehicle < proportion_of_SUVs + proportion_of_trucks){
                    // Create a new truck eastbound where the size is hardcoded as 4
                    v = Vehicle(VehicleType::truck, 3, number_of_sections_before_intersection + 1, 0, number_of_sections_before_intersection + 1, Direction::east, turnRightTruck);
                }
		v.setIDNumber(t);
                road->eastbound->addVehicle(v); // Add the new Vehicle to the eastbound lane. If there is no space, it will not be added
            }
        	else if(newVehicle >= prob_new_vehicle_eastbound && newVehicle < prob_new_vehicle_westbound){
        		// Create a new Vehicle westbound
                if(newVehicle >= 0.0 && newVehicle < proportion_of_cars){
                    // Create a car eastbound where the size is hardcoded as 2
                    v = Vehicle(VehicleType::car, totalLaneLength - 2, number_of_sections_before_intersection + 2, totalLaneLength - 1, number_of_sections_before_intersection + 2, Direction::west, turnRightCar);
                }
                else if(newVehicle > proportion_of_cars && newVehicle < proportion_of_SUVs){
                    // Create a new SUV eastbound where the size is hardcoded as 3
                    v = Vehicle(VehicleType::suv, totalLaneLength - 3, number_of_sections_before_intersection + 2, totalLaneLength - 1, number_of_sections_before_intersection + 2, Direction::west, turnRightSUV);
                }
                else if(newVehicle > proportion_of_SUVs && newVehicle < proportion_of_SUVs + proportion_of_trucks){
                    // Create a new truck eastbound where the size is hardcoded as 4
                    v = Vehicle(VehicleType::truck, totalLaneLength - 4, number_of_sections_before_intersection + 2, totalLaneLength - 1, number_of_sections_before_intersection + 2, Direction::west, turnRightTruck);
                }
		v.setIDNumber(t);
                road->westbound->addVehicle(v); // Add the new Vehicle to the westbound lane. If there is no space, it will not be added
            }

            // Iterate through each lane attempting to move the Vehicles 

            for(int i = 0; i < road->northbound->lane.size(); i++){

                if(road->northbound->isSafeToMove(road->northbound->lane[i], i, t, yellow_north_south)) {

                    if(road->isIntersection(road->northbound->lane[i])) {
                        // If the vehicle at index i of the northbound lane is in the intersection
                         if(road->northbound->lane[i].turnsRight() == true){
                             // Remove vehicle from current lane
			                Vehicle v = road->northbound->lane[i];
			                 road->northbound->removeVehicle(i);
			                // Turn right
			                 v.turnRight();
                             road->northbound->lane[i].turnRight();
			                 // Add vehicle to new lane
			                road->eastbound->insertVehicle(v);
                        }
                        else{
                            // Go straight
                            road->northbound->lane[i].go();
                        }
                    }
                    else{
                        road->northbound->lane[i].go();
                    }
                }
            }
	    
	    for(int i = 0; i < road->southbound->lane.size(); i++){						
                if(road->southbound->isSafeToMove(road->southbound->lane[i], i, t, yellow_north_south)){

                    if(road->isIntersection(road->southbound->lane[i])){
                        // If the vehicle at index i of the southbound lane is in the intersection
                        if(road->southbound->lane[i].turnsRight() == true){
			            Vehicle v = road->southbound->lane[i];
			            road->southbound->removeVehicle(i);
                        // Turn right
                        // road->southbound->lane[i].turnRight();
			            v.turnRight();
			            road->westbound->insertVehicle(v);
                        }
                        else{
                            // Go straight
                            road->southbound->lane[i].go();
                        }
                    }
                    else{
                        road->southbound->lane[i].go();
                    }
                }
            }

            for(int i = 0; i < road->eastbound->lane.size(); i++){ 

                if(road->eastbound->isSafeToMove(road->eastbound->lane[i], i, t, yellow_east_west)) {

                    if(road->isIntersection(road->eastbound->lane[i])){
                        // If the vehicle at index i of the eastbound lane is in the intersection
                        if(road->eastbound->lane[i].turnsRight() == true){
                            // Turn right
                            // road->eastbound->lane[i].turnRight();
			                Vehicle v = road->eastbound->lane[i];
			                road->eastbound->removeVehicle(i);
			                v.turnRight();
			                road->southbound->insertVehicle(v);
                        }
                        else{
                            // Go straight
                            road->eastbound->lane[i].go();
                        }
                    }
                    else{
                        road->eastbound->lane[i].go();
                    }
                }
            }

            for(int i = 0; i < road->westbound->lane.size(); i++){ 

                if(road->westbound->isSafeToMove(road->westbound->lane[i], i, t, yellow_east_west)){

                    if(road->isIntersection(road->westbound->lane[i])){
                        // If the vehicle at index i of the westbound lane is in the intersection
                        if(road->westbound->lane[i].turnsRight() == true){
                            // Turn right
                            // road->westbound->lane[i].turnRight();
			                Vehicle v = road->westbound->lane[i];
			                road->westbound->removeVehicle(i);
			                v.turnRight();
			                road->northbound->insertVehicle(v);
                        }
                        else{
                            // Go straight
                            road->westbound->lane[i].go();
                        }
                    }
                    else{
                        road->westbound->lane[i].go();
                    }
                }
            }

	    		
	    vector<VehicleBase*> nbound = road->northbound->pointerLane();
	    vector<VehicleBase*> sbound = road->southbound->pointerLane();
	    vector<VehicleBase*> ebound = road->eastbound->pointerLane();
	    vector<VehicleBase*> wbound = road->westbound->pointerLane();
	    anim.setVehiclesNorthbound(nbound);
	    anim.setVehiclesSouthbound(sbound);
	    anim.setVehiclesEastbound(ebound);
	    anim.setVehiclesWestbound(wbound);
	    cout << road->northbound->lane.size() << endl;
	    cout << road->southbound->lane.size() << endl;
	    cout << road->eastbound->lane.size() << endl;
	    cout << road->westbound->lane.size() << endl;
	    switch(northLight->getColor())
	    {
		    case Color::green:
			    anim.setLightNorthSouth(LightColor::green);
			    break;
		    case Color::yellow:
			    anim.setLightNorthSouth(LightColor::yellow);
			    break;
		    case Color::red:
			    anim.setLightNorthSouth(LightColor::red);
			    break;
	    }

	    switch(eastLight->getColor())
	    {
		    case Color::green:
			    anim.setLightEastWest(LightColor::green);
	            case Color::yellow:
			    anim.setLightEastWest(LightColor::yellow);
		    case Color::red:
			    anim.setLightEastWest(LightColor::red);
	    }

	    				
	    anim.draw(t);

	    cin.get(dummy);

	    cout << t << endl;

	    cout << "End of loop" << endl;

            t++;
        }      
    }

 return 0;
}
