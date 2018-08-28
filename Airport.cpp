//
// Created by uauser on 4/23/18.
//

#include "Gate.h"
#include "Runway.h"
#include "DesignByContract.h"
#include "Communication.h"
#include "Airport.h"

/** TO DO: ATC MEER MACHT GEVEN (Controles)
 *
 */

//TODO: NIET GEBRUIKTE FUNCTIES WEGHALEN
//TODO: WACHT SYSTEEM MET RUNWAYS AANPASSEN (OP DE RUNWAY ZELF IPV IN EEN WACHT VECTOR)


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
    _comm = new Communication();
    for(unsigned int x = 0;x < Airport::_gatesize;x++){
        Gate* gate = new Gate(x+1);
        _gates.push_back(gate);
    }
    ENSURE(properlyInitialised(), "Constructor must end");
    ENSURE(getGates().size() == _gatesize, "Gates has to be initialised correctly");
    ENSURE(getWaitpoint1() == NULL && getWaitpoint2() == NULL && _controller == NULL, "Values must point to NULL");
    ENSURE(getRunways().size() == 0, "Amount of runways must be zero");
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


/*Doet 3 dingen: 1)Laat passagiers opstappen en technische controle 2)bijtanken 3)Passagiers opstappen
 *@param Airplane* airplane, unsigned int passengers
 *@return niks
 */
void Airport::gateprotocol(Airplane *airplane, unsigned int passengers, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling gateprotocol()");
    REQUIRE(airplane->getStatus() == JustLanded || airplane->getStatus() == StandingAtGate, "Failure");
    REQUIRE(airplane->getHeight() == 0 , "Airplane must be on the ground");
    if(airplane->getStatus() == JustLanded) {
        for(unsigned int x = 0; x < _gates.size();x++){
            if(_gates[x]->getAirplane() == airplane){
                out << airplane->getPassengers() << " exited " << airplane->getCallsign() << " at Gate " <<
                          _gates[x]->getName() << " of " << _name << std::endl;
                airplane->setPassengers(0);
                out<< airplane->getCallsign() << " has been checked for technical malfunctions" << std::endl;
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
                    out << airplane->getCallsign() << " has been refueled" << std::endl;
                    airplane->setFuel(1000);
                    airplane->setFueled(true);
                    ENSURE(airplane->getFuel() == 1000, "Airplane hasn't been fueled");
                    ENSURE(airplane->isFueled(), "Airplane should be fueled");
                } else{
                    _gates[x]->getAirplane()->setPassengers(passengers);
                    out << passengers << " boarded " << airplane->getCallsign() << " at Gate " <<
                              _gates[x]->getName() << " of " << _name << std::endl;
                    out << "--------------------------------------------------------------------------" << std::endl;
                    ENSURE(airplane->getPassengers() == passengers, "Boarded passengers don't match with given amount");
                }
                break;
            }
        }
    }
}




/*Zoekt naar een lege niet gebruikte runway spot om geg vliegtuig aan toe te voegen
 *@param Airplane* airplane
 *@return niks
 */
