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
    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDestination()");
    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setDestination()");
    //    ENSURE(getDestination() == destination, "setDestination() failure");
    void setDestination(string &destination);

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setDeparture()");
    //    ENSURE(getDeparture() == departure, "setDeparture() failure");
    void setDeparture(unsigned int departure);

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setArrival()");
    //    ENSURE(getArrival() == arrival, "setArrival() failure");
    void setArrival(unsigned int arrival);

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setInterval()");
    //    ENSURE(getInterval() == interval, "setInterval() failure");
    void setInterval(unsigned int interval);

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getArrival()");
    unsigned int getArrival();

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getInterval()");
    unsigned int getInterval();

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDeparture()");
    unsigned int getDeparture();

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDestination()");
    string &getDestination();

    //    ENSURE(properlyInitialised(), "Constructor must end");
    Flightplan(std::string& dest, unsigned int dep, unsigned int arr, unsigned int inter);


};


#endif //PSE_FLIGHTPLAN_H
