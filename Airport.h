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
    /* Contract
     * PRE:
     * POST:
     */
    Airport(unsigned int _gatesize, const std::string &_name, const std::string &_iata,
            const std::string &_callsign);

    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();

    /* Contract
    * PRE:
    * POST:
    */
    void completeLandingSequence(Airplane *airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void completeTakeOffsequence(Airplane *airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void TakeOffprotocol(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void Landingprotocol(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void gateprotocol(Airplane* airplane, unsigned int passengers);
    /* Contract
    * PRE:
    * POST:
    */
    void TaxiToGate(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void TaxiToRunway(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void addAirplaneToGate(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void addAirplaneToRunway(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    /* Contract
    * PRE:
    * POST:
    */
    void removeAirplaneOfGate(Airplane* airplane);
    /* Contract
    * PRE:
    * POST:
    */
    void removeAirplaneOfRunway(Airplane* airplane);

    /* Contract
    * PRE:
    * POST:
    */
    unsigned int getGatesize();
    /* Contract
    * PRE:
    * POST:
    */
    const std::string &getName();
    /* Contract
    * PRE:
    * POST:
    */
    const std::string &getIata();
    /* Contract
    * PRE:
    * POST:
    */
    const std::string &getCallsign();

    /* Contract
    * PRE:
    * POST:
    */
    void setIata(const std::string &_iata);
    /* Contract
    * PRE:
    * POST:
    */
    void setName(const std::string &_name);
    /* Contract
    * PRE:
    * POST:
    */
    void setGatesize(unsigned int _gatesize);
    /* Contract
    * PRE:
    * POST:
    */
    void setCallsign(const std::string &_callsign);

    bool isRunwayNotUsed();
    /* Contract
    * PRE:
    * POST:
    */
    bool isRunwayEmpty();
    /* Contract
    * PRE:
    * POST:
    */
    void addRunway(Runway* runway);
    /* Contract
    * PRE:
    * POST:
    */
    unsigned int getAmountRunways();

    /* Contract
    * PRE:
    * POST:
    */
    void removeWaitpoint1();
    /* Contract
    * PRE:
    * POST:
    */
    Airplane *getWaitpoint1();
    /* Contract
    * PRE:
    * POST:
    */
    void setWaitpoint1(Airplane *waitpoint1);

    /* Contract
    * PRE:
    * POST:
    */
    void removeWaitpoint2();
    /* Contract
    * PRE:
    * POST:
    */
    Airplane *getWaitpoint2();
    /* Contract
    * PRE:
    * POST:
    */
    void setWaitpoint2(Airplane *waitpoint2);

    /* Contract
    * PRE:
    * POST:
    */
    AirTrafficController *getController();
    /* Contract
    * PRE:
    * POST:
    */
    void assignController(AirTrafficController *_controller);

    unsigned int getFreeRunwaySpot();

    const vector<Runway *> &getRunways();
};
#endif //PSE_AIRPORT_H