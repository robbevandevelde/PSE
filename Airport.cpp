//
// Created by uauser on 4/23/18.
//

#include "Gate.h"
#include "Runway.h"
#include "DesignByContract.h"
#include "Airport.h"

Airport::Airport(unsigned int gatesize, const std::string &name,
                 const std::string &iata, const std::string &callsign) : gatesize(gatesize), name(name),
                                                                         iata(iata), callsign(callsign) {
    _initcheck = this;
    amountRunways = 0;

    waitpoint1 = NULL;
    waitpoint2 = NULL;
    controller = NULL;

    for(unsigned int x = 0;x < Airport::gatesize;x++){
        Gate* gate = new Gate(x+1);
        gates.push_back(gate);
    }
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(gates.size() == gatesize, "Gates has to be initialised correctly");
    ENSURE(waitpoint1 == NULL && waitpoint2 == NULL && controller == NULL, "Values must point to NULL");
    ENSURE(amountRunways == 0, "Amount of runways must be zero");
}

bool Airport::properlyInitialised() {
    return _initcheck == this;
}
void Airport::TakeOffprotocol(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling TakeOffProtocol");
    REQUIRE(airplane->get_height() == 0, "Airplane must be on the ground");

    unsigned int preheight = airplane->get_height();

    while(airplane->get_height() < 5000){
        unsigned int postheight =  airplane->get_height() + 1000;
        std::cout << airplane->get_callsign() <<  " ascended to " << postheight << " ft. " << std::endl;
        airplane->set_height(postheight);
        ENSURE(preheight < postheight,"Take off failure");
    }
    removeAirplaneOfRunway(airplane);
    airplane->set_status(Approaching);
    airplane->set_height(10000);
    std::cout << airplane->get_callsign() << " has left " << name << std::endl;
}

void Airport::Landingprotocol(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Airpower wasn't properly initialised when calling Landingprotocol");
    REQUIRE(airplane->get_status() == Approaching, "Airplane must be approaching in order to land");
    unsigned int preheight = airplane->get_height();

    while(airplane->get_height() > 10000){
        unsigned int postheight = airplane->get_height() - 1000;
        airplane->set_height(postheight);
        ENSURE(preheight > postheight, "Descending failure");
    }
    ENSURE(airplane->get_height() == 10000, "Airplane must be at 10000 ft in order to land");

    std::cout << airplane->get_callsign() << " is approaching " << name << " at " << airplane->get_height() << " ft. "<< std::endl;
    while(airplane->get_height() > 1000){
        airplane->set_height(airplane->get_height() - 1000);
        std::cout<< airplane->get_callsign() << " descended to " << airplane->get_height() << std::endl;
    }

    ENSURE(airplane->get_height() == 1000, "Airplane must be at 1000 ft");
}

void Airport::completeLandingSequence(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling completeLandingSequence()");

    Landingprotocol(airplane);
    addAirplaneToRunway(airplane);
    gateprotocol(airplane,0);
    TaxiToGate(airplane);
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}

void Airport::completeTakeOffsequence(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling completeTakeOffsequence()");

    TaxiToRunway(airplane);

    TakeOffprotocol(airplane);

    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}


void Airport::gateprotocol(Airplane *airplane, unsigned int passengers) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling gateprotocol()");
    REQUIRE(airplane->get_height() == 0 , "Airplane must be on the ground");
    if(airplane->get_status() == JustLanded) {
        for(unsigned int x = 0; x < runways.size();x++){
            if(runways[x]->get_airplane() == airplane){
                std::cout << airplane->get_passengers() << " exited " << airplane->get_callsign() << " at Gate " <<
                          runways[x]->get_name() << " of " << name << std::endl;
                airplane->set_passengers(0);
                ENSURE(airplane->get_passengers() == 0, "Passenger exit failure");
                std::cout<< airplane->get_callsign() << " has been checked for technical malfunctions " << std::endl;
                break;
            }
        }
    } else if(airplane->get_status() == Departure) {
        for(unsigned int x = 0; x < gates.size(); x++){
            if(gates[x]->get_airplane() == airplane){
                std::cout << airplane->get_callsign() << " has been refueled" << std::endl;
                gates[x]->get_airplane()->set_passengers(passengers);
                std::cout << passengers << " boarded " << airplane->get_callsign() << " at Gate " <<
                          gates[x]->get_name() << " of " << name << std::endl;
            }
        }
    }
}

void Airport::addAirplaneToGate(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToGate()");
    REQUIRE(airplane->get_status() == JustLanded, "Airplane has to be standing at the runway in order to taxi");
    REQUIRE(gates.size() <= gatesize, "Amount of gates don't match with the given amount of gates");

    for(unsigned int x = 0; x < gates.size();x++){
        if(!gates[x]->is_occupied()){
            std::cout << airplane->get_callsign() << " is taxiing to Gate " << gates[x]->get_name()<< std::endl;
            gates[x]->addAirplane(airplane);
            ENSURE(gates[x]->get_airplane()->get_model() == airplane->get_model() &&
                   gates[x]->get_airplane()->get_number() == airplane->get_number() &&
                   gates[x]->get_airplane()->get_callsign() == airplane->get_callsign(),
                   "Airplane in gate doesn't match added airplane");
            ENSURE(gates[x]->get_airplane()->get_status() == StandingAtGate, "Airplane's status isn't standing at gate");
            std::cout << airplane ->get_callsign() << " is standing at Gate " << gates[x]->get_name() << std::endl;
            break;
        }
    }
}

