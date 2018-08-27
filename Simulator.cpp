//
// Created by thimoty on 4/30/18.
//

/** TODO: ZORGEN DAT ER GEEN PROPERLY INITIALISED ERROR IS ME EMERGENCY LANDING
 *
 */



#include "Simulator.h"

/*Constructor van simulator
 *@param vector<Runway *> &_runways, vector<Airplane *> &_airplanes, Airport *_airport
 *@return geen
 */
Simulator::Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport) :
        _runways(_runways), _airplanes(_airplanes), _airport(_airport)
{
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

/*init check
 *@param geen
 *@return bool
 */
bool Simulator::properlyInitialised()
{
    return _initcheck == this;
}

/*add de runways aan de airport
 *@param geen
 *@return geen
 */
void Simulator::addRunways()
{
    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling addRunways()");
    for(unsigned int x = 0; x < _runways.size(); x++){
        _airport->addRunway(_runways[x]);
    }
    ENSURE(_airport->getAmountRunways() == _runways.size(), "Runway size dont match");
}

/*Automatiseert de airplanes
 *@param geen
 *@return geen
 */
/** TODO: Checken of dat vliegtuig op juiste landingsbaan kan landen
 *
 * @param out
 */
void Simulator::Simulate(std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling Simulate()");
    while (!_airplanes.empty()) {
        doStep(out);
    }
}
/*
 * does extra step within function
 * @param ostream
 * @return none
 */
void Simulator::doStep(ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling Simulate()");
    for (unsigned int x = 0; x < _airplanes.size(); x++) {
        if (_airport->isAirplaneInWaitPoint(_airplanes[x])) {
            //end of a collision
            _airport->collisionSolverAirEnd(_airplanes[x], out);
        }
        else if(_airport->isAirplaneInRunwayWait(_airplanes[x])){
            //End of a collision
            _airport->_comm->ATC_Airplane_TakeOff_Permission_Granted_Runway_Comm(_airport->getController(),_airplanes[x], out);
            _airport->collissionSolverRunwayEnd(_airplanes[x]);
        }

        else if(_airplanes[x]->getFuel() == 0) {
            _airport->emergencySequence(_airplanes[x], out);
        }
            // end of emergencylanding
        else {
            //Start of landing procedure
            if(_airplanes[x]->getStatus() == Approaching || _airplanes[x]->getStatus() == FinalApproach) {
                _airport->landingSequence(_airplanes[x], out);
            }
                //end of landing procedure
                //Airplane should be "JustLanded" or "EmergencyLanding"

            else if (_airplanes[x]->getStatus() == JustLanded) {
                _airport->taxiToGate(_airplanes[x]);
                _airport->gateprotocol(_airplanes[x], 0);
                out << "--------------------------------------------------------------------------"<< endl;
            }
                //Begin gate procedure
            else if (_airplanes[x]->getStatus() == StandingAtGate) {
                _airport->completeGateProtocol(_airplanes[x], out);
            }
            else if (_airplanes[x]->getStatus() == Departure) {
                //Start of take off sequence
                _airport->takeOffSequence(_airplanes[x], out);
            }
            else if (_airplanes[x]->getStatus() == InTheAir || _airplanes[x]->getStatus() == EmergencyLanding || _airplanes[x]->getStatus() == EmergencyLandingOutside) {
                _airplanes.erase(_airplanes.begin() + x);
            }
        }
    }
}