void Airport::addAirplaneToRunway(Airplane *airplane, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't initialised when calling addAirplaneToRunway");
    REQUIRE(airplane->getStatus() == Departure|| airplane->getStatus() == FinalApproach || airplane->getStatus() == EmergencyLanding, "Invalid status for runway");
    REQUIRE(airplane->getHeight() == 0, "Airplane must be on the ground");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if (airplane->getStatus() == Departure) {
            if (!_runways[x]->isOccupied()) {
                if (!_runways[x]->isGoingToBeUsed()) {
                    if (validRunwayForPlane(airplane, _runways[x])) {
                        _comm->ATC_Airplane_Of_Gate_Comm(_controller,airplane, out);
                        out << airplane->getCallsign() << " is taxiing to runway " << _runways[x]->getName() <<
                            std::endl;
                        _runways[x]->setGoingtobeusedby(airplane);
                        _runways[x]->addAirplane(airplane);
                        ENSURE(isAirplaneInRunway(airplane), "addAirplaneToRunway() failure");
                        break;
                    }
                }
            }
        }
        else if(airplane->getStatus() == FinalApproach){
            if(!_runways[x]->isOccupied()) {
                if(_runways[x]->isGoingToBeUsed()) {
                    if (validRunwayForPlane(airplane, _runways[x])) {
                        if (_runways[x]->getGoingtobeusedby() == airplane) {
                            out << airplane->getCallsign() << " is landing at " << _name << " on runway "
                                << _runways[x]->getName() << std::endl;
                            out << "--------------------------------------------------------------------------" << std::endl;

                            airplane->setStatus(JustLanded);
                            _runways[x]->addAirplane(airplane);
                            out << airplane->getCallsign() << " has landed at " << _name << " on runway "
                                << _runways[x]->getName() << std::endl;
                            out << "--------------------------------------------------------------------------" << std::endl;
                            _controller->landingprotocol(airplane, out);

                            ENSURE(airplane->getStatus() == JustLanded,
                                   "Add airplane to runway failure");
                            ENSURE(isAirplaneInRunway(airplane), "addAirplaneToRunway() failure");
                            break;
                        }
                    }
                }
            }
        }
        else if(airplane->getStatus() == EmergencyLanding){
            if(_runways[x]->isGoingToBeUsed()) {
                if (validRunwayForPlane(airplane, _runways[x])) {
                    if (_runways[x]->getGoingtobeusedby() == airplane) {
                        out << airplane->getCallsign() << " is landing at " << _name << " on runway "
                            << _runways[x]->getName() << std::endl;
                        airplane->setStatus(EmergencyControle1);
                        _runways[x]->addAirplane(airplane);
                        out << airplane->getCallsign() << " has landed at " << _name << " on runway "
                            << _runways[x]->getName() << std::endl;
                        out << airplane->getCallsign() << " wait for an emergency controle" << std::endl;
                        ENSURE(airplane->getStatus() == EmergencyControle1,
                               "Add airplane to runway failure");
                        ENSURE(isAirplaneInRunway(airplane), "addAirplaneToRunway() failure");
                        break;
                    }
                }
            }
        }
    }
}

/*zoekt naar de geg vliegtuig in de runways en removed die
 *@param Airplane* airplane
 *@return niks
 */
void Airport::removeAirplaneFromRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneOfFrumway()");
    for(unsigned int x = 0; x < _runways.size(); x++) {
        if(_runways[x]->getAirplane() == airplane){
            _runways[x]->removeAirplane();
            ENSURE(isAirplaneRemovedFromRunway(airplane), "Remove airplane of runway failure");
            break;
        }
    }
}

/*zoekt naar een empty gate spot en add de geg vliegtuig aan deze spot
 *@param Airplane* airplane
 *@return geen
 */
void Airport::addAirplaneToGate(Airplane *airplane, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling addAirplaneToGate()");
    REQUIRE(airplane->getStatus() == JustLanded, "Airplane has to be just landed at the runway in order to taxi");
    REQUIRE(getGates().size() == _gatesize, "Amount of gates don't match with the given amount of gates");

    for(unsigned int x = 0; x < _gates.size();x++){
        if(!_gates[x]->isOccupied()){
            out << airplane->getCallsign() << " is taxiing to Gate " << _gates[x]->getName()<< std::endl;
            _gates[x]->addAirplane(airplane);
            ENSURE(isAirplaneInGate(airplane), "Airplane in gate doesn't match added airplane");
            out << airplane->getCallsign() << " is standing at Gate " << _gates[x]->getName() << std::endl;
            break;
        }
    }
}

/*zoekt naar de gegeven airplane in de gate en removed die
 *@param Airplane* airplane
 *@return geen
 */
