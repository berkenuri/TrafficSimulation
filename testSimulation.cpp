#include "Vehicle.h"
#include "TrafficLight.h"
#include "Lane.h"
#include "Roadway.h"
#include "Tools.h"
#include "ReadInput.h"

#include <iostream>
#include <fstream>
#include <map>

int main(int argc, char *argv[]) {

	ifstream in; 
	in.open(argv[1].c_str());
	if(in.bad()){
    	cout << "Bad Input File Format" << endl;
  	}
  	else{
  	}

	return 0;
}
