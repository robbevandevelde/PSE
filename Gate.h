//
// Created by uauser on 4/23/18.
//

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
    Gate(int _name);

    bool properlyInitialised();

    int getName();
    bool isOccupied();
    Airplane *getAirplane();

    void removeAirplane();
    void addAirplane(Airplane * airplane);
};


#endif //PSE_GATE_H
