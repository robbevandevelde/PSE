//
// Created by uauser on 4/23/18.
//

#include "Gate.h"

Gate::Gate(int _name) : _name(_name)
{
    _initcheck = this;
    _occupied = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_airplane == NULL, "Airplane must point to nullptr");
    ENSURE(!_occupied, "Occupied must be false");
}

bool Gate::properlyInitialised()
{
    return _initcheck == this;
}

void Gate::addAirplane(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling addAirplane()");
    _airplane = airplane;
    ENSURE(_airplane->getCallsign() == airplane->getCallsign() && _airplane->getModel() == airplane->getModel()&&
                   _airplane->getNumber() == airplane->getNumber(), "addAirplane failure");
    _occupied = true;
    ENSURE(_occupied, "Occupied must be true");
}
void Gate::removeAirplane()
{
    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling removeAirplane()");
    _airplane = NULL;
    ENSURE(_airplane == NULL, "Airplane must point to NULL");
    _occupied = false;
    ENSURE(!_occupied, "Occupied must be false");
}

bool Gate::isOccupied()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isOccupied()");
    return _occupied;
}

int Gate::getName()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling getName()");
    return _name;
}

Airplane *Gate::getAirplane()
{
    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling getAirplane()");
    return _airplane;
}
