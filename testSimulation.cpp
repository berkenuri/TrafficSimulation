//#include "Vehicle.h"
//#include "TrafficLight.h"
//#include "Lane.h"
//#include "Roadway.h"
//#include "Tools.h"
//#include "ReadInput.h"

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {

    vector<double> var;

	ifstream in; 
	in.open(argv[1]);
	
    if(in.bad()) {

        cout << "Bad Input File Format" << endl;
  	}
  	else {
            
        string line;
            
        while (getline(in, line)) {
            string label;
            stringstream linestream(line);
            getline(linestream, label, ' ');
            cout << label << endl;
            double value;
            linestream >> value;

            cout << value << endl;   

            var.push_back(value);
        }
    }
    return 0;
}
