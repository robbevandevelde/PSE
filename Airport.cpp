//
// Created by uauser on 4/23/18.
//

#include "Gate.h"
#include "Runway.h"
#include "DesignByContract.h"
#include "Airport.h"

Airport::Airport(unsigned int gatesize, const std::string &name,
                 const std::string &iata, const std::string &callsign) : _gatesize(gatesize), _name(name),
                                                                         _iata(iata), _callsign(callsign) {
    _initcheck = this;

    for(unsigned int x = 0;x < Airport::_gatesize;x++){
        Gate* gate = new Gate(x+1);
        _gates.push_back(gate);
    }
    for(unsigned int x = 0; x < Airport::_amountRunways;x++){
        Runway* runway = new Runway(400,"moo","R11",_name);
        _runways.push_back(runway);
    }
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(_runways.size() == _amountRunways, "Runways has to be initialised correctly");
    ENSURE(_gates.size() == _gatesize, "Gates has to be initialised correctly");
}

bool Airport::properlyInitialised() {
    return _initcheck == this;
}

void Airport::landingprotocol(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling landingprotocol()");
    REQUIRE(airplane->get_status() == Approaching, "Airplane must be approaching in order to land");
    unsigned int preheight = airplane->get_height();

    while(airplane->get_height() > 10000){
        unsigned int postheight = airplane->get_height() - 1000;
        airplane->set_height(postheight);
        ENSURE(preheight > postheight, "Descending failure");
    }
    ENSURE(airplane->get_height() == 10000, "Airplane must be at 10000 ft in order to land");

    std::cout << airplane->get_callsign() << " is approaching " << _name << " at " << airplane->get_height() << std::endl;
    while(airplane->get_height() > 1000){
        airplane->set_height(airplane->get_height() - 1000);
        std::cout<< airplane->get_callsign() << " descended to " << airplane->get_height() << std::endl;
    }

    ENSURE(airplane->get_height() == 1000, "Airplane must be at 1000 ft");

    addAirplaneToRunway(airplane);
    gateprotocol(airplane,0);
    addAirplaneToGate(airplane);
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}


void Airport::gateprotocol(Airplane *airplane, unsigned int passengers) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling gateprotocol()");
    REQUIRE(airplane->get_height() == 0 , "Airplane must be on the ground");
    if(airplane->get_status() == JustLanded) {
        for(unsigned int x = 0; x < _runways.size();x++){
            if(_runways[x]->get_airplane() == airplane){
                std::cout << airplane->get_passengers() << " exited " << airplane->get_callsign() << " at Gate " <<
                          _runways[x]->get_name() << " of " << _name << std::endl;
                airplane->set_passengers(0);
                ENSURE(airplane->get_passengers() == 0, "Passenger exit failure");
                std::cout<< airplane->get_callsign() << " has been chacked for technical malfunctions " << std::endl;
                break;
            }
        }
    } else if(airplane->get_status() == Departure) {
        for(unsigned int x = 0; x < _gates.size(); x++){
            if(_gates[x]->get_airplane() == airplane){
                std::cout << airplane->get_callsign() << " has been refueled" << std::endl;
                _gates[x]->get_airplane()->set_passengers(passengers);
                std::cout << passengers << " boarded " << airplane->get_callsign() << " at Gate " <<
                          _gates[x]->get_name() << " of " << _name << std::endl;
            }
        }
    }
}
void Airport::takeoffprotocol(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling takeoffprotocol()");
    REQUIRE(airplane->get_status() == StandingAtGate, "Airplane must be at gate");
    REQUIRE(airplane->get_height() == 0, "Airplane must be on the ground");

    removeAirplaneOfGate(airplane);
    addAirplaneToRunway(airplane);
    unsigned int preheight = airplane->get_height();

    while(airplane->get_height() < 5000){
        unsigned int postheight =  airplane->get_height() + 1000;
        std::cout << airplane->get_callsign() <<  " ascended to " << postheight << " ft. " << std::endl;
        airplane->set_height(postheight);
        ENSURE(preheight < postheight,"Taking off failure");
    }
    removeAirplaneOfRunway(airplane);
    airplane->set_status(Approaching);
    airplane->set_height(10000);
    std::cout << airplane->get_callsign() << " has left " << _name << std::endl;
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}


