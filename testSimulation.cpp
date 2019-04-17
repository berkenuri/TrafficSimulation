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

using namespace std;

int main(int argc, char *argv[]) {

	ifstream in; 
	in.open(argv[1]);
	
        if(in.bad()) {

            cout << "Bad Input File Format" << endl;
  	}
  	else {
            
            string line;
            
            while (getline(in, line)) {
             
                string name;
                int value;

                in >> value;                
                //in.ignore( numeric_limits<streamsize>::max(), '\n' );

                cout << value << endl;   
            }
        }
        return 0;
}
