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
    AirTrafficController(Airport *_airport, const std::string &_name);

    bool properlyInitialised();

    bool landingprotocol(Airplane* airplane, std::ostream& out = std::cout);

    bool takeoffprotocol(Airplane* airplane, std::ostream& out = std::cout);

    bool emergencyprotocol(Airplane* airplane, std::ostream& out = std::cout);

    Airport *getAirport();

    const std::string &getName();
};


#endif //PSE_AIRTRAFFICCONTROLLER_H
