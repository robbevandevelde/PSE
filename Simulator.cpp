//
// Created by thimoty on 4/30/18.
//

#include "Simulator.h"

/*
 *@param
 *@return
 */
Simulator::Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport) :
        _runways(_runways), _airplanes(_airplanes), _airport(_airport)
{
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

/*
 *@param
 *@return
 */
bool Simulator::properlyInitialised()
{
    return _initcheck == this;
}

/*
 *@param
 *@return
 */
void Simulator::addRunways()
{
    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling addRunways()");
    for(unsigned int x = 0; x < _runways.size(); x++){
        _airport->addRunway(_runways[x]);
    }
    ENSURE(_airport->getAmountRunways() == _runways.size(), "Runway size dont match");
}

/*
 *@param
 *@return
 */
void Simulator::Airplanes()
{
    while (!_airplanes.empty()) {
        for (unsigned int x = 0; x < _airplanes.size(); x++) {
            if (_airport->getWaitpoint1() == _airplanes[x] || _airport->getWaitpoint2() == _airplanes[x]) {
                if (_airport->isRunwayEmpty()) {
                    if (_airport->getWaitpoint1() == _airplanes[x]) {
                        _airplanes[x]->setStatus(Approaching);
                        _airplanes[x]->setHeight(5000);
                    } else if (_airport->getWaitpoint2() == _airplanes[x]) {
                        _airplanes[x]->setStatus(Approaching);
                        _airplanes[x]->setHeight(3000);
                    }
                }
            }
            else {
                if (_airplanes[x]->getStatus() == Approaching || _airplanes[x]->getStatus() == FinalApproach) {
                    if (_airplanes[x]->getHeight() == 10000) {
                        std::cout << _airplanes[x]->getCallsign() << " is approaching Zaventem at " << _airplanes[x]->getHeight()
                                  << std::endl;
                        _airport->getController()->landingprotocol(_airplanes[x]);
                        _airplanes[x]->descend();
                        std::cout << "--------------------------------------------------------------------------"<< std::endl;
                    }
                    else if (_airplanes[x]->getHeight() == 5000) {
                        if (_airport->getController()->landingprotocol(_airplanes[x])) {
                            std::cout << _airplanes[x]->getCallsign() << " you have permission to descend to 3000 ft"
                                      << std::endl;
                            _airplanes[x]->descend();
                            std::cout << "--------------------------------------------------------------------------"<< std::endl;
                        } else {
                            if (_airport->getWaitpoint1() == NULL) {
                                std::cout << "You have to wait for an empty runway, do a waiting pattern around 5000 ft "
                                          << std::endl;
                                _airport->setWaitpoint1(_airplanes[x]);
                            } else {
                                std::cout
                                        << "You have to wait for an empty runway, do a waiting pattern around 3000 ft "
                                        << std::endl;
                                _airplanes[x]->descend();
                                _airplanes[x]->descend();
                                _airport->setWaitpoint2(_airplanes[x]);
                            }
                        }
                    }
                    else if (_airplanes[x]->getHeight() == 3000) {
                        if (_airport->getController()->landingprotocol(_airplanes[x])) {
                            _airplanes[x]->setStatus(FinalApproach);
                            _airport->getRunways()[_airport->getFreeRunwaySpot()]->setUsedStatus();
                            _airplanes[x]->descend();
                            std::cout << "--------------------------------------------------------------------------"<< std::endl;
                        } else {
                            std::cout << "You have to wait for an empty runway, do a waiting pattern around 3000 ft "
                                      << std::endl;
                            _airport->setWaitpoint2(_airplanes[x]);
                            std::cout << "--------------------------------------------------------------------------"<< std::endl;
                        }
                    }
                    else if (_airplanes[x]->getHeight() == 0) {
                        _airport->addAirplaneToRunway(_airplanes[x]);
                        std::cout << "--------------------------------------------------------------------------"<< std::endl;
                    }
                    else if (_airplanes[x]->getHeight() < 10000) {
                        _airplanes[x]->descend();
                        std::cout << "--------------------------------------------------------------------------"<< std::endl;
                    }

                }
                else if (_airplanes[x]->getStatus() == JustLanded) {
                    _airport->TaxiToGate(_airplanes[x]);
                    _airport->gateprotocol(_airplanes[x], 0);
                    std::cout << "--------------------------------------------------------------------------"<< std::endl;

                }
                else if (_airplanes[x]->getStatus() == StandingAtGate) {
                    if(!_airplanes[x]->isFueled()){
                        _airport->gateprotocol(_airplanes[x],50);
                        std::cout << "--------------------------------------------------------------------------"<< std::endl;
                    } else {
                        _airport->gateprotocol(_airplanes[x], 50);
                        _airport->getController()->takeoffprotocol(_airplanes[x]);
                        _airport->TaxiToRunway(_airplanes[x]);
                        std::cout << "--------------------------------------------------------------------------"<< std::endl;
                    }
                }
                else if (_airplanes[x]->getStatus() == Departure) {
                    for (unsigned int i = 0; i < _airport->getRunways().size();i++) {
                        if(_airport->getRunways()[i]->getAirplane() == _airplanes[x]){
                            if(_airplanes[x]->getHeight() == 0){
                                std::cout << "This is " << _airplanes[x]->getCallsign() << " we are taking off " <<
                                          std::endl;
                                _airplanes[x]->ascend();
                                std::cout << "--------------------------------------------------------------------------"<< std::endl;
                            } else if(_airplanes[x]->getHeight() == 5000){
                                _airport->removeAirplaneOfRunway(_airplanes[x]);
                                _airplanes[x]->setStatus(InTheAir);
                                std::cout << _airplanes[x]->getCallsign() << " has left " << _airport->getName() <<
                                          std::endl;
                                std::cout << "--------------------------------------------------------------------------"<< std::endl;
                            }
                            else if(_airplanes[x]->getHeight() < 5000){
                                _airplanes[x]->ascend();
                                std::cout << "--------------------------------------------------------------------------"<< std::endl;
                            }

                        }
                    }
                }
                else if (_airplanes[x]->getStatus() == InTheAir) {
                    _airplanes.erase(_airplanes.begin() + x);
                }
            }
        }
    }
}
