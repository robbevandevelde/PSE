//
// Created by uauser on 4/23/18.
//

#include "Gate.h"
#include "Runway.h"
#include "DesignByContract.h"
#include "Airport.h"

Airport::Airport(unsigned int gatesize, const std::string &name,
                 const std::string &iata, const std::string &callsign) : _gatesize(gatesize), _name(name),
                                                                         _iata(iata), _callsign(callsign)
{
    _initcheck = this;
    _amountRunways = 0;

    _waitpoint1 = NULL;
    _waitpoint2 = NULL;
    _controller = NULL;

    for(unsigned int x = 0;x < Airport::_gatesize;x++){
        Gate* gate = new Gate(x+1);
        _gates.push_back(gate);
    }
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_gates.size() == _gatesize, "Gates has to be initialised correctly");
    ENSURE(_waitpoint1 == NULL && _waitpoint2 == NULL && _controller == NULL, "Values must point to NULL");
    ENSURE(_amountRunways == 0, "Amount of runways must be zero");
}

bool Airport::properlyInitialised()
{
    return _initcheck == this;
}
void Airport::TakeOffprotocol(Airplane *airplane)
{
    REQUIRE(airplane->getStatus() == Departure, "Airplane must be departure");
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling TakeOffProtocol");
    REQUIRE(airplane->getHeight() == 0, "Airplane must be on the ground");

    unsigned int preheight = airplane->getHeight();

    while(airplane->getHeight() < 5000){
        unsigned int postheight = airplane->getHeight() + 1000;
        std::cout << airplane->getCallsign() <<  " ascended to " << postheight << " ft. " << std::endl;
        airplane->setHeight(postheight);
        ENSURE(preheight < postheight,"Take off failure");
    }
    removeAirplaneOfRunway(airplane);
    airplane->setStatus(Approaching);
    airplane->setHeight(10000);
    std::cout << airplane->getCallsign() << " has left " << _name << std::endl;
}

void Airport::Landingprotocol(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airpower wasn't properly initialised when calling Landingprotocol");
    REQUIRE(airplane->getStatus() == Approaching, "Airplane must be approaching in order to land");
    unsigned int preheight = airplane->getHeight();

    while(airplane->getHeight() > 10000){
        unsigned int postheight = airplane->getHeight() - 1000;
        airplane->setHeight(postheight);
        ENSURE(preheight > postheight, "Descending failure");
    }
    ENSURE(airplane->getHeight() == 10000, "Airplane must be at 10000 ft in order to land");

    std::cout << airplane->getCallsign() << " is approaching " << _name << " at " << airplane->getHeight() << " ft. "<< std::endl;
    while(airplane->getHeight() > 1000){
        _controller->landingprotocol(airplane);
        airplane->setHeight(airplane->getHeight() - 1000);
        std::cout<< airplane->getCallsign() << " descended to " << airplane->getHeight() << std::endl;
    }
    airplane->setStatus(FinalApproach);
    ENSURE(airplane->getStatus() == FinalApproach, "Landing failure");
    ENSURE(airplane->getHeight() == 1000, "Airplane must be at 1000 ft");
}

void Airport::completeLandingSequence(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling completeLandingSequence()");

    Landingprotocol(airplane);
    addAirplaneToRunway(airplane);
    TaxiToGate(airplane);
    gateprotocol(airplane,0);
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}

void Airport::completeTakeOffsequence(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling completeTakeOffsequence()");
    gateprotocol(airplane,5);
    TaxiToRunway(airplane);

    TakeOffprotocol(airplane);

    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}


void Airport::gateprotocol(Airplane *airplane, unsigned int passengers)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling gateprotocol()");
    REQUIRE(airplane->getHeight() == 0 , "Airplane must be on the ground");
    if(airplane->getStatus() == JustLanded) {
        for(unsigned int x = 0; x < _gates.size();x++){
            if(_gates[x]->getAirplane() == airplane){
                std::cout << airplane->getPassengers() << " exited " << airplane->getCallsign() << " at Gate " <<
                                                                                                               _gates[x]->getName() << " of " << _name << std::endl;
                airplane->setPassengers(0);
                ENSURE(airplane->getPassengers() == 0, "Passenger exit failure");
                std::cout<< airplane->getCallsign() << " has been checked for technical malfunctions " << std::endl;
                airplane->setStatus(StandingAtGate);
                ENSURE(airplane->getStatus() == StandingAtGate, "Failire");
                break;
            }
        }
    } else if(airplane->getStatus() == StandingAtGate) {
        for(unsigned int x = 0; x < _gates.size(); x++){
            if(_gates[x]->getAirplane() == airplane){
                std::cout << airplane->getCallsign() << " has been refueled" << std::endl;
                _gates[x]->getAirplane()->setPassengers(passengers);
                std::cout << passengers << " boarded " << airplane->getCallsign() << " at Gate " <<
                                                                                                 _gates[x]->getName() << " of " << _name << std::endl;
            }
        }
    }
}

void Airport::addAirplaneToGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling addAirplaneToGate()");
    REQUIRE(airplane->getStatus() == JustLanded, "Airplane has to be standing at the runway in order to taxi");
    REQUIRE(_gates.size() <= _gatesize, "Amount of gates don't match with the given amount of gates");

    for(unsigned int x = 0; x < _gates.size();x++){
        if(!_gates[x]->isOccupied()){
            std::cout << airplane->getCallsign() << " is taxiing to Gate " << _gates[x]->getName()<< std::endl;
            _gates[x]->addAirplane(airplane);
            ENSURE(_gates[x]->getAirplane()->getModel() == airplane->getModel() &&
                           _gates[x]->getAirplane()->getNumber() == airplane->getNumber() &&
                           _gates[x]->getAirplane()->getCallsign() == airplane->getCallsign(),
                   "Airplane in gate doesn't match added airplane");
            std::cout << airplane->getCallsign() << " is standing at Gate " << _gates[x]->getName() << std::endl;
            break;
        }
    }
}

