//
// Created by thimoty on 4/30/18.
//

#ifndef PSE_AIRTRAFFICCONTROLLER_H
#define PSE_AIRTRAFFICCONTROLLER_H

#include <iostream>
#include "DesignByContract.h"
class Airport;
class Airplane;
class Runway;
class Communication;

class AirTrafficController {
private:
    AirTrafficController* _initcheck;

    Airport* _airport;

    Communication* _comm;

    std::string _name;

public:
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(getAirport() == _airport && getName() == _name, "AirTraffic controller failure");
    AirTrafficController(Airport *_airport, const std::string &_name);

    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling landingprotocol()");
    //    REQUIRE(airplane->getHeight() == 10000, "Airplane must be at 10000 ft");
    bool landingprotocol(Airplane* airplane, std::ostream& out = std::cout);

    //    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling takeoffprotocol");
    bool takeoffprotocol(Airplane* airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling emergencyprotocol");
    bool emergencyprotocol(Airplane* airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling getAirport()");
    Airport *getAirport();
    //    REQUIRE(this->properlyInitialised(), "AirtrafficController wasn't properly initialised when calling getName");
    const std::string &getName();

    void takeOffClearance(Airplane* airplane, std::ostream& out);

};


#endif //PSE_AIRTRAFFICCONTROLLER_H
