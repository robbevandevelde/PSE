//
// Created by uauser on 4/23/18.
//

#include "Airplane.h"
//#include "Flightplan.h"

/*Constructor
 *@param string number, string callsign, int passengers, string model, string status
 *@return niks constructor
 */
Airplane::Airplane(std::string number,std::string callsign, std::string model,
                   unsigned int status, unsigned int passengers, unsigned int fuel,
                   std::string type, std::string engine, std::string size, Flightplan* flightp) {

    _initcheck = this;
    _number = number;
    _callsign = callsign;
    _model = model;
    _status = status;
    _fuel = fuel;
    _passengers = passengers;
    _type = type;
    _size = size;
    _engine = engine;
    _flightplan = flightp;
    if(_status == Approaching){
        _height = 10000;
    }
    else{
        _height = 0;
    }

    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_height == 0 || _height == 10000, "Height must be either 0 or 10000");
}

/*Checkt of dat het goed geinitialised is
 *@param geen param
 *@return true als waar, false als niet waar
 */
bool Airplane::properlyInitialised() {
    return _initcheck == this;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
unsigned int Airplane::get_fuel(){
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling get_fuel()");
    return _fuel;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
void Airplane::set_fuel(unsigned int _fuel) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling set_fuel()");
    Airplane::_fuel = _fuel;
    ENSURE(get_fuel() == _fuel, "set_fuel() failure");
}

/*Get de passengers van de airplane
 *@param geen
 *@return int hoeveelheid passengers in de airplane
 */
unsigned int Airplane::get_passengers() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling get_passengers()");
    return _passengers;
}

/*Set de passengers van de airplane
 *@param string status
 *@return niks void functie
 */
void Airplane::set_passengers(unsigned int _passengers) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling set_passengers()");
    Airplane::_passengers = _passengers;
    ENSURE(get_passengers() == _passengers, "set_passengers() failure");
}

/*Get de number van de airplane
 *@param string number
 *@return string number van de airplane
 */
const std::string &Airplane::get_number() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling get_number()");
    return _number;
}

/*Set de number van de airplane
 *@param string number
 *@return niks void functie
 */
void Airplane::set_number(const std::string &_number) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling set_number()");
    Airplane::_number = _number;
    ENSURE(get_number() == _number, "set_number() failure");
}

/*Get de de callsign
 *@param geen
 *@return string callsign van de airplane
 */
const std::string &Airplane::get_callsign() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling getCallsign()");
    return _callsign;
}

/*Set de de callsign
 *@param string callsign
 *@return niks void functie
 */
void Airplane::set_callsign(const std::string &_callsign) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling setCallsign()");
    Airplane::_callsign = _callsign;
    ENSURE(get_callsign() == _callsign, "setCallsign() failure");
}

/*Get de model van de airplane
 *@param geen
 *@return string model van de airplane
 */
const std::string &Airplane::get_model() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling get_model()");
    return _model;
}

/*Set de model van de airplane
 *@param string model
 *@return niks void functie
 */
void Airplane::set_model(const std::string &_model) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling set_model()");
    Airplane::_model = _model;
    ENSURE(get_model() == _model, "set_model() failure");
}

/*Get de status van de airplane
 *@param geen
 *@return int status van de airplane (enumerator)
 */
unsigned int Airplane::get_status() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling get_status()");
    return _status;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
void Airplane::set_status(unsigned int _status) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling set_status()");
    Airplane::_status = _status;
    ENSURE(get_status() == _status, "set_status() failure");
}

/*Get de height van de airplane
 *@param geen
 *@return int height van de airplane
 */
unsigned int Airplane::get_height() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling get_height()");
    return _height;
}

/*Set de height van de airplane
 *@param int height
 *@return niks void functie
 */
void Airplane::set_height(unsigned int _height) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't initialised when calling set_height()");
    Airplane::_height = _height;
    ENSURE(get_height() == _height,"set_height() failure");
}

const std::string &Airplane::get_type() const {
    return _type;
}

void Airplane::set_type(const std::string &type) {
    Airplane::_type = type;
}

const std::string &Airplane::get_engine() const {
    return _engine;
}

void Airplane::set_engine(const std::string &engine) {
    Airplane::_engine = engine;
}

const std::string &Airplane::get_size() const {
    return _size;
}

void Airplane::set_size(const std::string &size) {
    Airplane::_size = size;
}

Flightplan *Airplane::get_Flightplan() const {
    return _flightplan;
}

void Airplane::set_Flightplan(Flightplan *flightplan) {
    Airplane::_flightplan = flightplan;
}

