//
// Created by thimoty on 4/30/18.
//

#include "AirTrafficController.h"
#include "Airplane.h"
#include "Airport.h"

/*Constructor van airtrafficcontroller
 *@param airport airport, string name
 *@return niks
 */
AirTrafficController::AirTrafficController(Airport *_airport, const std::string &_name) : _airport(_airport),
                                                                                          _name(_name) {
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(getAirport() == _airport && getName() == _name, "AirTraffic controller failure");
}

/*initialiser check
 *@param geen
 *@return bool
 */
bool AirTrafficController::properlyInitialised()
{
    return _initcheck == this;
}

/*Landing protocol van de vliegtuig
 *@param airplane airplane
 *@return bool
 */
bool AirTrafficController::landingprotocol(Airplane *airplane, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling landingprotocol()");
    if(airplane->getHeight() == 10000){
        REQUIRE(airplane->getHeight() == 10000, "Airplane must be at 10000 ft");
        out << airplane->getCallsign() << " is asking permission to land in " << _airport->getName() << std::endl;
        out << "This is " << _name << " from " << _airport->getName() << " you have permission to descend to 5000 ft"
                  << std::endl;
        return  true;
    }
    else if(airplane->getHeight() == 5000){
        if(_airport->isRunwayEmpty() && _airport->isRunwayNotUsed()){
            return true;
        } else{
            return false;
        }
    }else if(airplane->getHeight() == 3000){
        if(_airport->isRunwayEmpty() && _airport->isRunwayNotUsed()){
            return true;
        } else{
            return false;
        }
    }
    else if(airplane->getStatus() == JustLanded){
        out << airplane->getCallsign() << " proceed to an empty gate as soon as possible" << std::endl;
        return true;
    }
    return false;
}

/*takeoffprotocol voor de airplane
 *@param airplane airplane
 *@return bool
 */
bool AirTrafficController::takeoffprotocol(Airplane *airplane, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling takeoffprotocol");
    if(airplane->getStatus() == StandingAtGate){
        out << airplane->getCallsign() << " is asking permission to leave " << _airport->getName() << std::endl;
        out << "This is " << _name << " you have permission to leave the gate" << std::endl;
        return true;
    } else if(airplane->getStatus() == Departure) {
        out << "This is " <<_name << " you may proceed to an empty runway" << std::endl;
        return true;
    } else if(airplane->getStatus() == StandingAtRunway){
        if(_airport->isRunwayEmpty()){
            return true;
        } else {
            out << "You have to wait a few minutes for a clear runway" << std::endl;
            return false;
        }
    }
    return false;
}

/*Emergency protocollen voor de vliegtuig
 *@param airplane airplane
 *@return
 */
bool AirTrafficController::emergencyprotocol(Airplane *airplane, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling emergencyprotocol");
    if(airplane->getFuel() == 0){
        if(airplane->getHeight() >= 3000){
            out << "We will make a free runway for you" << std::endl;
            return true;
        } else if(airplane->getHeight() < 3000){
            out << "You will have to land outside of the airport, we are contacting an emergency line" << std::endl;
            return false;
        }
    }
    return false;
}

/*get de airport van de controller
 *@param geen
 *@return airport airport
 */
Airport *AirTrafficController::getAirport()

{
    REQUIRE(this->properlyInitialised(), "AirTrafficController wasn't properly initialised when calling getAirport()");
    return _airport;
}

/*get de name van de controller
 *@param geen
 *@return string name
 */
const string &AirTrafficController::getName()
{
    REQUIRE(this->properlyInitialised(), "AirtrafficController wasn't properly initialised when calling getName");
    return _name;
}


