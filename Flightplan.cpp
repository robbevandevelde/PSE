//
// Created by Robbe Van de Velde on 24/04/18.
//

#include "Flightplan.h"

string &Flightplan::getDestination()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDestination()");

    return destination;
}

void Flightplan::setDestination(string &destination)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setDestination()");
    Flightplan::destination = destination;
    ENSURE(getDestination() == destination, "setDestination() failure");

}

unsigned int Flightplan::getDeparture()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDeparture()");
    return departure;
}

void Flightplan::setDeparture(unsigned int departure)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setDeparture()");
    Flightplan::departure = departure;
    ENSURE(getDeparture() == departure, "setDeparture() failure");
    exit(911);
}

unsigned int Flightplan::getArrival()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getArrival()");
    return arrival;
}

void Flightplan::setArrival(unsigned int arrival)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setArrival()");
    Flightplan::arrival = arrival;
    ENSURE(getArrival() == arrival, "setArrival() failure");

}

unsigned int Flightplan::getInterval()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getInterval()");
    return interval;
}

void Flightplan::setInterval(unsigned int interval)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setInterval()");
    Flightplan::interval = interval;
    ENSURE(getInterval() == interval, "setInterval() failure");

}

Flightplan::Flightplan(string &dest, unsigned int dep, unsigned int arr, unsigned int inter)
{
    destination = dest;
    departure=dep;
    arrival= arr;
    interval=inter;
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

bool Flightplan::properlyInitialised()
{
    return initCheck==this;
}
