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
                   std::string type, std::string engine, std::string size, Flightplan* flightp)
{

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
bool Airplane::properlyInitialised()
{
    return _initcheck == this;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
unsigned int Airplane::getFuel()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getFuel()");
    return _fuel;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
void Airplane::setFuel(unsigned int _fuel)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFuel()");
    Airplane::_fuel = _fuel;
    ENSURE(getFuel() == _fuel, "setFuel() failure");
}

/*Get de passengers van de airplane
 *@param geen
 *@return int hoeveelheid passengers in de airplane
 */
unsigned int Airplane::getPassengers()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getPassengers()");
    return _passengers;
}

/*Set de passengers van de airplane
 *@param string status
 *@return niks void functie
 */
void Airplane::setPassengers(unsigned int _passengers)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setPassengers()");
    Airplane::_passengers = _passengers;
    ENSURE(getPassengers() == _passengers, "setPassengers() failure");
}

/*Get de number van de airplane
 *@param string number
 *@return string number van de airplane
 */
const std::string &Airplane::getNumber()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getNumber()");
    return _number;
}

/*Set de number van de airplane
 *@param string number
 *@return niks void functie
 */
void Airplane::setNumber(const std::string &_number)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setNumber()");
    Airplane::_number = _number;
    ENSURE(getNumber() == _number, "setNumber() failure");
}

/*Get de de callsign
 *@param geen
 *@return string callsign van de airplane
 */
const std::string &Airplane::getCallsign()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getCallsign()");
    return _callsign;
}

/*Set de de callsign
 *@param string callsign
 *@return niks void functie
 */
void Airplane::setCallsign(const std::string &_callsign)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setCallsign()");
    Airplane::_callsign = _callsign;
    ENSURE(getCallsign() == _callsign, "setCallsign() failure");
}

/*Get de model van de airplane
 *@param geen
 *@return string model van de airplane
 */
const std::string &Airplane::getModel()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getModel()");
    return _model;
}

/*Set de model van de airplane
 *@param string model
 *@return niks void functie
 */
void Airplane::setModel(const std::string &_model)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setModel()");
    Airplane::_model = _model;
    ENSURE(getModel() == _model, "setModel() failure");
}

/*Get de status van de airplane
 *@param geen
 *@return int status van de airplane (enumerator)
 */
unsigned int Airplane::getStatus()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getStatus()");
    return _status;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
void Airplane::setStatus(unsigned int _status)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setStatus()");
    Airplane::_status = _status;
    ENSURE(getStatus() == _status, "setStatus() failure");
}

/*Get de height van de airplane
 *@param geen
 *@return int height van de airplane
 */
unsigned int Airplane::getHeight()
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getHeight()");
    return _height;
}

/*Set de height van de airplane
 *@param int height
 *@return niks void functie
 */
void Airplane::setHeight(unsigned int _height)
{
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setHeight()");
    Airplane::_height = _height;
    ENSURE(getHeight() == _height,"setHeight() failure");
}

const std::string &Airplane::getType()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getType()");
    return _type;
}

void Airplane::setType(const std::string &type)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setType()");
    Airplane::_type = type;
    ENSURE(getType() == type,"setType() failure");
}

const std::string &Airplane::getEngine()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getEngine()");
    return _engine;
}

void Airplane::setEngine(const std::string &engine)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setEngine()");
    Airplane::_engine = engine;
    ENSURE(getEngine() == engine, "setEngine() failure");
}

const std::string &Airplane::getSize()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getSize()");
    return _size;
}

void Airplane::setSize(const std::string &size)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setSize()");
    Airplane::_size = size;
    ENSURE(getSize() == size, "setSize() failure");
}

Flightplan *Airplane::getFlightplan()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getFlightplan");
    return _flightplan;
}

void Airplane::setFlightplan(Flightplan *flightplan)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setFlightplan()");
    Airplane::_flightplan = flightplan;
    ENSURE(getFlightplan() == flightplan, "setFlightplan() failure");
}

