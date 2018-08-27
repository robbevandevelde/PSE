//
// Created by Robbe Van de Velde on 24/04/18.
//

#include "Flightplan.h"
/*
 * returns destinatio
 * @param none
 * @return destination
 */
string &Flightplan::getDestination()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDestination()");

    return destination;
}
/*
 * sets destination
 * @param destination
 * @return none
 */
void Flightplan::setDestination(string &destination)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setDestination()");
    Flightplan::destination = destination;
    ENSURE(getDestination() == destination, "setDestination() failure");

}
/*
 * gets departure
 * @param none
 * @return int departure
 */
unsigned int Flightplan::getDeparture()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getDeparture()");
    return departure;
}
/*
 * set departure
 * @param departure int
 * @return none
 */
void Flightplan::setDeparture(unsigned int departure)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setDeparture()");
    Flightplan::departure = departure;
    ENSURE(getDeparture() == departure, "setDeparture() failure");
}
/*
 * return arrival
 * @param none
 * @return arrival int
 */
unsigned int Flightplan::getArrival()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getArrival()");
    return arrival;
}
/*
 * sets arrival
 * @param int arrival
 * @return none
 */
void Flightplan::setArrival(unsigned int arrival)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setArrival()");
    Flightplan::arrival = arrival;
    ENSURE(getArrival() == arrival, "setArrival() failure");

}
/*
 * returns interval
 * @param none
 * @return interval int
 */
unsigned int Flightplan::getInterval()
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling getInterval()");
    return interval;
}
/*
 * set interval
 * @param int interval
 * @return none
 */
void Flightplan::setInterval(unsigned int interval)
{
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling setInterval()");
    Flightplan::interval = interval;
    ENSURE(getInterval() == interval, "setInterval() failure");

}
/*
 * constructs flightplan
 * @param string destination, int dep, int arr, in inter
 * @returnnone
 */
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
