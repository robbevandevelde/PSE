
#include "Gate.h"

/*Constructor van gate
 *@param string name
 *@return geen
 */
Gate::Gate(unsigned int _name) : _name(_name)
{
    _initcheck = this;
    _occupied = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(getAirplane() == NULL, "Airplane must point to nullptr");
    ENSURE(getName() == _name, "Gate constructor failure");
}

/*initcheck
 *@param geen
 *@return bool
 */
bool Gate::properlyInitialised()
{
    return _initcheck == this;
}

/*add een airplane aan de gate
 *@param airplane airplane
 *@return geen
 */
void Gate::addAirplane(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling addAirplane()");
    REQUIRE(airplane != NULL, "Airplane cannot be nothing");
    _airplane = airplane;
    _occupied = true;
    ENSURE(getAirplane() == airplane, "addAirplane() failure");
    ENSURE(isOccupied(), "Occupied must be true");
}

/*Removed een airplane van de gate
 *@param geen
 *@return geen
 */
void Gate::removeAirplane()
{
    REQUIRE(getAirplane() != NULL, "Airplane cannot be NULL");
    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling removeAirplane()");
    _airplane = NULL;
    _occupied = false;
    ENSURE(getAirplane() == NULL, "Airplane must point to NULL");
    ENSURE(!isOccupied(), "Occupied must be false");
}

/*return de status van de gate
 *@param geen
 *@return bool
 */
bool Gate::isOccupied()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isOccupied()");
    return _occupied;
}

/*get de name van de gate
 *@param geen
 *@return string name
 */
unsigned int Gate::getName()
{
    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling getName()");
    return _name;
}

/*get de airplane van de gate
 *@param geen
 *@return airplane airplane van de gate
 */
Airplane *Gate::getAirplane()
{
    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling getAirplane()");
    return _airplane;
}


