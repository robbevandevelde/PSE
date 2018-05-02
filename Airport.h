//
// Created by uauser on 4/23/18.
//

#ifndef PSE_AIRPORT_H
#define PSE_AIRPORT_H

#include <vector>
#include <sstream>
#include <iostream>
#include "Airplane.h"
#include "AirTrafficController.h"

class Gate;
class Runway;
class DesignByContract;

/*
 * REQUIRES EN ENSURES IN HEADERS ZETTE ALS COMMENT
 *
 */

class Airport {
private:
    Airport* _initcheck;

    std::vector<Gate*> _gates;
    std::vector<Runway*> _runways;

    AirTrafficController* _controller;

    Airplane* _waitpoint1;

    Airplane* _waitpoint2;

    unsigned int _gatesize;
    unsigned int _amountRunways;

    std::string _name;
    std::string _iata;
    std::string _callsign;

public:
    Airport(unsigned int _gatesize, const std::string &_name, const std::string &_iata,
            const std::string &_callsign);

    bool properlyInitialised();

    void completeLandingSequence(Airplane *airplane);
    void completeTakeOffsequence(Airplane *airplane);

    void TakeOffprotocol(Airplane* airplane);
    void Landingprotocol(Airplane* airplane);
    void gateprotocol(Airplane* airplane, unsigned int passengers);

    void TaxiToGate(Airplane* airplane);
    void TaxiToRunway(Airplane* airplane);
    void addAirplaneToGate(Airplane* airplane);
    void addAirplaneToRunway(Airplane* airplane);
    void removeAirplaneOfGate(Airplane* airplane);
    void removeAirplaneOfRunway(Airplane* airplane);

    unsigned int getGatesize();
    const std::string &getName();
    const std::string &getIata();
    const std::string &getCallsign();

    void setIata(const std::string &_iata);
    void setName(const std::string &_name);
    void setGatesize(unsigned int _gatesize);
    void setCallsign(const std::string &_callsign);

    bool isRunwayEmpty();
    void addRunway(Runway* runway);
    unsigned int getAmountRunways();

    void removeWaitpoint1();
    Airplane *getWaitpoint1();
    void setWaitpoint1(Airplane *waitpoint1);

    void removeWaitpoint2();
    Airplane *getWaitpoint2();
    void setWaitpoint2(Airplane *waitpoint2);


    AirTrafficController *getController();
    void assignController(AirTrafficController *_controller);
};


#endif //PSE_AIRPORT_H
