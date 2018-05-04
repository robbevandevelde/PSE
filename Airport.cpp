//
// Created by uauser on 4/23/18.
//

#include "Gate.h"
#include "Runway.h"
#include "DesignByContract.h"
#include "Airport.h"

/*Constructor van de airport
 *@param unsigned int gatesize, string name, string iata, string callsign
 *@return geen
 */
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
    ENSURE(getGatesize() == gatesize && getName() == name && getIata() == iata && getCallsign() == callsign, "Constructor failure");
}

/*initchecker voor airport
 *@param geen
 *@return bool
 */
bool Airport::properlyInitialised()
{
    return _initcheck == this;
}

/*complete landing sequence voor een vliegtuig
 *@param Airplane* airplane
 *@return geen
 */
void Airport::completeLandingSequence(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling completeLandingSequence()");

    Landingprotocol(airplane);
    addAirplaneToRunway(airplane);
    TaxiToGate(airplane);
    gateprotocol(airplane,0);
    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}

/*Landing protocol voor een vliegtuig
*@param Airplane* airplane
*@return niks
*/
void Airport::Landingprotocol(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airpower wasn't properly initialised when calling Landingprotocol");
    REQUIRE(airplane->getStatus() == Approaching, "Airplane must be approaching in order to land");

    std::cout << airplane->getCallsign() << " is approaching " << _name << " at " << airplane->getHeight() << " ft. "<< std::endl;
    while(airplane->getHeight() > 1000){
        _controller->landingprotocol(airplane);
        airplane->descend();
    }
    airplane->setStatus(FinalApproach);
    airplane->setHeight(0);
    ENSURE(airplane->getStatus() == FinalApproach, "Landing failure");
    ENSURE(airplane->getHeight() == 0, "Airplane must be at 0 ft");
}

/*Doet 3 dingen: 1)Laat passagiers opstappen en technische controle 2)bijtanken 3)Passagiers opstappen
 *@param Airplane* airplane, unsigned int passengers
 *@return niks
 */
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
                std::cout<< airplane->getCallsign() << " has been checked for technical malfunctions " << std::endl;
                airplane->setStatus(StandingAtGate);
                ENSURE(airplane->getPassengers() == 0, "Passenger exit failure");
                ENSURE(airplane->getStatus() == StandingAtGate, "Failire");
                break;
            }
        }
    } else if(airplane->getStatus() == StandingAtGate) {
        for(unsigned int x = 0; x < _gates.size(); x++){
            if(_gates[x]->getAirplane() == airplane){
                if(!airplane->isFueled()){
                    std::cout << airplane->getCallsign() << " has been refueled" << std::endl;
                    airplane->setFuel(1000);
                    airplane->setFueled(true);
                    ENSURE(airplane->getFuel() == 1000, "Airplane hasn't been fueled");
                    ENSURE(airplane->isFueled(), "Airplane should be fueled");
                } else{
                    _gates[x]->getAirplane()->setPassengers(passengers);
                    std::cout << passengers << " boarded " << airplane->getCallsign() << " at Gate " <<
                              _gates[x]->getName() << " of " << _name << std::endl;
                    ENSURE(airplane->getPassengers() == passengers, "Boarded passengers don't match with given amount");
                }
                break;
            }
        }
    }
}

/*complete take off sequence van een vliegtuig
 *@param Airplane* airplane
 *@return niks
 */
void Airport::completeTakeOffsequence(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling completeTakeOffsequence()");
    gateprotocol(airplane,5);
    TaxiToRunway(airplane);
    TakeOffprotocol(airplane);

    std::cout << "---------------------------------------------------------------------------------------" << std::endl;
}

/*take off protocol voor een airplane
 *@param Airplane* airplane
 *@return niks
 */
