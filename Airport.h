/*Dit is de airport, hier gebeurt het landen en opstijgen van vliegtuigen
 *@author: Thimoty
 *@date: 20/04/2018
 *@version: 2.0
 */
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

    std::vector<Airplane*> _RunwayWait;

    AirTrafficController* _controller;

    Airplane* _waitpoint1;

    Airplane* _waitpoint2;

    unsigned int _gatesize;
    unsigned int _amountRunways;
    std::string _name;
    std::string _iata;
    std::string _callsign;
public:
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(_gates.size() == _gatesize, "Gates has to be initialised correctly");
    //    ENSURE(_waitpoint1 == NULL && _waitpoint2 == NULL && _controller == NULL, "Values must point to NULL");
    //    ENSURE(_amountRunways == 0, "Amount of runways must be zero");
    //    ENSURE(getGatesize() == gatesize && getName() == name && getIata() == iata && getCallsign() == callsign, "Constructor failure");
    Airport(unsigned int _gatesize, const std::string &_name, const std::string &_iata,
            const std::string &_callsign);

    //Geen pre of post condities
    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling completeLandingSequence()");
    void completeLandingSequence(Airplane *airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling completeTakeOffsequence()");
    void completeTakeOffsequence(Airplane *airplane, std::ostream& out = std::cout);

    //    REQUIRE(airplane->getStatus() == Departure, "Airplane must be departure");
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling TakeOffProtocol");
    //    REQUIRE(airplane->getHeight() == 0, "Airplane must be on the ground");
    //    ENSURE(airplane->getStatus() == InTheAir, "TakeOff failure");
    //    ENSURE(_runways[x]->getAirplane() == NULL,"Take off failure");
    void takeOffprotocol(Airplane *airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(), "Airpower wasn't properly initialised when calling Landingprotocol");
    //    REQUIRE(airplane->getStatus() == Approaching, "Airplane must be approaching in order to land");
    //    ENSURE(airplane->getStatus() == FinalApproach, "Landing failure");
    //    ENSURE(airplane->getHeight() == 0, "Airplane must be at 0 ft");
    void landingprotocol(Airplane *airplane, std::ostream& out = std::cout);

    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling gateprotocol()");
    //    REQUIRE(airplane->getHeight() == 0 , "Airplane must be on the ground");
    //    3 post condities:
    //    Post conditie 1:
    //    ENSURE(airplane->getPassengers() == 0, "Passenger exit failure");
    //    ENSURE(airplane->getStatus() == StandingAtGate, "Failire");
    //    Post conditie 2:
    //    ENSURE(airplane->getFuel() == 1000, "Airplane hasn't been fueled");
    //    ENSURE(airplane->isFueled(), "Airplane should be fueled");
    //    Post conditie 3:
    //    ENSURE(airplane->getPassengers() == passengers, "Boarded passengers don't match with given amount");
    void gateprotocol(Airplane* airplane, unsigned int passengers, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling taxiToGate");
    void taxiToGate(Airplane *airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling taxiToRunway");
    void taxiToRunway(Airplane *airplane);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling addAirplaneToGate()");
    //    REQUIRE(airplane->getStatus() == JustLanded, "Airplane has to be standing at the runway in order to taxi");
    //    REQUIRE(_gates.size() == _gatesize, "Amount of gates don't match with the given amount of gates");
    //    ENSURE(_gates[x]->getAirplane() == airplane, "Airplane in gate doesn't match added airplane");
    void addAirplaneToGate(Airplane* airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    //    REQUIRE(airplane->getStatus() == Departure|| airplane->getStatus() == FinalApproach ||airplane->getStatus() == EmergencyLanding, "Not valid status for landing");
    //    REQUIRE(airplane->getHeight() == 0, "Airplane must be on the ground");
    //    2 post condities:
    //    Post conditie 1:
    //    ENSURE(_runways[x]->getAirplane() == airplane, "addAirplaneToRunway() failure");
    //    Post conditie 2:
    //    ENSURE(_runways[x]->getAirplane()->getStatus() == JustLanded, "Add airplane to runway failure");
    //    ENSURE(_runways[x]->getAirplane() == airplane, "addAirplaneToRunway() failure");
    void addAirplaneToRunway(Airplane* airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneFromGate()");
    //    ENSURE(_gates[x]->getAirplane() == NULL,"Remove airplane of gate failure");
    void removeAirplaneFromGate(Airplane *airplane, std::ostream &out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfFrumway()");
    //    ENSURE(_runways[x]    ->getAirplane() == NULL, "Remove airplane of runway failure");
    void removeAirplaneFromRunway(Airplane *airplane);

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize()");
    unsigned int getGatesize();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getName()");
    const std::string &getName();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getIata()";
    const std::string &getIata();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getCallsign()";
    const std::string &getCallsign();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setIata()");
    //    ENSURE(getIata() == _iata, "setIata() failure");
    void setIata(const std::string &_iata);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setName()");
    //    ENSURE(getName() == _name, "setName() failure");
    void setName(const std::string &_name);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setGatesize()");
    //    ENSURE(getGatesize() == _gatesize, "setGatesize() failure");
    void setGatesize(unsigned int _gatesize);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setCallsign()");
    //    ENSURE(getCallsign() == _callsign, "setCallsign() failure");
    void setCallsign(const std::string &_callsign);
    //    REQUIRE(this->properlyInitialised(), "Airprort wasn't properly initialised when calling isRunwayNotUsed()");
    bool isRunwayNotUsed();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isRunwayEmpty()");
    bool isRunwayEmpty();
    //    REQUIRE(this->properlyInitialised(), "Airport wgetUsedasn't properly initialised when calling addRunway()");
    //    ENSURE(_runways[_runways.size() -1] == runway, "addRunway failure");
    void addRunway(Runway* runway);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getAmountRunways()");
    unsigned int getAmountRunways();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint1()");
    //    ENSURE(_waitpoint1 == NULL, "removeWaitpoint1() failure");
    void removeWaitpoint1();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint1()");
    Airplane *getWaitpoint1();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint1()");
    //    ENSURE(getWaitpoint1() == waitpoint1, "setWaitpoint1() failure");
    void setWaitpoint1(Airplane *waitpoint1);

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint2()");
    //    ENSURE(_waitpoint2 == NULL, "removeWaitpoint2() failure");
    void removeWaitpoint2();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint2()");
    Airplane *getWaitpoint2();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint2()");
    //    ENSURE(getWaitpoint2() == waitpoint2, "setWaitpoint2() failure");
    void setWaitpoint2(Airplane *waitpoint2);

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getController()");
    AirTrafficController *getController();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling assignController()");
    //    ENSURE(getController() == _controller, "assignController() failure");
    void assignController(AirTrafficController *_controller);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getFreeRunwaySpot()");
    unsigned int getFreeRunwaySpot();
    //    REQUIRE(this->properlyInitialised(), "Airprort wasn't properly initialised when calling getRunways()");
    const vector<Runway *> &getRunways();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunwayWait()");
    //    ENSURE(runwayWaitChecker(airplane), "add airplane to runwaywait failure");
    void addRunwayWait(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeRunwayWait()");
    void removeRunwayWait(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling RunWaitChecker()");
    bool runwayWaitChecker(Airplane *airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling goingToBeUsedRunway()");
    void goingToBeUsedRunway(Airplane *airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isARunwayCompletelyClear()");
    bool isARunwayCompletelyClear();

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInGate");
    bool isAirplaneInGate(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInRunway");
    bool isAirplaneInRunway(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling emergencyControle()");
    //    REQUIRE(airplane->getStatus() == EmergencyControle1, "Not valid status for airplane status");
    //    REQUIRE(airplane->getHeight() == 0, "Airplane must be on ground");
    void emergencyControle(Airplane* airplane, std::ostream& out);

    bool validRunwayForPlane(Airplane* airplane, Runway* runway);
};
#endif //PSE_AIRPORT_H