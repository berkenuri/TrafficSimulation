#include "Vehicle.h"
#include "TrafficLight.h"
#include "Lane.h"
#include "Roadway.h"

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
            cout << label << endl;           
            double value;            
            // Read the double at the end of the input line
            linestream >> value;
            
            cout << value << endl;   

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
        double prob_right_turn_cars = var[12];
        double prob_left_turn_cars = var[13];
        double prob_right_turn_SUVs = var[14];
        double prob_left_turn_SUVs = var[15];
        double prob_right_turn_trucks = var[16];
        double prob_left_turn_trucks = var[17];

        // t will represent current time in the simulation starting at time zero
        int t = 0;

        // Create four instances of TrafficLight for each lane/direction

        // North and south lanes will alwyas start with green 
         TrafficLight *northLight = new TrafficLight(green_north_south, yellow_north_south, red_north_south, Color::green, TrafficLightDirection::north_south);
         TrafficLight *southLight = new TrafficLight(*northLight);
         // East and west lanes will always start with red
         TrafficLight *eastLight = new TrafficLight(green_east_west, yellow_east_west, red_east_west, Color::red, TrafficLightDirection::east_west);
         TrafficLight *westLight = new TrafficLight(*eastLight);

         // Create an instance of Roadway that will 

        int initialSeed = 8675309;
        // Creating an instance of the Mersenne Twister 19937 Generator
        mt19937 generator (initialSeed); 
        // Floating point type between 0.0 and 1.1
        uniform_real_distribution<double> rand_double(0.0, 1.0);

        // This while loop will execute until time runs out (the current time is equal to the maximum simulated time)
        while(t < maximum_simulated_time){

        	 // Update the state of each TrafficLight every clock tick 
        	 northLight->updateState(t);
        	 southLight->updateState(t); 
        	 eastLight->updateState(t);
        	 westLight->updateState(t);


        	double newVehicle = rand_double(generator);
        	
        	if(newVehicle >=  0.0 && newVehicle < prob_new_vehicle_northbound){
        		// Create a new Vehicle northbound
                Vehicle car = Vehicle(VehicleType::car, 10, 9, 10, 7, Direction::north, false);
        	}
        	else if(newVehicle >= prob_new_vehicle_northbound && newVehicle < prob_new_vehicle_southbound){
        		// Create a new Vehicle southbound
                Vehicle car = Vehicle(VehicleType::car, 10, 9, 10, 7, Direction::south, false);

        	}
        	else if(newVehicle >= prob_new_vehicle_southbound && newVehicle < prob_new_vehicle_eastbound){
        		// Create a new Vehicle eastbound
                Vehicle car = Vehicle(VehicleType::car, 10, 9, 10, 7, Direction::east, false);
        	}
        	else if(newVehicle >= prob_new_vehicle_eastbound && newVehicle < prob_new_vehicle_westbound){
        		// Create a new Vehicle westbound
                Vehicle car = Vehicle(VehicleType::car, 10, 9, 10, 7, Direction::west, false);
        	}

        	t++;
        }

        
    }
    return 0;
}
