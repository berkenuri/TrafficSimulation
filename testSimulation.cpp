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
#include <array>

using namespace std;

int main(int argc, char *argv[]) {

	ifstream in; 
	in.open(argv[1]);
	
        if(in.bad()) {

            cout << "Bad Input File Format" << endl;
  	}
  	else {
            
            string line;
            array<int, 18> myInts;
            string temp;
            int j = 0;
            
            while (getline(in, line)) {

            	for(int i = 0; i < line.size(); i++) {
            		if(line[i].isdigit()) {
            			temp += line[i];
            		}
            	}

            	array[j] = atoi(temp);

            	j++;
         
                // string name;
                // int value;

                // in >> value;                
                // //in.ignore( numeric_limits<streamsize>::max(), '\n' );

                // cout << value << endl;   
            }
        }
        return 0;
}
