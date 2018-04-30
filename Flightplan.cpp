//
// Created by Robbe Van de Velde on 24/04/18.
//

#include "Flightplan.h"

const string &Flightplan::getDestination() const {
    return destination;
}

void Flightplan::setDestination(const string &destination) {
    Flightplan::destination = destination;
}

unsigned int Flightplan::getDeparture() const {
    return departure;
}

void Flightplan::setDeparture(unsigned int departure) {
    Flightplan::departure = departure;
}

unsigned int Flightplan::getArrival() const {
    return arrival;
}

void Flightplan::setArrival(unsigned int arrival) {
    Flightplan::arrival = arrival;
}

unsigned int Flightplan::getInterval() const {
    return interval;
}

void Flightplan::setInterval(unsigned int interval) {
    Flightplan::interval = interval;
}

Flightplan::Flightplan(string &dest, unsigned int dep, unsigned int arr, unsigned int inter) {
    destination = dest, departure=dep, arrival= arr, interval=inter;

}