void Airport::removeAirplaneFromGate(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(),"Airport wasn't properly initialised when calling removeAirplaneFromGate()");
    for(unsigned int x = 0; x < _gates.size();x++){
        if(_gates[x]->getAirplane() == airplane){
            out << airplane->getCallsign() << " is standing at Gate " << _gates[x]->getName() << std::endl;
            _gates[x]->getAirplane()->setStatus(Departure);
            _gates[x]->removeAirplane();
            ENSURE(isAirplaneRemovedFromGate(airplane),"Remove airplane of gate failure");
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
}

/*remove gegeven airplane van een gate en add die aan een runway
 *@param Airplane* airplane
 *@return geen
 */
void Airport::taxiToRunway(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling taxiToRunway()");
    removeAirplaneFromGate(airplane, out);
    addAirplaneToRunway(airplane, out);
}

/*remove geg airplane van runway en add die aan een gate
 *@param Airplane* airplane
 *@return geen
 */
void Airport::taxiToGate(Airplane *airplane,std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling taxiToGate()");
    removeAirplaneFromRunway(airplane);
    addAirplaneToGate(airplane, out);
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
    ENSURE(getWaitpoint1() == NULL, "removeWaitpoint1() failure");
}

/*set waitpoint2 op null
 *@param geen
 *@return geen
 */
void Airport::removeWaitpoint2()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling removeWaitPoint2()");
    setWaitpoint2(NULL);
    ENSURE(getWaitpoint2() == NULL, "removeWaitpoint2() failure");
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

/*return de runway vector
 *@param geen
 *@return vector<runway*> runway
 */
vector<Runway*> &Airport::getRunways()
{
    REQUIRE(this->properlyInitialised(), "Airprort wasn't properly initialised when calling getRunways()");
    return _runways;
}

/*add gegeven airplane aan de wacht"straat"
 *@param Airplane* airplane
 *@return geen
 */
void Airport::addRunwayWait(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling addRunwayWait()");
    _RunwayWait.push_back(airplane);
    ENSURE(isAirplaneInRunwayWait(airplane), "add airplane to runwaywait failure");
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
bool Airport::isAirplaneInRunwayWait(Airplane *airplane)
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
void Airport::goingToBeUsedRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling goingToBeUsedRunway()");
    for(unsigned int x =0; x < _runways.size();x++){
        if(!_runways[x]->isGoingToBeUsed()){
            if (validRunwayForPlane(airplane, _runways[x])) {
                _runways[x]->setUsedStatus();
                _runways[x]->setGoingtobeusedby(airplane);
                break;
            }
        }
    }
}

/*checkt of dat een airplane in een runway zit;
 *param airplane
 *@return bool
 */
bool Airport::isAirplaneInRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInRunway");
    for(unsigned int x = 0; x < _runways.size(); x++){
        if(_runways[x]->getAirplane() == airplane) return true;
    }
    return false;
}

/*checkt of dat een airplane in een gate zit
 *param airplane
 *@return bool
 */
bool Airport::isAirplaneInGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInGate");
    for(unsigned int x = 0; x < _gates.size(); x++){
        if(_gates[x]->getAirplane() == airplane) return true;
    }
    return false;
}

/*voert de emergencycontrole voor een airplane uit
 *@param airplane
 *@return niks
 */
void Airport::emergencyControle(Airplane *airplane,std::ostream& out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling emergencyControle()");
    REQUIRE(airplane->getStatus() == EmergencyControle1 ||airplane->getStatus() == EmergencyControle2, "Not valid status for airplane status");
    REQUIRE(airplane->getHeight() == 0, "Airplane must be on ground");
    if(airplane->getStatus() == EmergencyControle1){
        out << airplane->getCallsign() << " has been checked for technical malfunctions" << std::endl;
        airplane->setStatus(EmergencyControle2);
        ENSURE(airplane->getStatus() == EmergencyControle2, "Aiplane status failure");
    }
    else if(airplane->getStatus() == EmergencyControle2){
        airplane->setFuel(1000);
        out << airplane->getCallsign() << " has been refueled" << std::endl;
        out << airplane->getCallsign() << " may proceed to an empty gate" << std::endl;
        airplane->setStatus(JustLanded);
        ENSURE(airplane->getStatus() == JustLanded, "Aiplane status failure");
        this->taxiToGate(airplane, out);
        ENSURE(this->isAirplaneInGate(airplane),"Airplane to gate failure");
        this->gateprotocol(airplane, 0);
    }
}

/*checkt of dat een gegeven airplane op een gegeven runway mag landen
 *@param airplane, runway
 *@return bool
 */
