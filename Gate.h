/*Dit is een gate, deze zullen in de airport klasse gezet worden waar airplanes in kunnen worden geplaatst
 *@author: Thimoty
 *@date: 23/04/2018
 *@version: 2.0
 */

#ifndef PSE_GATE_H
#define PSE_GATE_H

#include <iostream>
#include "Airplane.h"

class Gate {
    Gate* _initcheck;
    Airplane* _airplane;

    int _name;

    bool _occupied;
public:
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(_airplane == NULL, "Airplane must point to nullptr");
    //    ENSURE(getName() == _name, "Gate constructor failure");
    Gate(int _name);
    //    Geen pre of post condities
    bool properlyInitialised();
    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling getName()");
    int getName();
    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isOccupied()");
    bool isOccupied();
    //    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling getAirplane()");
    Airplane *getAirplane();

    //    REQUIRE(this->properlyInitialised(),"Gate wasn't properly initialised when calling removeAirplane()");
    //    ENSURE(getAirplane() == NULL, "Airplane must point to NULL");
    //    ENSURE(!_occupied, "Occupied must be false");
    void removeAirplane();
    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling addAirplane()");
    //    ENSURE(getAirplane() == airplane, "addAirplane() failure");
    //    ENSURE(_occupied, "Occupied must be true");
    void addAirplane(Airplane * airplane);
};


#endif //PSE_GATE_H