void Airport::TakeOffprotocol(Airplane *airplane)
{
    REQUIRE(airplane->getStatus() == Departure, "Airplane must be departure");
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling TakeOffProtocol");
    REQUIRE(airplane->getHeight() == 0, "Airplane must be on the ground");
    for(unsigned int x = 0; x < _runways.size();x++){
        if(_runways[x]->getAirplane() == airplane){
            while(airplane->getHeight() < 5000){
                airplane->ascend();
            }
            removeAirplaneOfRunway(airplane);
            airplane->setStatus(InTheAir);
            std::cout << airplane->getCallsign() << " has left " << _name << std::endl;
            ENSURE(airplane->getStatus() == InTheAir, "TakeOff failure");
            ENSURE(_runways[x]->getAirplane() == NULL,"Take off failure");
        }
    }

}

/*Zoekt naar een lege niet gebruikte runway spot om geg vliegtuig aan toe te voegen
 *@param Airplane* airplane
 *@return niks
 */
void Airport::addAirplaneToRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if (airplane->getStatus() == Departure) {
            if (!_runways[x]->isOccupied()) {
                if (!_runways[x]->isGoingToBeUsed()) {
                    _controller->takeoffprotocol(airplane);
                    std::cout << airplane->getCallsign() << " is taxiing to runway " << _runways[x]->getName() <<
                              std::endl;
                    _runways[x]->addAirplane(airplane);
                    ENSURE(_runways[x]->getAirplane() == airplane, "addAirplaneToRunway() failure");
                    break;
                }
            }
        }
        else if(airplane->getStatus() == FinalApproach){
            if(!_runways[x]->isOccupied()) {
                if(_runways[x]->isGoingToBeUsed()) {
                    std::cout << airplane->getCallsign() << " is landing at " << _name << " on runway "
                              << _runways[x]->getName() << std::endl;

                    airplane->setStatus(JustLanded);
                    _runways[x]->addAirplane(airplane);
                    std::cout << airplane->getCallsign() << " has landed at " << _name << " on runway "
                              << _runways[x]->getName() << std::endl;
                    _controller->landingprotocol(airplane);
                    ENSURE(_runways[x]->getAirplane()->getStatus() == JustLanded, "Add airplane to runway failure");
                    ENSURE(_runways[x]->getAirplane() == airplane, "addAirplaneToRunway() failure");
                    break;
                }
            }
        }
    }
}

/*zoekt naar de geg vliegtuig in de runways en removed die
 *@param Airplane* airplane
 *@return niks
 */
void Airport::removeAirplaneOfRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfFrumway()");
    for(unsigned int x = 0; x < _runways.size(); x++) {
        if(_runways[x]->getAirplane() == airplane){
            _runways[x]->removeAirplane();
            ENSURE(_runways[x]->getAirplane() == NULL, "Remove airplane of runway failure");
            break;
        }
    }
}

/*zoekt naar een empty gate spot en add de geg vliegtuig aan deze spot
 *@param Airplane* airplane
 *@return geen
 */
void Airport::addAirplaneToGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling addAirplaneToGate()");
    REQUIRE(airplane->getStatus() == JustLanded, "Airplane has to be standing at the runway in order to taxi");
    REQUIRE(_gates.size() == _gatesize, "Amount of gates don't match with the given amount of gates");

    for(unsigned int x = 0; x < _gates.size();x++){
        if(!_gates[x]->isOccupied()){
            std::cout << airplane->getCallsign() << " is taxiing to Gate " << _gates[x]->getName()<< std::endl;
            _gates[x]->addAirplane(airplane);
            ENSURE(_gates[x]->getAirplane() == airplane, "Airplane in gate doesn't match added airplane");
            std::cout << airplane->getCallsign() << " is standing at Gate " << _gates[x]->getName() << std::endl;
            break;
        }
    }
}

/*zoekt naar de gegeven airplane in de gate en removed die
 *@param Airplane* airplane
 *@return geen
 */
void Airport::removeAirplaneOfGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfGate()");
    for(unsigned int x = 0; x < _gates.size();x++){
        if(_gates[x]->getAirplane() == airplane){
            std::cout << airplane->getCallsign() << " is standing at Gate " << _gates[x]->getName() << std::endl;
            _gates[x]->getAirplane()->setStatus(Departure);
            _gates[x]->removeAirplane();
            ENSURE(_gates[x]->getAirplane() == NULL,"Remove airplane of gate failure");
            break;
        }
    }
}