void Airport::addAirplaneToRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if(!_runways[x]->isStatus()){
            if(airplane->getStatus() == FinalApproach){
                std::cout << airplane->getCallsign() << " is landing at " << _name << " on runway "
                          << _runways[x]->getName()  << std::endl;

                airplane->setStatus(JustLanded);
                _runways[x]->addAirplane(airplane);
                _controller->landingprotocol(airplane);
                std::cout << airplane->getCallsign() << " has landed at " << _name << " on runway "
                          << _runways[x]->getName()  << std::endl;
                ENSURE(_runways[x]->getAirplane()->getStatus() == JustLanded, "Add airplane to runway failure");
            } else if(airplane->getStatus() == Departure){
                std::cout << airplane->getCallsign() << " is taxiing to runway " << _runways[x]->getName() <<
                          std::endl;
                _runways[x]->addAirplane(airplane);
                std::cout << airplane->getCallsign() << " is taxiing to runway " << _name << " on runway " <<
                                                                                                           _runways[x]->getName() <<std::endl;
            }
            ENSURE(_runways[x]->getAirplane()->getModel() == airplane->getModel() &&
                           _runways[x]->getAirplane()->getNumber() == airplane->getNumber() &&
                           _runways[x]->getAirplane()->getCallsign() == airplane->getCallsign(),
                   "Add airplane to runway failure");
            break;
        }
    }
}

void Airport::removeAirplaneOfGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfGate()");
    for(unsigned int x = 0; x < _gates.size();x++){
        if(_gates[x]->getAirplane()->getModel() == airplane->getModel() &&
                _gates[x]->getAirplane()->getNumber() == airplane->getNumber() &&
                _gates[x]->getAirplane()->getCallsign() == airplane->getCallsign()){
            std::cout << airplane->getCallsign() << " is standing at Gate " << _gates[x]->getName() << std::endl;
            _gates[x]->getAirplane()->setStatus(Departure);
            _gates[x]->removeAirplane();
            ENSURE(_gates[x]->getAirplane() == NULL,"Remove airplane of gate failure");
            break;
        }
    }
}

void Airport::removeAirplaneOfRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfFrumway()");
    for(unsigned int x = 0; x < _runways.size(); x++) {
        if(_runways[x]->getAirplane()->getModel() == airplane->getModel() &&
                _runways[x]->getAirplane()->getNumber() == airplane->getNumber() &&
                _runways[x]->getAirplane()->getCallsign() == airplane->getCallsign()){
            _runways[x]->removeAirplane();
            ENSURE(_runways[x]->getAirplane() == NULL, "Remove airplane of runway failure");
        }
    }
}

const std::string &Airport::getName()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return _name;
}

void Airport::setName(const std::string &_name)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    Airport::_name = _name;
    ENSURE(getName() == _name, "setName() failure");
}

const std::string &Airport::getIata()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return _iata;
}

void Airport::setIata(const std::string &_iata)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    Airport::_iata = _iata;
    ENSURE(getIata() == _iata, "setIata() failure");
}

const std::string &Airport::getCallsign()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return _callsign;
}

void Airport::setCallsign(const std::string &_callsign)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    Airport::_callsign = _callsign;
    ENSURE(getCallsign() == _callsign, "setCallsign() failure");
}

unsigned int Airport::getGatesize()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return _gatesize;
}

void Airport::setGatesize(unsigned int _gatesize)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setGatesize");
    Airport::_gatesize = _gatesize;
    ENSURE(getGatesize() == _gatesize, "setGatesize() failure");
}

void Airport::addRunway(Runway *runway)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunway");
    _runways.push_back(runway);
    _amountRunways+=1;
    ENSURE(_runways[_runways.size() -1] == runway, "addRunway failure");
}

void Airport::TaxiToRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling TaxiToRunway");
    removeAirplaneOfGate(airplane);
    addAirplaneToRunway(airplane);
}

void Airport::TaxiToGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling TaxiToGate");
    removeAirplaneOfRunway(airplane);
    addAirplaneToGate(airplane);
}

bool Airport::isRunwayEmpty()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isRunwayEmpty");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if(!_runways[x]->isStatus()){
            return true;
        }
    }
    return false;
}

Airplane *Airport::getWaitpoint1()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint1()");

    return _waitpoint1;
}

void Airport::setWaitpoint1(Airplane *waitpoint1)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint1()");
    Airport::_waitpoint1 = waitpoint1;
    ENSURE(getWaitpoint1() == waitpoint1, "setWaitpoint1() failure");
}

Airplane *Airport::getWaitpoint2()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint2()");
    return _waitpoint2;
}

void Airport::setWaitpoint2(Airplane *waitpoint2)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint2()");
    Airport::_waitpoint2 = waitpoint2;
    ENSURE(getWaitpoint2() == waitpoint2, "setWaitpoint2() failure");
}

void Airport::assignController(AirTrafficController *_controller)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling assignController()");
    Airport::_controller = _controller;
    ENSURE(getController() == _controller, "assignController() failure");
}

void Airport::removeWaitpoint1()
{
    setWaitpoint1(NULL);
    ENSURE(_waitpoint1 == NULL, "removeWaitpoint1() failure");
}

void Airport::removeWaitpoint2()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint2()");
    setWaitpoint2(NULL);
    ENSURE(_waitpoint2 == NULL, "removeWaitpoint2() failure");
}

unsigned int Airport::getAmountRunways()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getAmountRunways()");
    return _amountRunways;
}

AirTrafficController *Airport::getController()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getController()");
    return _controller;
}

