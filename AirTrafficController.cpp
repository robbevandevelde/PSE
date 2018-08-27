//
// Created by thimoty on 4/30/18.
//

#include "AirTrafficController.h"
#include "Airplane.h"
#include "Airport.h"
#include "Runway.h"
#include "Communication.h"

/*Constructor van airtrafficcontroller
 *@param airport airport, string name
 *@return niks
 */
AirTrafficController::AirTrafficController(Airport *_airport, const std::string &_name) : _airport(_airport),
                                                                                          _name(_name)
{
    _initcheck = this;
    _comm = new Communication();
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
        _comm->ATC_Airplane_10000ft_Comm(this, airplane, out);
        return  true;
    }
    else if(airplane->getHeight() == 5000){
        unsigned int checker = 0;
        for(unsigned int x = 0; x<_airport->getRunways().size();x++){
            if(_airport->validRunwayForPlane(airplane,_airport->getRunways()[x])){
                if(!_airport->getRunways()[x]->isGoingToBeUsed()){
                    checker +=1;
                }
            }
        }
        if(checker == 0){
            return false;
        } else {
            return true;
        }
    }
    else if(airplane->getHeight() == 3000){
        unsigned int checker =0;
        for(unsigned int x = 0; x<_airport->getRunways().size();x++){
            if(_airport->validRunwayForPlane(airplane,_airport->getRunways()[x])){
                if(!_airport->getRunways()[x]->isGoingToBeUsed()){
                    checker +=1;
                }
            }
        }
        if(checker ==0){
            return false;
        } else {
            return true;
        }
    }
    else if(airplane->getStatus() == JustLanded){
        _comm->ATC_Airplane_After_Landing_Comm(this, airplane, out);
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
        _comm->ATC_Airplane_At_Gate_Comm(this, airplane, out);
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
            _comm->ATC_Airplane_More_Than_3000ft_Emergency(this, airplane, out);
            return true;
        } else if(airplane->getHeight() < 3000){
            _comm->ATC_Airplane_Less_Than_3000ft_Emergency(this, airplane,out);
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
/*
 * Asks for permition to go to runway
 * @param airplane ostream
 * @return none
 */
void AirTrafficController::takeOffClearance(Airplane* airplane, std::ostream& out) {
    REQUIRE(this->properlyInitialised(), "AirtrafficController wasn't properly initialised when calling takeOffClearance");

    _comm->ATC_Airplane_At_Gate_Comm(this, airplane, out);

    vector<Runway *> validrunways;

    bool checker = true;
    for (unsigned int j = 0; j < _airport->getRunways().size(); j++) {
        if (_airport->validRunwayForPlane(airplane, _airport->getRunways()[j])) {
            validrunways.push_back(_airport->getRunways()[j]);
        }
    }
    for (unsigned int l = 0; l < validrunways.size(); l++) {
        if (!validrunways[l]->isGoingToBeUsed()) {
            for (unsigned int k = 0; k < _airport->getRunways().size(); k++) {
                if (_airport->getRunways()[k] == validrunways[l]) {

                    _comm->ATC_Airplane_At_Gate_After_IFR_Comm(this, airplane, out);

                    _airport->taxiToRunway(airplane);
                    checker = false;
                    break;
                }
            }
            break;
        }
    }
    if (checker) {
        _comm->ATC_Airplane_Enter_Permission_Granted_Runway_Comm(this, airplane, out);

        _airport->collisionSolverRunwayStart(airplane, out);
    }
}

