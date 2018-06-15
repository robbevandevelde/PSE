//
// Created by thimoty on 4/30/18.
//

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
        for (unsigned int x = 0; x < _airplanes.size(); x++) {
            if (_airport->getWaitpoint1() == _airplanes[x] || _airport->getWaitpoint2() == _airplanes[x]) {
                if (_airport->getController()->landingprotocol(_airplanes[x])) {
                    if (_airport->getWaitpoint1() == _airplanes[x]) {
                        _airport->removeWaitpoint1();
                        _airplanes[x]->setStatus(FinalApproach);
                        _airport->goingToGetUsedRunway();
                        _airplanes[x]->descend();
                    } else if (_airport->getWaitpoint2() == _airplanes[x]) {
                        _airport->removeWaitpoint2();
                        _airplanes[x]->setStatus(FinalApproach);
                        _airport->goingToGetUsedRunway();
                        _airplanes[x]->descend();
                    }
                }
            }
            else if(_airport->runwayWaitChecker(_airplanes[x])){
                if(_airport->isRunwayEmpty() && _airport->isRunwayNotUsed()){
                    _airplanes[x]->setStatus(Departure);
                    _airport->removeRunwayWait(_airplanes[x]);
                    _airport->taxiToRunway(_airplanes[x]);
                }
            }
            else {
                if (_airplanes[x]->getStatus() == Approaching || _airplanes[x]->getStatus() == FinalApproach) {
                    if (_airplanes[x]->getHeight() == 10000) {
                        out << _airplanes[x]->getCallsign() << " is approaching Zaventem at " << _airplanes[x]->getHeight()
                                  << std::endl;
                        _airport->getController()->landingprotocol(_airplanes[x]);
                        _airplanes[x]->descend();
                        out << "--------------------------------------------------------------------------"<< std::endl;
                    }
                        /**TODO: noodlanding verder afwerken!
                         *
                         */
                    else if(_airplanes[x]->getFuel() == 0) {
                        out << "This is " << _airplanes[x]->getCallsign()
                            << " we have almost no fuel and request an emergency landing" << std::endl;
                        if (_airport->getController()->emergencyprotocol(_airplanes[x])) {
                            _airplanes[x]->setStatus(Emergency);
                            if (_airport->isARunwayCompletelyClear()) {
                                _airport->goingToGetUsedRunway();
                                while (_airplanes[x]->getHeight() != 0) {
                                    if (_airplanes[x]->getHeight() == 3000) {
                                        _airplanes[x]->descend();
                                    }
                                    _airplanes[x]->descend();
                                }
                            }
                        } else {
                            while (_airplanes[x]->getHeight() != 0) {
                                _airplanes[x]->descend();
                            }
                            _airplanes[x]->setStatus(EmergencyLanding);
                        }
                    }
                    else if (_airplanes[x]->getHeight() == 5000) {
                        if (_airport->getController()->landingprotocol(_airplanes[x])) {
                            out << _airplanes[x]->getCallsign() << " you have permission to descend to 3000 ft."
                                      << std::endl;
                            _airplanes[x]->descend();
                            out << "--------------------------------------------------------------------------"<< std::endl;
                        } else {
                            if (_airport->getWaitpoint1() == NULL) {
                                out << "You have to wait for an empty runway, do a waiting pattern around 5000 ft. "
                                          << std::endl;
                                _airport->setWaitpoint1(_airplanes[x]);
                                _airplanes[x]->setStatus(Approaching);
                            } else {
                                out
                                        << "You have to wait for an empty runway, do a waiting pattern around 3000 ft. "
                                        << std::endl;
                                _airplanes[x]->descend();
                                _airplanes[x]->descend();
                                _airport->setWaitpoint2(_airplanes[x]);
                                _airplanes[x]->setStatus(FinalApproach);
                            }
                        }
                    }
                    else if (_airplanes[x]->getHeight() == 3000) {
                        if (_airport->getController()->landingprotocol(_airplanes[x])) {
                            _airplanes[x]->setStatus(FinalApproach);
                            _airport->goingToGetUsedRunway();
                            _airplanes[x]->descend();
                            out << "--------------------------------------------------------------------------"<< std::endl;
                        } else {
                            out << "You, " << _airplanes[x]->getCallsign() <<", have to wait for an empty runway, do a waiting pattern around 3000 ft.    e    "
                                      << std::endl;
                            _airport->setWaitpoint2(_airplanes[x]);
                            _airplanes[x]->setStatus(FinalApproach);
                            out << "--------------------------------------------------------------------------"<< std::endl;
                        }
                    }
                    else if (_airplanes[x]->getHeight() == 0) {
                        _airport->addAirplaneToRunway(_airplanes[x]);
                        out << "--------------------------------------------------------------------------"<< std::endl;
                    }
                    else if (_airplanes[x]->getHeight() < 10000) {
                        _airplanes[x]->descend();
                        out << "--------------------------------------------------------------------------"<< std::endl;
                    }

                }
                else if (_airplanes[x]->getStatus() == JustLanded) {
                    _airport->taxiToGate(_airplanes[x]);
                    _airport->gateprotocol(_airplanes[x], 0);
                    out << "--------------------------------------------------------------------------"<< std::endl;

                }
                else if (_airplanes[x]->getStatus() == StandingAtGate) {
                    if(!_airplanes[x]->isFueled()){
                        _airport->gateprotocol(_airplanes[x],50);
                        out << "--------------------------------------------------------------------------"<< std::endl;
                    } else {
                        _airport->gateprotocol(_airplanes[x], 50);
                        _airport->getController()->takeoffprotocol(_airplanes[x]);
                        if(_airport->isRunwayEmpty() && _airport->isRunwayNotUsed()){
                            _airport->taxiToRunway(_airplanes[x]);
                            out << "--------------------------------------------------------------------------"<< std::endl;
                        }
                        else {
                            out << "You, " << _airplanes[x]->getCallsign()<< " have to wait a few minutes for a clear runway" << std::endl;
                            _airport->addRunwayWait(_airplanes[x]);
                            _airplanes[x]->setStatus(WaitingAtRunway);
                            out << "--------------------------------------------------------------------------"<< std::endl;
                        }
                    }
                }
                else if (_airplanes[x]->getStatus() == Departure) {
                    for (unsigned int i = 0; i < _airport->getRunways().size();i++) {
                        if(_airport->getRunways()[i]->getAirplane() == _airplanes[x]){
                            if(_airplanes[x]->getHeight() == 0){
                                out << "This is " << _airplanes[x]->getCallsign() << " we are taking off " <<
                                          std::endl;
                                _airplanes[x]->ascend();
                                out << "--------------------------------------------------------------------------"<< std::endl;
                            } else if(_airplanes[x]->getHeight() == 5000){
                                _airport->removeAirplaneFromRunway(_airplanes[x]);
                                _airplanes[x]->setStatus(InTheAir);
                                out << _airplanes[x]->getCallsign() << " has left " << _airport->getName() <<
                                          std::endl;
                                out << "--------------------------------------------------------------------------"<< std::endl;
                            }
                            else if(_airplanes[x]->getHeight() < 5000){
                                _airplanes[x]->ascend();
                                out << "--------------------------------------------------------------------------"<< std::endl;
                            }

                        }
                    }
                }
                else if (_airplanes[x]->getStatus() == InTheAir || _airplanes[x]->getStatus() == EmergencyLanding) {
                    _airplanes.erase(_airplanes.begin() + x);
                }
            }
        }
    }
}