bool Airport::validRunwayForPlane(Airplane *airplane, Runway* runway)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling validRunwayForPlane()");
    if(airplane->getSize() == Small){
        if(airplane->getEngine() == Propeller && runway->getType() == Grass && runway->getLength() >=500){
            return true;
        } else if(airplane->getEngine() == Jet && runway->getType() == Asphalt && runway->getLength() >=1000){
            return true;
        } else {
            return false;
        }
    } else if(airplane->getSize() == Medium){
        if(airplane->getEngine() == Propeller && runway->getType() == Asphalt && runway->getLength() >=1000){
            return true;
        } else if(airplane->getEngine() == Jet && runway->getType() == Asphalt && runway->getLength() >=2000){
            return true;
        } else {
            return false;
        }
    } else if(airplane->getSize() == Large){
        if(airplane->getEngine() == Propeller && runway->getType() == Asphalt && runway->getLength() >=1500){
            return true;
        } else if(airplane->getEngine() ==Jet && runway->getType() == Asphalt && runway->getLength() >=3000){
            return true;
        } else {
            return false;
        }
    } else{
        return false;
    }
}

/* Kijkt na of dat de airplane in een van de wachtpunten zit
 *@param airplane
 *@return bool
 */
bool Airport::isAirplaneInWaitPoint(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling isAirplaneInWaitPoint()");
    if(this->getWaitpoint1() == airplane || this->getWaitpoint2() == airplane){
        return true;
    } else {
        return false;
    }
}

/* Zet de airplane in een wachtpatroon
 *@param airplane, cout
 *@return niks
 */
void Airport::collisionSolverAirStart(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverAirStart()");
    if(airplane->getHeight() == 5000) {
        if (getWaitpoint1() == NULL) {
            setWaitpoint1(airplane);
            airplane->setStatus(Approaching);
        } else if (getWaitpoint2() == NULL) {
            airplane->descend(out);
            airplane->descend(out);
            setWaitpoint2(airplane);
        } else {
            out << airplane->getCallsign() << " has to ascend to 10000 ft. again" << std::endl;
            airplane->setHeight(10000);
        }
    }
    else if(airplane->getHeight() == 3000){
        if(getWaitpoint2() == NULL){
            setWaitpoint2(airplane);
        } else if(getWaitpoint1() == NULL){
            airplane->setHeight(5000);
            setWaitpoint1(airplane);
        } else{
            airplane->setHeight(10000);
        }
    }
    ENSURE(getWaitpoint2() == airplane || getWaitpoint1() == airplane || airplane->getHeight() == 10000, "Collisionsolver failure");
}

/* Zet de airplane uit zijn wachtpunt
 *@param airplane, cout
 *@return niks
 */
void Airport::collisionSolverAirEnd(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverAirEnd()");
    if (getController()->landingprotocol(airplane, out)) {
        if (getWaitpoint1() == airplane) {
            removeWaitpoint1();
            airplane->setStatus(Approaching);
            airplane->descend(out);
        } else if (getWaitpoint2() == airplane) {
            removeWaitpoint2();
            airplane->setStatus(FinalApproach);
            goingToBeUsedRunway(airplane);
            airplane->descend(out);
        }
    }
    ENSURE(airplane->getStatus() == Approaching|| airplane->getStatus() == FinalApproach, "Collisionsolver failure");
}

/* Start van de runway collisionsolver, zet de airplane in een wachtrij
 *@param airplane, cout
 *@return niks
 */
void Airport::collisionSolverRunwayStart(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverRunwayStart()");

    _comm->ATC_Airplane_Wait_At_Runway_Comm(_controller, airplane, out);
    addRunwayWait(airplane);
    airplane->setStatus(WaitingAtRunway);
    ENSURE(airplane->getStatus() == WaitingAtRunway, "Collisionsolver failure");
    ENSURE(isAirplaneInRunwayWait(airplane), "Collisionsolver failure");
}

/* Zet de airplane uit de wachtrij van de runways
 *@param airplane, cout
 *@return niks
 */
