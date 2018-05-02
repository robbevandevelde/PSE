//
// Created by Robbe Van de Velde on 24/04/18.
//

#ifndef PSE_FLIGHTPLAN_H
#define PSE_FLIGHTPLAN_H
#include "DesignByContract.h"

#include <string>
using namespace std;

class Flightplan {
private:
    std::string destination;
    unsigned int departure;
    unsigned int arrival;
    unsigned int interval;
    Flightplan* initCheck;

public:

    bool properlyInitialised();

    void setDestination(string &destination);
    void setDeparture(unsigned int departure);
    void setArrival(unsigned int arrival);
    void setInterval(unsigned int interval);

    unsigned int getArrival();
    unsigned int getInterval();
    unsigned int getDeparture();
    string &getDestination();


    Flightplan(std::string& dest, unsigned int dep, unsigned int arr, unsigned int inter);


};


#endif //PSE_FLIGHTPLAN_H
