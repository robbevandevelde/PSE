//
// Created by uauser on 4/23/18.
//

#include "Runway.h"
#include "Airplane.h"
#include "Taxiroute.h"

Runway::Runway(int _length, const std::string &_name, const std::string &_type, const std::string &_airport) : _length(
        _length), _name(_name), _type(_type), _airport(_airport) {

    _initcheck = this;
    _status = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(!_status, "Status must be false after initialising");
    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after initialising");
}


bool Runway::properlyInitialised() {
    return _initcheck == this;
}

void Runway::addAirplane(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling addAirplane()");
    REQUIRE(!_status, "Status must be false");
    REQUIRE(_airplane == NULL, "Airplane must point to a nullptr");

    _airplane = airplane;
    _status = true;

    _airplane->set_height(0);
    ENSURE(_airplane->get_height() == 0, "Added airplane's height isn't set to 0");

    ENSURE(_airplane->get_model() == airplane->get_model() && _airplane->get_number() == airplane->get_number() &&
           _airplane->get_callsign() == airplane->get_callsign(), "Added airplane doesn't match airplane");

    ENSURE(get_airplane() == airplane, "Airplane must point to the given airplane");
    ENSURE(_status,"Status must be true after adding an airplane");
}

void Runway::removeAirplane() {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling removeAirplane()");
    REQUIRE(_airplane != NULL, "Airplane must point to an airplane and not a nullptr");
    REQUIRE(_status, "Status must be true because the space is occupied");

    _airplane = NULL;
    _status = false;

    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after removing a plane");
    ENSURE(!_status,"Status must be false after removing a plane");
}
const std::string &Runway::get_name() {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling get_name()");
    return _name;
}

void Runway::set_name(const std::string &_name) {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling set_name()");
    Runway::_name = _name;
    ENSURE(get_name() == _name, "set_name() failure");
}

const std::string &Runway::get_type() {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling get_type()");
    return _type;
}

void Runway::set_type(const std::string &_type) {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling set_type()");
    Runway::_type = _type;
    ENSURE(get_type() == _type, "set_type() failure");
}

const std::string &Runway::get_airport() {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling get_airport()");
    return _airport;
}

void Runway::set_airport(const std::string &_airport) {
    Runway::_airport = _airport;
}

unsigned int Runway::get_length() {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling get_length()");
    return _length;
}

void Runway::set_length(unsigned int _length) {
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling set_length()");
    Runway::_length = _length;
    ENSURE(get_length() == _length, "set_length() failure");
}

Airplane *Runway::get_airplane(){
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling get_airplane()");
    return _airplane;
}

bool Runway::is_status(){
    REQUIRE(this->properlyInitialised(), "Runway wasn't initialised when calling get_status()");
    return _status;
}

const vector<Taxiroute *> &Runway::getTaxiRoute() const {
    return taxiRoute;
}

void Runway::setTaxiRoute(const vector<Taxiroute *> &taxiRoute) {
    Runway::taxiRoute = taxiRoute;
}

void Runway::pushbackTaxi(Taxiroute *taxiroute) {
    taxiRoute.push_back(taxiroute);

}