void Airport::collissionSolverRunwayEnd(Airplane *airplane,std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling collisionSolverRunwayEnd()");

    for(unsigned int i=0;i< getRunways().size();i++){
        if(validRunwayForPlane(airplane,getRunways()[i])){
            if(!getRunways()[i]->isGoingToBeUsed()){
                airplane->setStatus(Departure);
                removeRunwayWait(airplane);
                taxiToRunway(airplane, out);
                ENSURE(isAirplaneInRunway(airplane),"Collisionsolver failure");
                break;
            }
        }
    }
}

/* Landing sequence zodat de airplane op een runway kan landen
 *@param airplane
 *@return niks
 */
void Airport::landingSequence(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling landingSequence()");
    REQUIRE(airplane->getStatus() == Approaching || airplane->getStatus() == FinalApproach,
            "Aircontrole failure, aircraft isn't in the air");
    if (airplane->getHeight() == 10000) {
        getController()->landingprotocol(airplane, out);
        airplane->descend(out);
        out << "--------------------------------------------------------------------------" << std::endl;
    } else if (airplane->getHeight() == 5000) {
        if (getController()->landingprotocol(airplane, out)) {
            _comm->ATC_Airplane_5000ft_Comm(_controller, airplane, out);
            airplane->descend(out);
            out << "--------------------------------------------------------------------------" << std::endl;
        } else {
            _comm->ATC_Airplane_WaitPattern_Comm(_controller, airplane, out);
            collisionSolverAirStart(airplane, out);
        }
    } else if (airplane->getHeight() == 3000) {
        if (getController()->landingprotocol(airplane, out)) {
            _comm->ATC_Airplane_3000ft_Comm(_controller, airplane, out);
            airplane->setStatus(FinalApproach);
            goingToBeUsedRunway(airplane);
            airplane->descend(out);
            out << "--------------------------------------------------------------------------" << std::endl;

        } else {
            _comm->ATC_Airplane_WaitPattern_Comm(_controller, airplane, out);
            collisionSolverAirStart(airplane, out);
        }
    }
    else if (airplane->getHeight() == 0) {
        addAirplaneToRunway(airplane, out);
    }
    else if (airplane->getHeight() != 0) {
        airplane->descend(out);
        out << "--------------------------------------------------------------------------" << std::endl;
    }
}

/* De uitvoering van de gateprotocol voor de airplane
 *@param airplane, cout
 *@return niks
 */
void Airport::completeGateProtocol(Airplane* airplane, std::ostream & out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling completeGateProtocol()");
    REQUIRE(airplane->getStatus() == JustLanded || airplane->getStatus() == StandingAtGate, "Complete Gate protocol failure");
    REQUIRE(airplane->getHeight() == 0, "GateProtocol failure");
    if(!airplane->isFueled()){
        gateprotocol(airplane,50, out);
    } else {
        gateprotocol(airplane, 50, out);
        _controller->takeOffClearance(airplane, out);
    }
}

/* Take off sequence voor een vliegtuig
 *@param  airplane, cout
 *@return niks
 */
void Airport::takeOffSequence(Airplane *airplane, std::ostream &out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised when calling takeOffSequence()");
    REQUIRE(airplane->getStatus() == Departure, "Departure failure");
    REQUIRE(isAirplaneInRunway(airplane), "Airplane isn't on a runway");
    for (unsigned int i = 0; i < getRunways().size();i++) {
        if(getRunways()[i]->getAirplane() == airplane){
            if(airplane->getHeight() == 0){
                _comm->ATC_Airplane_Enter_TakeOff_Permission_Granted_Runway_Comm(_controller, airplane, out);
                airplane->ascend(out);
                out << "--------------------------------------------------------------------------" << std::endl;
                break;
            } else if(airplane->getHeight() == 5000){
                removeAirplaneFromRunway(airplane);
                airplane->setStatus(InTheAir);
                out << airplane->getCallsign() << " has left " << getName() <<std::endl;
                ENSURE(!isAirplaneInRunway(airplane), "Take off failure");
                ENSURE(airplane->getStatus() == InTheAir, "Take off failure");
                out << "--------------------------------------------------------------------------" << std::endl;
                break;
            }
            else if(airplane->getHeight() < 5000){
                airplane->ascend(out);
                out << "--------------------------------------------------------------------------" << std::endl;
                break;
            }

        }
    }
}