/*get de name van de airport
 *@param geen
 *@return string name
 */
const std::string &Airport::getName()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getName()");
    return _name;
}

/*set de name van de airport
 *@param string name
 *@return geen
 */
void Airport::setName(const std::string &_name)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setName()");
    Airport::_name = _name;
    ENSURE(getName() == _name, "setName() failure");
}

/*return de iata van de airport
 *@param geen
 *@return string iata
 */
const std::string &Airport::getIata()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getIata()");
    return _iata;
}

/*set de iata van de airport
 *@param string iata
 *@return geen
 */
void Airport::setIata(const std::string &_iata)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setIata()");
    Airport::_iata = _iata;
    ENSURE(getIata() == _iata, "setIata() failure");
}

/*return de callsign van de airport
 *@param geen
 *@return string callsign
 */
const std::string &Airport::getCallsign()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getCallsign()");
    return _callsign;
}

/*set de callsign van de airport
 *@param const string callsign
 *@return niks
 */
void Airport::setCallsign(const std::string &_callsign)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setCallsign()");
    Airport::_callsign = _callsign;
    ENSURE(getCallsign() == _callsign, "setCallsign() failure");
}

/*return de gatesize van de gates van airport
 *@param geen
 *@return unsigned int gatesize
 */
unsigned int Airport::getGatesize()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getGatesize()");
    return _gatesize;
}

/*set de gatesize van de airport
 *@param unsigned int gatesize
 *@return niks
 */
void Airport::setGatesize(unsigned int _gatesize)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setGatesize()");
    Airport::_gatesize = _gatesize;
    ENSURE(getGatesize() == _gatesize, "setGatesize() failure");
}

/*add de runway aan de runwayvector
 *@param Runway* runway
 *@return geen
 */
void Airport::addRunway(Runway *runway)
{
    REQUIRE(this->properlyInitialised(), "Airport wgetUsedasn't properly initialised when calling addRunway()");
    _runways.push_back(runway);
    _amountRunways+=1;
    ENSURE(_runways[_runways.size() -1] == runway, "addRunway failure");
}

/*remove gegeven airplane van een gate en add die aan een runway
 *@param Airplane* airplane
 *@return geen
 */
void Airport::TaxiToRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling TaxiToRunway()");
    removeAirplaneOfGate(airplane);
    addAirplaneToRunway(airplane);
}

/*remove geg airplane van runway en add die aan een gate
 *@param Airplane* airplane
 *@return geen
 */
void Airport::TaxiToGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling TaxiToGate()");
    removeAirplaneOfRunway(airplane);
    addAirplaneToGate(airplane);
}

/*checkt of dat er een runway niet gebruikt wordt
 *@param geen
 *@return true als waar, true als niet waar
 */
bool Airport::isRunwayEmpty()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isRunwayEmpty()");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if(!_runways[x]->isOccupied()){
            return true;
        }
    }
    return false;
}

/*return de vliegtuig op waitpoint1
 *@param geen
 *@return Airplane* waitpoint1
 */
Airplane *Airport::getWaitpoint1()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint1()");
    return _waitpoint1;
}

/*zet een airplane in waitpoint1
 *@param Airplane* waitpoint1
 *@return geen
 */
void Airport::setWaitpoint1(Airplane *waitpoint1)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint1()");
    Airport::_waitpoint1 = waitpoint1;
    ENSURE(getWaitpoint1() == waitpoint1, "setWaitpoint1() failure");
}

/*return de vliegtuig op waitpoint2
 *@param geen
 *@return Airplane* waitpoint2
 */
Airplane *Airport::getWaitpoint2()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getWaitpoint2()");
    return _waitpoint2;
}

/*zet een airplane in waitpoint2;
 *@param Airplane* waitpoint2
 *@return geen
 */
void Airport::setWaitpoint2(Airplane *waitpoint2)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling setWaitpoint2()");
    Airport::_waitpoint2 = waitpoint2;
    ENSURE(getWaitpoint2() == waitpoint2, "setWaitpoint2() failure");
}

/*assign de controller van airport
 *@param ATC* controller
 *@return geen
 */
