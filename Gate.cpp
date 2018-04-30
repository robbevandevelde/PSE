//
// Created by uauser on 4/23/18.
//

#include "Gate.h"

Gate::Gate(int _name) : _name(_name){
    _initcheck = this;
    _occupied = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_airplane == NULL, "Airplane must point to nullptr");
    ENSURE(!_occupied, "Occupied must be false");
}

bool Gate::properlyInitialised() {
    return _initcheck == this;
}

void Gate::addAirplane(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Gate wasn't initialised when calling addAirplane()");
    _airplane = airplane;
    ENSURE(_airplane->getCallsign() == airplane->getCallsign() && _airplane->getModel() == airplane->getModel()&&
                   _airplane->getNumber() == airplane->getNumber(), "addAirplane failure");
    _airplane->setStatus(StandingAtGate);
    ENSURE(_airplane->getStatus() == StandingAtGate, "addAirplane failure");
    _occupied = true;
    ENSURE(_occupied, "Occupied must be true");
}
void Gate::removeAirplane() {
    REQUIRE(this->properlyInitialised(),"Gate wasn't initialised when calling removeAirplane()");
    _airplane = NULL;
    ENSURE(_airplane == NULL, "Airplane must point to NULL");
    _occupied = false;
    ENSURE(!_occupied, "Occupied must be false");
}

bool Gate::is_occupied(){
    REQUIRE(this->properlyInitialised(), "Gate wasn't initialised when calling is_occupied()");
    return _occupied;
}

int Gate::get_name(){
    REQUIRE(this->properlyInitialised(), "Gate wasn't initialised when calling getName()");
    return _name;
}

Airplane *Gate::get_airplane(){
    REQUIRE(this->properlyInitialised(),"Gate wasn't initialised when calling get_airplane()");
    return _airplane;
}