/* emergencylanding voor een vliegtuig
 *@param airplane, cout
 *@return niks
 */
void Airport::emergencySequence(Airplane* airplane, std::ostream& out)
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised");
    REQUIRE(airplane->getFuel() == 0, "Fuel isn't empty");
    if (!airplane->isControle()) {
        airplane->setStatus(EmergencyLanding);
        if (getController()->emergencyprotocol(airplane,out)) {
            for (unsigned int l = 0; l < getRunways().size(); l++) {
                //There is a free valid runway for the emergency landing
                if (validRunwayForPlane(airplane, getRunways()[l])) {
                    if (!getRunways()[l]->isGoingToBeUsed()) {
                        if (!getRunways()[l]->isOccupied()) {
                            airplane->setControle(true);
                            getRunways()[l]->setUsedStatus();
                            getRunways()[l]->setGoingtobeusedby(airplane);
                            break;
                        }
                    } else {
                        //There is no free valid runway for the emergency landing
                        //Make one free for the airplane
                        if(validRunwayForPlane(airplane, getRunways()[l])){
                            if(getRunways()[l]->getGoingtobeusedby()->getStatus() == Departure){
                                Airplane* tempairplane = getRunways()[l]->getAirplane();
                                getRunways()[l]->removeAirplane();
                                addRunwayWait(tempairplane);
                                getRunways()[l]->setUsedStatus();
                                getRunways()[l]->setGoingtobeusedby(airplane);
                                airplane->setControle(true);
                            }
                            else if(getRunways()[l]->getGoingtobeusedby()->getHeight() >= 3000 &&
                                    getRunways()[l]->getGoingtobeusedby()->getHeight() <= 5000){
                                Airplane* tempairplane = getRunways()[l]->getAirplane();
                                getRunways()[l]->removeAirplane();
                                collisionSolverAirStart(tempairplane, out);
                                getRunways()[l]->setUsedStatus();
                                getRunways()[l]->setGoingtobeusedby(airplane);
                                airplane->setControle(true);
                            }
                            else{
                                airplane->setStatus(EmergencyLandingOutside);
                                ENSURE(airplane->getStatus() == EmergencyLandingOutside, "Emergencylanding outside failure");
                            }
                        }
                        break;
                    }
                }
            }
        }
    }
    if (airplane->getHeight() == 0 && airplane->getStatus() == EmergencyLanding) {
        addAirplaneToRunway(airplane, out);
        ENSURE(isAirplaneInRunway(airplane), "Emergency landing failure");
    }else if(airplane->getStatus() == EmergencyControle1 ||airplane->getStatus() == EmergencyControle2){
        emergencyControle(airplane,out);
    } else {
        if(airplane->getHeight() != 0){
            airplane->descend(out);
            out << "--------------------------------------------------------------------------" << std::endl;
        }
    }
}

/* Returned de gate vector
 *@param geen
 *@return gate vector
 */
vector<Gate *> &Airport::getGates()
{
    REQUIRE(this->properlyInitialised(), "Not properly initialised");
    return _gates;
}

/* returned of dat de airplane niet meer in de gate zit
 *@param airplane
 *@return bool
 */
bool Airport::isAirplaneRemovedFromGate(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Not properly initialised");
    for(unsigned int x = 0;x < _gates.size();x++){
        if(_gates[x]->getAirplane() == airplane){
            return false;
        }
    }
    return true;
}

/* returned of dat de airplane niet meer in de runway zit
 *@param airplane
 *@return bool
 */
bool Airport::isAirplaneRemovedFromRunway(Airplane *airplane)
{
    REQUIRE(this->properlyInitialised(), "Not properly initialised");
    for(unsigned int x = 0;x < _runways.size();x++){
        if(_runways[x]->getAirplane() == airplane){
            return false;
        }
    }
    return true;
}

/* return de wachtrij vector
 *@param geen
 *@return wachtrij vector
 */
const vector<Airplane *> &Airport::getRunwayWait()
{
    REQUIRE(this->properlyInitialised(), "Airport wasn't properly initialised");
    return _RunwayWait;
}

