//
// Created by thimoty on 4/30/18.
//

#include "Simulator.h"

Simulator::Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport)
        : _runways(_runways), _airplanes(_airplanes), _airport(_airport) {
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

bool Simulator::properlyInitialised() {
    return _initcheck == this;
}

void Simulator::addRunways() {
    for(unsigned int x = 0; x < _runways.size(); x++){
        _airport->addRunway(_runways[x]);
    }
}

void Simulator::Airplanes() {

}

