//
// Created by thimoty on 4/30/18.
//

#ifndef PSE_SIMULATOR_H
#define PSE_SIMULATOR_H

#include <iostream>
#include "Runway.h"
#include "Airplane.h"
#include "Airport.h"
#include "DesignByContract.h"
class Simulator {
private:
    Simulator* _initcheck;
    std::vector<Runway*> _runways;
    std::vector<Airplane*> _airplanes;
    Airport* _airport;
public:
    Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport);

public:
    bool properlyInitialised();

    void addRunways();
    void Airplanes();
};


#endif //PSE_SIMULATOR_H
