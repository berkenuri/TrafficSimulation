//#include "Vehicle.h"
//#include "TrafficLight.h"
//#include "Lane.h"
//#include "Roadway.h"
//#include "Tools.h"
//#include "ReadInput.h"

#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <array>

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

        // Assign values read from input to local variables 
        int maximum_simulated_time = var[0];
        int number_of_sections_before_intersection = var[1];
        int green_north_south = var[2];
        int yellow_north_south = var[3];
        int green_east_west = var[4];
        int yellow_east_west = var[5];
        int red_north_south = green_east_west + yellow_east_west;
        int red_east_west = green_north_south + yellow_north_south;
        int prob_new_vehicle_northbound = var[6];
        int prob_new_vehicle_southbound = var[7];
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
    }




    return 0;
}
