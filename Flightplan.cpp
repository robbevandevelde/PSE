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

int Flightplan::getDeparture() const {
    return departure;
}

void Flightplan::setDeparture(int departure) {
    Flightplan::departure = departure;
}

int Flightplan::getArrival() const {
    return arrival;
}

void Flightplan::setArrival(int arrival) {
    Flightplan::arrival = arrival;
}

int Flightplan::getInterval() const {
    return interval;
}

void Flightplan::setInterval(int interval) {
    Flightplan::interval = interval;
}

Flightplan::Flightplan() {

}
