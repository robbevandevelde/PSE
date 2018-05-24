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
                   unsigned int type, unsigned int engine, unsigned int size, Flightplan* flightp)
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
    _fueled = false;
    ENSURE(!_fueled, "Fueled must be false");
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_height == 0 || _height == 10000, "Height must be either 0 or 10000");
    ENSURE(getNumber() == number && getCallsign() == callsign && getModel() == model && getStatus() == status &&
           getPassengers() == passengers && getFuel() == fuel && getType() == type && getEngine() == engine &&
           getSize() == size && getFlightplan() == flightp, "Airplane constructor failure");
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

/*get de height van de airplane
 *@param geen
 *@return string type van airplane
 */
unsigned int Airplane::getType()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getType()");
    return _type;
}

/*set de type van de airplane
 *@param string type
 *@return niks
 */
void Airplane::setType(unsigned int type)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setType()");
    Airplane::_type = type;
    ENSURE(getType() == type,"setType() failure");
}

/*get de engine van de airplane
 *@param geen
 *@return string engine van de airplane
 */
unsigned int Airplane::getEngine()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getEngine()");
    return _engine;
}

/*set de engine van de airplane
 *@param string engine
 *@return geen
 */
void Airplane::setEngine(unsigned int engine)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setEngine()");
    Airplane::_engine = engine;
    ENSURE(getEngine() == engine, "setEngine() failure");
}

/*get de size van de airplane
 *@param geen
 *@return string size van de airplane
 */
unsigned int Airplane::getSize()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getSize()");
    return _size;
}

/*set de size van de airplane
 *@param string size
 *@return geen
 */
void Airplane::setSize(unsigned int size)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setSize()");
    Airplane::_size = size;
    ENSURE(getSize() == size, "setSize() failure");
}

/*get de flightplan van de airplane
 *@param geen
 *@return Flightplan flightplan van de airplane
 */
Flightplan *Airplane::getFlightplan()
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getFlightplan");
    return _flightplan;
}

/*set de flightplan van de vliegtuig
 *@param Flightplan flightplan
 *@return geen
 */
void Airplane::setFlightplan(Flightplan *flightplan)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setFlightplan()");
    Airplane::_flightplan = flightplan;
    ENSURE(getFlightplan() == flightplan, "setFlightplan() failure");
}

/*Ascend de vliegtuig met 1000 ft
 *@param geen
 *@return geen
 */
void Airplane::ascend(std::ostream& out)
{
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling ascend()");
    _height += 1000;
    ENSURE(getHeight() == _height, "Height is not altered");
    out<< _callsign << " ascended to " << _height << " ft." << std::endl;
}

/*Descend de vliegtuig met 1000 ft
 *@param geen
 *@return geen
 */
void Airplane::descend(std::ostream& out) {
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling descend()");
    _height -= 1000;
    ENSURE(getHeight() == _height, "Height is not altered");
    out<< _callsign << " descended to " << _height << " ft." << std::endl;
}

/*Checkt of dat de vliegtuig bijgetankt is
 *@param geen
 *@return bool fueled
 */
bool Airplane::isFueled() {
    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling isFueled()");
    return _fueled;
}

/*Set de fueled status
 *@param bool fueled
 *@return geen
 */
void Airplane::setFueled(bool _fueled) {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFueled()");
    Airplane::_fueled = _fueled;
    ENSURE(isFueled() == _fueled, "setFueled fail");
}

bool Airplane::isAllowedToLandOnGrass() {
    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFueled()");
    if(_size  == Small && _engine == Propeller){
        return true;
        ENSURE(_size == Small, "Airplane is too big to land on grass");
        ENSURE(_engine == Propeller, "This engine is not a propeller");
    }
    return false;
}