void Airport::addAirplaneToRunway(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    for(unsigned int x = 0; x < runways.size(); x++){
        if(!runways[x]->is_status()){
            if(airplane->get_status() == Approaching){
                std::cout << airplane->get_callsign() << " is landing at " << name << " on runway "
                          << runways[x]->get_name()  << std::endl;

                airplane->set_status(JustLanded);
                runways[x]->addAirplane(airplane);

                std::cout << airplane->get_callsign() << " has landed at " << name << " on runway "
                          << runways[x]->get_name()  << std::endl;
                ENSURE(runways[x]->get_airplane()->get_status() == JustLanded, "Add airplane to runway failure");
            } else if(airplane->get_status() == Departure){

                std::cout << airplane->get_callsign() << " is taxiing to runway " << runways[x]->get_name() <<
                          std::endl;
                airplane->set_status(JustLanded);
                runways[x]->addAirplane(airplane);
                std::cout << airplane->get_callsign() << " is taxiing to runway " << name << " on runway " <<
                          runways[x]->get_name() <<std::endl;
            }
            ENSURE(runways[x]->get_airplane()->get_model() == airplane->get_model() &&
                   runways[x]->get_airplane()->get_number() == airplane->get_number() &&
                   runways[x]->get_airplane()->get_callsign() == airplane->get_callsign(),
                   "Add airplane to runway failure");
            break;
        }
    }
}

void Airport::removeAirplaneOfGate(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling removeAirplaneOfGate()");
    for(unsigned int x = 0; x < gates.size();x++){
        if(gates[x]->get_airplane()->get_model() == airplane->get_model() &&
           gates[x]->get_airplane()->get_number() == airplane->get_number() &&
           gates[x]->get_airplane()->get_callsign() == airplane->get_callsign()){
            std::cout << airplane->get_callsign() << " is standing at Gate " << gates[x]->get_name() << std::endl;
            gates[x]->get_airplane()->set_status(Departure);
            gateprotocol(gates[x]->get_airplane(),5);
            gates[x]->removeAirplane();
            ENSURE(gates[x]->get_airplane() == NULL,"Remove airplane of gate failure");
            break;
        }
    }
}

void Airport::removeAirplaneOfRunway(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling removeAirplaneOfFrumway()");
    for(unsigned int x = 0; x < runways.size(); x++) {
        if(runways[x]->get_airplane()->get_model() == airplane->get_model() &&
           runways[x]->get_airplane()->get_number() == airplane->get_number() &&
           runways[x]->get_airplane()->get_callsign() == airplane->get_callsign()){
            runways[x]->removeAirplane();
            ENSURE(runways[x]->get_airplane() == NULL, "Remove airplane of runway failure");
        }
    }
}

const std::string &Airport::getName(){
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return name;
}

void Airport::setName(const std::string &_name) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    Airport::name = _name;
}

const std::string &Airport::getIata(){
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return iata;
}

void Airport::setIata(const std::string &_iata) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    Airport::iata = _iata;
}

const std::string &Airport::getCallsign(){
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return callsign;
}

void Airport::setCallsign(const std::string &_callsign) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    Airport::callsign = _callsign;
}

unsigned int Airport::getGatesize() {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize");
    return gatesize;
}

void Airport::setGatesize(unsigned int _gatesize) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setGatesize");
    Airport::gatesize = _gatesize;
}

void Airport::addRunway(Runway *runway) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunway");
    runways.push_back(runway);
    amountRunways+=1;

}

void Airport::TaxiToRunway(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling TaxiToRunway");
    removeAirplaneOfGate(airplane);
    addAirplaneToRunway(airplane);
}

void Airport::TaxiToGate(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling TaxiToGate");
    removeAirplaneOfRunway(airplane);
    addAirplaneToGate(airplane);
}

bool Airport::isRunwayEmpty() {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isRunwayEmpty");
    for(unsigned int x = 0; x < runways.size(); x++){
        if(!runways[x]->is_status()){
            return true;
        }
    }
    return false;
}

Airplane *Airport::getWaitpoint1() const {
    return waitpoint1;
}

void Airport::setWaitpoint1(Airplane *waitpoint1) {
    Airport::waitpoint1 = waitpoint1;
}

Airplane *Airport::getWaitpoint2() const {
    return waitpoint2;
}

void Airport::setWaitpoint2(Airplane *waitpoint2) {
    Airport::waitpoint2 = waitpoint2;
}

void Airport::assignController(AirTrafficController *_controller) {
    Airport::controller = _controller;
}

void Airport::removeWaitpoint1() {
    setWaitpoint1(NULL);
}

void Airport::removeWaitpoint2() {
    setWaitpoint2(NULL);
}

