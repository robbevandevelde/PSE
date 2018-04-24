//
// Created by Robbe Van de Velde on 24/04/18.
//

#ifndef PSE_FLIGHTPLAN_H
#define PSE_FLIGHTPLAN_H

#include <string>
using namespace std;

class Flightplan {
private:
    string destination;
    int departure;
    int arrival;
    int interval;
public:

    Flightplan(string dest, int dep, int arr, int inter){destination = dest, departure=dep, arrival= arr, interval=inter;};
    const string &getDestination() const;
    Flightplan();
    void setDestination(const string &destination);

    int getDeparture() const;

    void setDeparture(int departure);

    int getArrival() const;

    void setArrival(int arrival);

    int getInterval() const;

    void setInterval(int interval);

};


#endif //PSE_FLIGHTPLAN_H
