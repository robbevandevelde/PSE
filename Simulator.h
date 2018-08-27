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
    Simulator(const vector<Runway *> &_runways, const vector<Airplane *> &_airplanes, Airport *_airport);

    bool properlyInitialised();

    void Simulate(std::ostream &out = std::cout);
    void addRunways();

    void doStep(ostream &out);
};


#endif //PSE_SIMULATOR_H