void Airport::assignController(AirTrafficController *_controller)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling assignController()");
    Airport::_controller = _controller;
    ENSURE(getController() == _controller, "assignController() failure");
}

/*set waitpoint1 op null
 *@param geen
 *@return geen
 */
void Airport::removeWaitpoint1()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint1()");
    setWaitpoint1(NULL);
    ENSURE(_waitpoint1 == NULL, "removeWaitpoint1() failure");
}

/*set waitpoint2 op null
 *@param geen
 *@return geen
 */
void Airport::removeWaitpoint2()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint2()");
    setWaitpoint2(NULL);
    ENSURE(_waitpoint2 == NULL, "removeWaitpoint2() failure");
}

/*return de hoeveelheid runways
 *@param geen
 *@return int amountRunways
 */
unsigned int Airport::getAmountRunways()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getAmountRunways()");
    return _amountRunways;
}

/*returned de ATC van airport
 *@param geen
 *@return ATC* controller
 */
AirTrafficController *Airport::getController()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getController()");
    return _controller;
}

/*zoekt naar een lege plek op de runway
 *@param geen
 *@return integer freespot
 */
unsigned int Airport::getFreeRunwaySpot()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling getFreeRunwaySpot()");
    for(unsigned int x = 0; x < _runways.size();x++){
        if(!_runways[x]->isOccupied()){
            return x;
        }
    }
    //zou nooit gebeuren door andere functies
    return 1000;
}

/*return de runway vector
 *@param geen
 *@return vector<runway*> runway
 */
const vector<Runway *> &Airport::getRunways()
{
    REQUIRE(this->properlyInitialised(), "Airprort wasn't properly initialised when calling getRunways()");
    return _runways;
}

/*checkt of dat er een runway gaat worden gebruikt
 *@param geen
 *@return bool
 */
bool Airport::isRunwayNotUsed()
{
    REQUIRE(this->properlyInitialised(), "Airprort wasn't properly initialised when calling isRunwayNotUsed()");
    for(unsigned int x =0; x<_runways.size();x++){
        if(!_runways[x]->isGoingToBeUsed()){
            return  true;
        }
    }
    return false;
}

/*add gegeven airplane aan de wacht"straat"
 *@param Airplane* airplane
 *@return geen
 */
void Airport::addRunwayWait(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunwayWait()");
    _RunwayWait.push_back(airplane);
    ENSURE(RunwayWaitChecker(airplane), "add airplane to runwaywait failure");
}

/*removed gegeven airplane van de wacht"straat"
 *@param Airplane* airplane
 *@return geen
 */
void Airport::removeRunwayWait(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeRunwayWait()");
    for(unsigned int x = 0; x <_RunwayWait.size();x++){
        if(_RunwayWait[x] == airplane){
            _RunwayWait.erase(_RunwayWait.begin() + x);
            break;
        }
    }
}

/*Checkt of dat de gegeven airplane in de wacht"straat" is
 *@param Airplane* airplane
 *@return bool
 */
bool Airport::RunwayWaitChecker(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling RunWaitChecker()");
    for(unsigned int x = 0; x <_RunwayWait.size();x++){
        if(_RunwayWait[x] == airplane){
            return true;
        }
    }
    return false;
}
/*Ziet of dat er een runway gebruikt wordt, zo niet zet op gebruikt
 *@param geen
 *@return geen
 */
void Airport::goingToGetUsedRunway()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling goingToGetUsedRunway()");
    for(unsigned int x =0; x< _runways.size();x++){
        if(!_runways[x]->isGoingToBeUsed()){
            _runways[x]->setUsedStatus();
            break;
        }
    }
}
/*checkt of dat er een runway compleet vrij is
 *@param geen
 *@return bool true als waar, false als niet waar
 */
bool Airport::isRunwayCompletelyClear()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isRunwayCompletelyClear()");
    for(unsigned int x = 0;x <_runways.size();x++){
        if(!_runways[x]->isOccupied()){
            if(!_runways[x]->isGoingToBeUsed()){
                return true;
            }
        }
    }
    return false;
}
