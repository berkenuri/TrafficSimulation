#ifndef _TRAFFICLIGHT_H__
#define _TRAFFICLIGHT_H__

using namespace std;

enum class Color { green, yellow, red };

class TrafficLight {

    public:

        TrafficLight();
        TrafficLight(const TrafficLight& other);
        ~TrafficLight();

        Color getColor();
        Color updateState();
        int getTimeRemaining();

    protected:

        int gLength;
        int yLength;
        int rLength;
        int remaining;        

};

#endif
