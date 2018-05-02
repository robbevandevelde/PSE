//
// Created by uauser on 4/23/18.
//

#include "Gate.h"

/*Constructor van gate
 *@param string name
 *@return geen
 */
Gate::Gate(int _name) : _name(_name)
{
    _initcheck = this;
    _occupied = false;
    _airplane = NULL;
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_airplane == NULL, "Airplane must point to nullptr");
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
    _airplane = airplane;
    ENSURE(getAirplane() == airplane, "addAirplane() failure");
    _occupied = true;
    ENSURE(_occupied, "Occupied must be true");
}

/*Removed een airplane van de gate
 *@param geen
 *@return geen
 */
void Gate::removeAirplane()
{
    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling removeAirplane()");
    _airplane = NULL;
    ENSURE(getAirplane() == NULL, "Airplane must point to NULL");
    _occupied = false;
    ENSURE(!_occupied, "Occupied must be false");
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
int Gate::getName()
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


