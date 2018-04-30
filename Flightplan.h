//
// Created by Robbe Van de Velde on 24/04/18.
//

#ifndef PSE_FLIGHTPLAN_H
#define PSE_FLIGHTPLAN_H

#include <string>
using namespace std;

class Flightplan {
private:
    std::string destination;
    unsigned int departure;
    unsigned int arrival;
    unsigned int interval;

public:

    void setDestination(const string &destination);
    void setDeparture(unsigned int departure);
    void setArrival(unsigned int arrival);
    void setInterval(unsigned int interval);

    unsigned int getArrival() const;
    unsigned int getInterval() const;
    unsigned int getDeparture() const;
    const string &getDestination() const;


    Flightplan(std::string& dest, unsigned int dep, unsigned int arr, unsigned int inter);


};


#endif //PSE_FLIGHTPLAN_H
