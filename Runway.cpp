//
// Created by uauser on 4/23/18.
//

#include "Runway.h"
#include "Airplane.h"
#include "Taxiroute.h"

Runway::Runway(unsigned int _length, const std::string &_name, const std::string &_type, const std::string &_airport) : _length(
        _length), _name(_name), _type(_type), _airport(_airport)
{
    _initcheck = this;
    _status = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(!_status, "Status must be false after initialising");
    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after initialising");
}

bool Runway::properlyInitialised()
{
    return _initcheck == this;
}

void Runway::addAirplane(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling addAirplane()");
    REQUIRE(!_status, "Status must be false");
    REQUIRE(_airplane == NULL, "Airplane must point to a nullptr");

    _airplane = airplane;
    _status = true;

    _airplane->setHeight(0);
    ENSURE(_airplane->getHeight() == 0, "Added airplane's height isn't set to 0");

    ENSURE(_airplane->getModel() == airplane->getModel() && _airplane->getNumber() == airplane->getNumber() &&
                   _airplane->getCallsign() == airplane->getCallsign(), "Added airplane doesn't match airplane");

    ENSURE(getAirplane() == airplane, "Airplane must point to the given airplane");
    ENSURE(_status,"Status must be true after adding an airplane");
}

void Runway::removeAirplane()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling removeAirplane()");
    REQUIRE(_airplane != NULL, "Airplane must point to an airplane and not a nullptr");
    REQUIRE(_status, "Status must be true because the space is occupied");

    _airplane = NULL;
    _status = false;

    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after removing a plane");
    ENSURE(!_status,"Status must be false after removing a plane");
}

const std::string &Runway::getName()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getName()");
    return _name;
}

void Runway::setName(const std::string &_name)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setName()");
    Runway::_name = _name;
    ENSURE(getName() == _name, "setName() failure");
}

const std::string &Runway::getType()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getType()");
    return _type;
}

void Runway::setType(const std::string &_type)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setType()");
    Runway::_type = _type;
    ENSURE(getType() == _type, "setType() failure");
}

const std::string &Runway::getAirport()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirport()");
    return _airport;
}

void Runway::setAirport(const std::string &_airport)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirport()");
    Runway::_airport = _airport;
    ENSURE(getAirport() == _airport, "setAirport failure");
}

unsigned int Runway::getLength()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getLength()");
    return _length;
}

void Runway::setLength(unsigned int _length)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setLength()");
    Runway::_length = _length;
    ENSURE(getLength() == _length, "setLength() failure");
}

Airplane *Runway::getAirplane()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirplane()");
    return _airplane;
}

bool Runway::isStatus()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getStatus()");
    return _status;
}

const vector<Taxiroute *> &Runway::getTaxiRoute()
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling getTaxiRoute()");
    return _taxiRoute;
}

void Runway::setTaxiRoute(const vector<Taxiroute *> &taxiRoute)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling ()");
    Runway::_taxiRoute = taxiRoute;
    ENSURE(getTaxiRoute() == taxiRoute, "setTaxiRoute() failure");
}

void Runway::pushbackTaxi(Taxiroute *taxiroute)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling pushbackTaxi()");
    _taxiRoute.push_back(taxiroute);
    ENSURE(_taxiRoute[_taxiRoute.size() - 1] == taxiroute, "pushbackTaxi() failure");
}

void Runway::setAirplane(Airplane *_airplane)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirplane()");
    Runway::_airplane = _airplane;
    ENSURE(getAirplane() == _airplane, "setAirplane() failure");
}

void Runway::setStatus(bool _status)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setStatus()");
    Runway::_status = _status;
    ENSURE(isStatus() == _status, "setStatus() failure");
}


