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
 *
 * REQUIRES EN ENSURES IN HEADERS ZETTE ALS COMMENT
 *
 *
 *
 */

class AirTrafficController;
class Airport
{
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

    void addAirplaneToGate(Airplane* airplane);
    void addAirplaneToRunway(Airplane* airplane);
    void removeAirplaneOfGate(Airplane* airplane);
    void removeAirplaneOfRunway(Airplane* airplane);

public:
    Airport(unsigned int _gatesize, const std::string &_name, const std::string &_iata,
            const std::string &_callsign);

    bool properlyInitialised();

    void gateprotocol(Airplane* airplane, unsigned int passengers);

    const std::string &get_name();
    const std::string &get_iata();
    unsigned int get_gatesize();
    const std::string &get_callsign();


    void completeLandingSequence(Airplane *airplane);
    void completeTakeOffsequence(Airplane *airplane);

    void TakeOffprotocol(Airplane* airplane);
    void Landingprotocol(Airplane* airplane);

    void set_callsign(const std::string &_callsign);
    void set_iata(const std::string &_iata);
    void set_name(const std::string &_name);
    void set_gatesize(unsigned int _gatesize);

    void addRunway(Runway* runway);

    void TaxiToRunway(Airplane* airplane);
    void TaxiToGate(Airplane* airplane);

    bool isRunwayEmpty();

    Airplane *getWaitpoint1() const;

    void setWaitpoint1(Airplane *waitpoint1);

    Airplane *getWaitpoint2() const;

    void setWaitpoint2(Airplane *waitpoint2);

    void removeWaitpoint1();
    void removeWaitpoint2();

    void assignController(AirTrafficController *_controller);
};


#endif //PSE_AIRPORT_H
