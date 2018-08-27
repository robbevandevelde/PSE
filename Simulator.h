/*Dit is de simulator dat het landen en opstijgen automatiseerd
 *@author: Thimoty
 *@date: 26/04/2018
 *@version: 2.0
 */

#ifndef PSE_SIMULATOR_H
#define PSE_SIMULATOR_H

#include <iostream>
#include "Runway.h"
#include "Airplane.h"
#include "Airport.h"
#include "DesignByContract.h"
class Simulator {
private:
    Simulator* _initcheck;
    std::vector<Runway*> _runways;
    std::vector<Airplane*> _airplanes;
    Airport* _airport;
public:

    //    ENSURE(properlyInitialised(), "Constructor must end");
    Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport);

    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling Simulate()");
    void Simulate(std::ostream &out = std::cout);

    //    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling addRunways()");
    //    ENSURE(_airport->getAmountRunways() == _runways.size(), "Runway size dont match");
    void addRunways();

    //    REQUIRE(this->properlyInitialised(), "Simulator wasn't properly initialised when calling Simulate()");
    void doStep(ostream &out);
};


#endif //PSE_SIMULATOR_H
