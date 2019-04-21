#ifndef _TRAFFICLIGHT_H__
#define _TRAFFICLIGHT_H__

using namespace std;

enum class Color { GREEN, YELLOW, RED, DEFAULT };

class TrafficLight {

    public:

        // Default constructor 
        TrafficLight();
        // Creates an instance of TrafficLigth with pass by value arguments
        TrafficLight(int green, int yellow, int red, Color currentState);
        // Copy constructor
        TrafficLight(const TrafficLight& other);
        // Destructor 
        ~TrafficLight();

        Color getColor();
        Color updateState();
        int getTimeRemaining();

    protected:

        int gLength;
        int yLength;
        int rLength;
        Color currentState;
        //int remaining;        

};

#endif
