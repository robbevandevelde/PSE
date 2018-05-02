//
// Created by thimoty on 4/30/18.
//

#include "Simulator.h"

Simulator::Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport)
        : _runways(_runways), _airplanes(_airplanes), _airport(_airport) {
    _initcheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

bool Simulator::properlyInitialised() {
    return _initcheck == this;
}

void Simulator::addRunways() {
    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling addRunways()");
    for(unsigned int x = 0; x < _runways.size(); x++){
        _airport->addRunway(_runways[x]);
    }
    ENSURE(_airport->get_amountRunways() == _runways.size(), "Runway size dont match");
}

void Simulator::Airplanes() {
    while(!_airplanes.empty()){
        for(unsigned int x = 0; x < _airplanes.size();x++){
            if(_airplanes[x]->getStatus() == Approaching){
                _airport->Landingprotocol(_airplanes[x]);
            }
            else if(_airplanes[x]->getStatus() == FinalApproach){
                _airport->addAirplaneToRunway(_airplanes[x]);

            }
            else if(_airplanes[x]->getStatus() == JustLanded){
                _airport->TaxiToGate(_airplanes[x]);
                _airport->gateprotocol(_airplanes[x],0);

            }
            else if(_airplanes[x]->getStatus() == StandingAtGate){
                _airport->gateprotocol(_airplanes[x],50);
                _airport->TaxiToRunway(_airplanes[x]);
            }
            else if(_airplanes[x]->getStatus() == Departure){
                _airport->TakeOffprotocol(_airplanes[x]);
            }
        }
    }
}

