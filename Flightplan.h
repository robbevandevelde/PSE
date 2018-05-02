//
// Created by Robbe Van de Velde on 24/04/18.
//

#ifndef PSE_FLIGHTPLAN_H
#define PSE_FLIGHTPLAN_H
#include "DesignByContract.h"

#include <string>
using namespace std;

class Flightplan {
private:
    std::string destination;
    unsigned int departure;
    unsigned int arrival;
    unsigned int interval;
    Flightplan* initCheck;

public:
    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();
    /* Contract
    * PRE:
    * POST:
    */
    void setDestination(string &destination);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:destination is now the given parameter
    */
    void setDeparture(unsigned int departure);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:departure is now the given parameter
    */
    void setArrival(unsigned int arrival);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:arrival is now the given parameter
    */
    void setInterval(unsigned int interval);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:interval is now the given parameter
    */
    unsigned int getArrival();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:returned arrival
    */
    unsigned int getInterval();
    /* Contract
    * PRE:Must be Properly initialised
    * POST::returned arrival
    */
    unsigned int getDeparture();
    /* Contract
    * PRE:Must be Properly initialised
    * POST::returned arrival
    */
    string &getDestination();
    /* Contract
    * PRE:Must be Properly initialised
    * POST::returned arrival
    */
    Flightplan(std::string& dest, unsigned int dep, unsigned int arr, unsigned int inter);


};


#endif //PSE_FLIGHTPLAN_H
