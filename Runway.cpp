//
// Created by uauser on 4/23/18.
//

#include "Runway.h"
#include "Airplane.h"
#include "Taxiroute.h"

/*Constructor van de Runway
 *@param unsigned int length, string name, string type, airport airport
 *@return niks
 */
Runway::Runway(unsigned int _length, const std::string &_name, const std::string &_type, const std::string &_airport) :
        _length(_length), _name(_name), _type(_type), _airport(_airport)
{
    _initcheck = this;
    _status = false;
    _goingtobeused = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(!_status && !_goingtobeused, "Status must be false after initialising");
    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after initialising");
}

/*initcheck
 *@param geen
 *@return bool
 */
bool Runway::properlyInitialised()
{
    return _initcheck == this;
}

/*add een airplane aan de runway
 *@param airplane airplane
 *@return geen
 */
void Runway::addAirplane(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling addAirplane()");
    REQUIRE(!_status, "Status must be false");
    REQUIRE(_airplane == NULL, "Airplane must point to a nullptr");

    _airplane = airplane;
    _status = true;

    _airplane->setHeight(0);
    ENSURE(_airplane->getHeight() == 0, "Added airplane's height isn't set to 0");

    ENSURE(getAirplane() == airplane, "Added airplane doesn't match airplane");

    ENSURE(getAirplane() == airplane, "Airplane must point to the given airplane");
    ENSURE(_status,"Status must be true after adding an airplane");
}

/*remove een airplane van de runway
 *@param geen
 *@return niks
 */
void Runway::removeAirplane()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling removeAirplane()");
    REQUIRE(_airplane != NULL, "Airplane must point to an airplane and not a nullptr");
    REQUIRE(_status, "Status must be true because the space is occupied");

    _airplane = NULL;
    _status = false;
    _goingtobeused = false;
    ENSURE(!_goingtobeused, " remove airplane failure");
    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after removing a plane");
    ENSURE(!_status,"Status must be false after removing a plane");
}

/*get de name
 *@param geen
 *@return string name
 */
const std::string &Runway::getName()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getName()");
    return _name;
}

/*set de name van de runway
 *@param string name
 *@return geen
 */
void Runway::setName(const std::string &_name)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setName()");
    Runway::_name = _name;
    ENSURE(getName() == _name, "setName() failure");
}

/*get de type van de runway
 *@param geen
 *@return string type
 */
const std::string &Runway::getType()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getType()");
    return _type;
}

/*set de type van de runway
 *@param string type
 *@return niks
 */
void Runway::setType(const std::string &_type)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setType()");
    Runway::_type = _type;
    ENSURE(getType() == _type, "setType() failure");
}

/*get de naam van de airport
 *@param geen
 *@return string airport
 */
const std::string &Runway::getAirport()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirport()");
    return _airport;
}

/*set de airport
 *@param string airport
 *@return geen
 */
void Runway::setAirport(const std::string &_airport)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirport()");
    Runway::_airport = _airport;
    ENSURE(getAirport() == _airport, "setAirport failure");
}

/*get de length van de runway
 *@param geen
 *@return int length
 */
unsigned int Runway::getLength()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getLength()");
    return _length;
}

/*set de length van de runway
 *@param unsigned int length
 *@return niks
 */
void Runway::setLength(unsigned int _length)
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setLength()");
    Runway::_length = _length;
    ENSURE(getLength() == _length, "setLength() failure");
}

/*get de airplane van de runway
 *@param geen
 *@return airplane airplane
 */
Airplane *Runway::getAirplane()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirplane()");
    return _airplane;
}

/*get de status van de runway
 *@param geen
 *@return bool de status van de runway
 */
bool Runway::isStatus()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getStatus()");
    return _status;
}

/*get de taxiroute van de runway
 *@param geen
 *@return vector taxiroute
 */
const vector<Taxiroute *> &Runway::getTaxiRoute()
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling getTaxiRoute()");
    return _taxiRoute;
}

/*set de taxiroute
 *@param vector taxiroute
 *@return niks
 */
void Runway::setTaxiRoute(const vector<Taxiroute *> &taxiRoute)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling ()");
    Runway::_taxiRoute = taxiRoute;
    ENSURE(getTaxiRoute() == taxiRoute, "setTaxiRoute() failure");
}

/*pusht een taxi route in de vecttor
 *@param taxiroute
 *@return niks
 */
void Runway::pushbackTaxi(Taxiroute *taxiroute)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling pushbackTaxi()");
    _taxiRoute.push_back(taxiroute);
    ENSURE(_taxiRoute[_taxiRoute.size() - 1] == taxiroute, "pushbackTaxi() failure");
}

/*set de airplane van de airplane
 *@param airplane airplane
 *@return geen
 */
void Runway::setAirplane(Airplane *_airplane)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirplane()");
    Runway::_airplane = _airplane;
    ENSURE(getAirplane() == _airplane, "setAirplane() failure");
}

/*set de status van de runway
 *@param bool status
 *@return geen
 */
void Runway::setStatus(bool _status)
{
    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setStatus()");
    Runway::_status = _status;
    ENSURE(isStatus() == _status, "setStatus() failure");
}

void Runway::setUsedStatus() {
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling setUsedStatus()");
    _goingtobeused = true;
    ENSURE(_goingtobeused, "setUsedStatus failure");
}

void Runway::removeUsedStatus() {
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling removeUsedStatus()");
    _goingtobeused = false;
    ENSURE(!_goingtobeused, "removeUsedStatus() failure");
}

bool Runway::isUsed() {
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isUsedStatus()");
    return _goingtobeused;
}
