//
// Created by uauser on 4/23/18.
//

#include "Runway.h"
#include "Airplane.h"

/*Constructor van de Runway
 *@param unsigned int length, string name, string type, airport airport
 *@return niks
 */
Runway::Runway(unsigned int _length, const std::string &_name, unsigned int _type, const std::string &_airport) :
        _length(_length), _name(_name), _rwType(_type), _airport(_airport)
{
    REQUIRE(_rwType<2, "type enum must be smaller than 2");
    _initcheck = this;
    _status = false;
    _goingtobeused = false;
    _airplane = NULL;
    _goingtobeusedby = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(!isStatus() && !isGoingToBeUsed(), "Status must be false after initialising");
    ENSURE(getAirplane() == NULL, "Airplane must point to a nullptr after initialising");
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
    REQUIRE(!isStatus(), "Status must be false");
    REQUIRE(getAirplane() == NULL, "Airplane must point to a nullptr");
    REQUIRE(getGoingtobeusedby()== airplane, "Airplanes don't match");
    _airplane = airplane;
    _status = true;
    _goingtobeused = true;
    ENSURE(getAirplane()->getHeight() == 0, "Added airplane's height isn't set to 0");
    ENSURE(getAirplane() == airplane, "Added airplane doesn't match airplane");
    ENSURE(getAirplane() == airplane, "Airplane must point to the given airplane");
    ENSURE(isStatus(),"Status must be true after adding an airplane");
}

/*remove een airplane van de runway
 *@param geen
 *@return niks
 */
void Runway::removeAirplane()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling removeAirplane()");
    REQUIRE(getAirplane() != NULL, "Airplane must point to an airplane and not a nullptr");
    REQUIRE(isStatus(), "Status must be true because the space is occupied");

    _airplane = NULL;
    _status = false;
    _goingtobeused = false;
    _goingtobeusedby = NULL;

    ENSURE(!isGoingToBeUsed(), " remove airplane failure");
    ENSURE(getAirplane() == NULL && getGoingtobeusedby() == NULL, "Airplane must point to a nullptr after removing a plane");
    ENSURE(!isStatus(),"Status must be false after removing a plane");
}

/*get de name
 *@param geen
 *@return string name
 */
std::string &Runway::getName()
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
unsigned int Runway::getType()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getType()");
    return _rwType;
}

/*set de type van de runway
 *@param string type
 *@return niks
 */
void Runway::setType(unsigned int _type)
{
    REQUIRE(_type < 2, "type enum must be smaller than 2");
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setType()");
    Runway::_rwType = _type;
    ENSURE(getType() == _rwType, "setType() failure");
}

/*get de naam van de airport
 *@param geen
 *@return string airport
 */
std::string &Runway::getAirport()
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
bool Runway::isOccupied()
{
    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getStatus()");
    return _status;
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
    ENSURE(isOccupied() == _status, "setStatus() failure");
}
/*set de goingtoebeusedstatus
 *@param geen
 *@return geen
 */
void Runway::setUsedStatus()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling setUsedStatus()");
    REQUIRE(!isGoingToBeUsed(), "setUsedSatus() failure");
    _goingtobeused = true;
    ENSURE(isGoingToBeUsed(), "setUsedStatus() failure");
}

/*Removed de gointobeused status
 *@param niks
 *@return niks
 */
void Runway::removeUsedStatus()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling removeUsedStatus()");
    _goingtobeused = false;
    ENSURE(!isGoingToBeUsed(), "removeUsedStatus() failure");
}

/*Checkt of dat de runway gebruikt gaat worden
 *@param geen
 *@return bool goingtobeused
 */
bool Runway::isGoingToBeUsed()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isUsedStatus()");
    return _goingtobeused;
}

/*return de _goingtobeusedby
 *@param geen
 *@return airplane
 */
Airplane *Runway::getGoingtobeusedby()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling getGoingtobeusedby()");
    return _goingtobeusedby;
}

/*set de _goingtobeusedby
 *@param airplane
 *@return niks
 */
void Runway::setGoingtobeusedby(Airplane *_goingtobeusedby)
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling setGoingtobeusedby");
    Runway::_goingtobeusedby = _goingtobeusedby;
    ENSURE(getGoingtobeusedby() == _goingtobeusedby, "setGoingtobeusedby() failure");
}

bool Runway::isStatus()  {
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isStatus()");
    return _status;
}
