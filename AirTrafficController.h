//
// Created by thimoty on 4/30/18.
//

#ifndef PSE_AIRTRAFFICCONTROLLER_H
#define PSE_AIRTRAFFICCONTROLLER_H

#include <iostream>
#include "DesignByContract.h"
class Airport;
class Airplane;

class AirTrafficController {
private:
    AirTrafficController* _initcheck;

    Airport* _airport;

    std::string _name;

public:
    AirTrafficController(Airport *_airport, const string &_name);

    bool properlyInitialised();

    bool landingprotocol(Airplane* airplane);

    bool takeoffprotocol(Airplane* airplane);

    bool emergencyprotocol(Airplane* airplane);
};


#endif //PSE_AIRTRAFFICCONTROLLER_H
