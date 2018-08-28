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
class Communication;

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
    Communication* _comm;
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(getGates().size() == _gatesize, "Gates has to be initialised correctly");
    //    ENSURE(getWaitpoint1() == NULL && getWaitpoint2() == NULL && _controller == NULL, "Values must point to NULL");
    //    ENSURE(getRunways().size() == 0, "Amount of runways must be zero");
    //    ENSURE(getGatesize() == gatesize && getName() == name && getIata() == iata && getCallsign() == callsign, "Constructor failure");
    Airport(unsigned int _gatesize, const std::string &_name, const std::string &_iata,
            const std::string &_callsign);

    //Geen pre of post condities
    bool properlyInitialised();

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
    void taxiToGate(Airplane *airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling taxiToRunway");
    void taxiToRunway(Airplane *airplane,std::ostream &out);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling addAirplaneToGate()");
    //    REQUIRE(airplane->getStatus() == JustLanded, "Airplane has to be standing at the runway in order to taxi");
    //    REQUIRE(getGates().size() == _gatesize, "Amount of gates don't match with the given amount of gates");
    //    ENSURE(isAirplaneInGate(airplane), "Airplane in gate doesn't match added airplane");
    void addAirplaneToGate(Airplane* airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    //    REQUIRE(airplane->getStatus() == Departure|| airplane->getStatus() == FinalApproach ||airplane->getStatus() == EmergencyLanding, "Not valid status for landing");
    //    REQUIRE(airplane->getHeight() == 0, "Airplane must be on the ground");
    //    3 post condities:
    //    Post conditie 1:
    //    ENSURE(isAirplaneInRunway(airplane), "addAirplaneToRunway() failure");
    //    Post conditie 2:
    //    ENSURE(airplane->getStatus() == JustLanded,
    //    ENSURE(isAirplaneInRunway(airplane), "addAirplaneToRunway() failure");
    //    Post conditie 3:
    //    ENSURE(airplane->getStatus() == EmergencyControle1,"Add airplane to runway failure");
    //    ENSURE(isAirplaneInRunway(airplane), "addAirplaneToRunway() failure");
    void addAirplaneToRunway(Airplane* airplane, std::ostream& out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneFromGate()");
    //    ENSURE(isAirplaneRemovedFromGate(airplane),"Remove airplane of gate failure");
    void removeAirplaneFromGate(Airplane *airplane, std::ostream &out = std::cout);
    //    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfFrumway()");
    //    ENSURE(isAirplaneRemovedFromRunway(airplane), "Remove airplane of runway failure");
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
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isRunwayEmpty()");
    bool isRunwayEmpty();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunway()");
    void addRunway(Runway* runway);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getAmountRunways()");
    unsigned int getAmountRunways();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint1()");
    //    ENSURE(getWaitpoint1() == NULL, "removeWaitpoint1() failure");
    void removeWaitpoint1();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint1()");
    Airplane *getWaitpoint1();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint1()");
    //    ENSURE(getWaitpoint1() == waitpoint1, "setWaitpoint1() failure");
    void setWaitpoint1(Airplane *waitpoint1);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint2()");
    //    ENSURE(getWaitpoint2() == NULL, "removeWaitpoint2() failure");
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
    //    REQUIRE(this->properlyInitialised(), "Airprort wasn't properly initialised when calling getRunways()");
    vector<Runway *> &getRunways();
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunwayWait()");
    //    ENSURE(isAirplaneInRunwayWait(airplane), "add airplane to runwaywait failure");
    void addRunwayWait(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeRunwayWait()");
    void removeRunwayWait(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling RunWaitChecker()");
    bool isAirplaneInRunwayWait(Airplane *airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling goingToBeUsedRunway()");
    void goingToBeUsedRunway(Airplane *airplane);

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInGate");
    bool isAirplaneInGate(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInRunway");
    bool isAirplaneInRunway(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling emergencyControle()");
    //    REQUIRE(airplane->getStatus() == EmergencyControle1, "Not valid status for airplane status");
    //    REQUIRE(airplane->getHeight() == 0, "Airplane must be on ground");
    void emergencyControle(Airplane* airplane, std::ostream& out);

    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling validRunwayForPlane()");
    bool validRunwayForPlane(Airplane* airplane, Runway* runway);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInWaitPoint()");
    bool isAirplaneInWaitPoint(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverAirStart()");
    //    ENSURE(getWaitpoint2() == airplane || getWaitpoint1() == airplane || airplane->getHeight() == 10000, "Collisionsolver failure");
    void collisionSolverAirStart(Airplane *airplane,std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverAirEnd()");
    //    ENSURE(airplane->getStatus() == Approaching || airplane->getStatus() == FinalApproach, "Collisionsolver failure");
    void collisionSolverAirEnd(Airplane *airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverRunwayStart()");
    //    ENSURE(airplane->getStatus() == WaitingAtRunway, "Collisionsolver failure");
    void collisionSolverRunwayStart(Airplane *airplane,std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverRunwayEnd()");
    //    ENSURE(isAirplaneInRunway(airplane),"Collisionsolver failure");
    //    ENSURE(isAirplaneInRunwayWait(airplane), "Collisionsolver failure");
    void collisionSolverRunwayEnd(Airplane *airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling landingSequence()");
    //    REQUIRE(airplane->getStatus() == Approaching || airplane->getStatus() == FinalApproach,"Aircontrole failure, aircraft isn't in the air");
    void landingSequence(Airplane *airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling completeGateProtocol()");
    //    REQUIRE(airplane->getStatus() == JustLanded || airplane->getStatus() == StandingAtGate, "Complete Gate protocol failure");
    //    REQUIRE(airplane->getHeight() == 0, "GateProtocol failure");
    void completeGateProtocol(Airplane* airplane, std::ostream & out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling takeOffSequence()");
    //    REQUIRE(airplane->getStatus() == Departure, "Departure failure");
    //    REQUIRE(isAirplaneInRunway(airplane), "Airplane isn't on a runway");
    //    ENSURE(!isAirplaneInRunway(airplane), "Take off failure");
    //    ENSURE(airplane->getStatus() == InTheAir, "Take off failure");
    void takeOffSequence(Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised");
    //    REQUIRE(airplane->getFuel() == 0, "Fuel isn't empty");
    //    REQUIRE(airplane->getStatus() == Approaching ||airplane->getStatus() == EmergencyLanding||
    //      airplane->getStatus() == EmergencyControle1|| airplane->getStatus() == EmergencyControle2 ||
    //      airplane->getStatus() == EmergencyControle2 || airplane->getStatus() == JustLanded, "Must be in the air or just landed");
    //    ENSURE(airplane->getStatus() == EmergencyLandingOutside, "Emergencylanding outside failure");
    //    ENSURE(isAirplaneInRunway(airplane), "Emergency landing failure");
    void emergencySequence(Airplane* airplane, std::ostream& out);

    //    REQUIRE(this->properlyInitialised(), "Not properly initialised");
    vector<Gate *> &getGates();
    //    REQUIRE(this->properlyInitialised(), "Not properly initialised");
    bool isAirplaneRemovedFromGate(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Not properly initialised");
    bool isAirplaneRemovedFromRunway(Airplane* airplane);
    //    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised");
    const vector<Airplane *> &getRunwayWait();
};
#endif //PSE_AIRPORT_H