void Airport::addAirplaneToGate(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToGate()");
    REQUIRE(airplane->get_status() == JustLanded, "Airplane has to be standing at the runway in order to taxi");
    REQUIRE(_gates.size() <= _gatesize, "Amount of gates don't match with the given amount of gates");

    removeAirplaneOfRunway(airplane);

    for(unsigned int x = 0; x < _gates.size();x++){
        if(!_gates[x]->is_occupied()){
            std::cout << airplane->get_callsign() << " is taxiing to Gate " << _gates[x]->get_name()<< std::endl;
            _gates[x]->addAirplane(airplane);
            ENSURE(_gates[x]->get_airplane()->get_model() == airplane->get_model() &&
                   _gates[x]->get_airplane()->get_number() == airplane->get_number() &&
                   _gates[x]->get_airplane()->get_callsign() == airplane->get_callsign(),
                   "Airplane in gate doesn't match added airplane");
            ENSURE(_gates[x]->get_airplane()->get_status() == StandingAtGate, "Airplane's status isn't standing at gate");
            std::cout << airplane ->get_callsign() << " is standing at Gate " << _gates[x]->get_name() << std::endl;
            break;
        }
    }
}

void Airport::addAirplaneToRunway(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    REQUIRE(_runways.size() == _amountRunways, "Amount of runways don't match with the given amount of runways");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if(!_runways[x]->is_status()){
            if(airplane->get_status() == Approaching){
                std::cout << airplane->get_callsign() << " is landing at " << _name << " on runway "
                          << _runways[x]->get_name()  << std::endl;

                airplane->set_status(JustLanded);
                _runways[x]->addAirplane(airplane);

                std::cout << airplane->get_callsign() << " has landed at " << _name << " on runway "
                          << _runways[x]->get_name()  << std::endl;
                ENSURE(_runways[x]->get_airplane()->get_status() == JustLanded, "Add airplane to runway failure");
            } else if(airplane->get_status() == Departure){

                std::cout << airplane->get_callsign() << " is taxiing to runway " << _runways[x]->get_name() <<
                          std::endl;
                airplane->set_status(JustLanded);
                _runways[x]->addAirplane(airplane);
                std::cout << airplane->get_callsign() << " is taxiing to runway " << _name << " on runway " <<
                          _runways[x]->get_name() <<std::endl;
            }
            ENSURE(_runways[x]->get_airplane()->get_model() == airplane->get_model() &&
                   _runways[x]->get_airplane()->get_number() == airplane->get_number() &&
                   _runways[x]->get_airplane()->get_callsign() == airplane->get_callsign(),
                   "Add airplane to runway failure");
            break;
        }
    }
}

void Airport::removeAirplaneOfGate(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling removeAirplaneOfGate()");
    for(unsigned int x = 0; x < _gates.size();x++){
        if(_gates[x]->get_airplane()->get_model() == airplane->get_model() &&
           _gates[x]->get_airplane()->get_number() == airplane->get_number() &&
           _gates[x]->get_airplane()->get_callsign() == airplane->get_callsign()){
            std::cout << airplane->get_callsign() << " is standing at Gate " << _gates[x]->get_name() << std::endl;
            _gates[x]->get_airplane()->set_status(Departure);
            gateprotocol(_gates[x]->get_airplane(),5);
            _gates[x]->removeAirplane();
            ENSURE(_gates[x]->get_airplane() == NULL,"Remove airplane of gate failure");
            break;
        }
    }
}

void Airport::removeAirplaneOfRunway(Airplane *airplane) {
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling removeAirplaneOfFrumway()");
    for(unsigned int x = 0; x < _runways.size(); x++) {
        if(_runways[x]->get_airplane()->get_model() == airplane->get_model() &&
           _runways[x]->get_airplane()->get_number() == airplane->get_number() &&
           _runways[x]->get_airplane()->get_callsign() == airplane->get_callsign()){
            _runways[x]->removeAirplane();
            ENSURE(_runways[x]->get_airplane() == NULL, "Remove airplane of runway failure");
        }
    }
}

const std::string &Airport::get_name() const {
    return _name;
}

void Airport::set_name(const std::string &_name) {
    Airport::_name = _name;
}

const std::string &Airport::get_iata() const {
    return _iata;
}

void Airport::set_iata(const std::string &_iata) {
    Airport::_iata = _iata;
}

const std::string &Airport::get_callsign() const {
    return _callsign;
}

void Airport::set_callsign(const std::string &_callsign) {
    Airport::_callsign = _callsign;
}

unsigned int Airport::get_gatesize() const {
    return _gatesize;
}

void Airport::set_gatesize(unsigned int _gatesize) {
    Airport::_gatesize = _gatesize;
}

void Airport::addRunway(Runway *runway) {
    _runways.push_back(runway);
    _amountRunways+=1;

}
