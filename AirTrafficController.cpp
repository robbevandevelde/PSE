//
// Created by thimoty on 4/30/18.
//

#include "AirTrafficController.h"
#include "Airplane.h"
#include "Airport.h"

AirTrafficController::AirTrafficController(Airport *_airport, const std::string &_name) : _airport(_airport),
                                                                                          _name(_name) {
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

bool AirTrafficController::properlyInitialised()
{
    return _initcheck == this;
}

bool AirTrafficController::landingprotocol(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling landingprotocol()");
    if(airplane->getHeight() == 10000){
        REQUIRE(airplane->getHeight() == 10000, "Airplane must be at 10000 ft");
        std::cout << airplane->getCallsign() << " is asking permission to land in " << _airport->get_name() << std::cout;
        std::cout << "This is" << _name << " from " << _airport->get_name() << " you have permission to descend to 5000 ft"
                                                                               << std::cout;
        return  true;
    }
    else if(airplane->getHeight() == 5000){
        REQUIRE(airplane->getHeight() == 5000, "Airplane must be at 5000 ft");
        if(_airport->isRunwayEmpty()){
            std::cout << airplane->getCallsign() << " you have permission to descend to 3000 ft" << std::endl;
            return true;
        }else {
            if(_airport->getWaitpoint1() == NULL){
                std::cout << "You have to wait for an empty runway, do a waiting pattern around 5000 ft "<< std::endl;
                _airport->setWaitpoint1(airplane);
            } else{
                std::cout << "You have to wait for an empty runway, do a waiting pattern around 3000 ft "<< std::endl;
                _airport->setWaitpoint2(airplane);
            }
            return false;
        }
    }
    else if(airplane->getStatus() == JustLanded){
        std::cout << airplane->getStatus() << "Proceed to an empty gate as soon as possible" << std::endl;
        return true;
    }
    return false;
}

bool AirTrafficController::takeoffprotocol(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling takeoffprotocol");
    if(airplane->getStatus() == StandingAtGate){
        std::cout << airplane->getCallsign() << " is asking permission to leave " << _airport->get_name() << std::endl;
        std::cout << "This is" << _name << " you have permission to leave the gate" << std::endl;
        return true;
    } else if(airplane->getStatus() == Departure) {
        std::cout << "You may leave the gate" << std::endl;
        return true;
    } else if(airplane->getStatus() == StandingAtRunway){
        if(_airport->isRunwayEmpty()){
            std::cout << "You have permission to leave " << _airport->get_name() << std::endl;
            return true;
        } else {
            std::cout << "You have to wait a few minutes for a clear runway" << std::endl;
            return false;
        }
    }
    return false;
}



bool AirTrafficController::emergencyprotocol(Airplane *airplane)
{
    if(airplane->getFuel() == 0){
        if(airplane->getHeight() >= 3000){
            std::cout << "We will make a free runway for you" << std::endl;
        } else if(airplane->getHeight() < 3000){
            std::cout << "We are contacting emergency lines, you will have to land outside of the airport" << std::endl;
        }
    }
    return false;
}


