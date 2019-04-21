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

	// Create a vector to store the doubles read in from the input file
    vector<double> var;

	ifstream in; 
	in.open(argv[1]);
	
    // If input file format is incorrect, let the user know 
    if(in.bad()) {

        cout << "Bad Input File Format" << endl;
  	}
  	else {
            
        string line;
            
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
    }
    return 0;
}
