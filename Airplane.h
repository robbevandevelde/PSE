/*Dit is de airplae, airplane heeft verschillende functies om variabelen van de airplane zelf te geven en te setten
 *@author: Thimoty
 *@date: 20/04/2018
 *@version: 2.0
 */

#ifndef PARSER_AIRPLANE_H
#define PARSER_AIRPLANE_H

#include "DesignByContract.h"
#include "Flightplan.h"
#include <iostream>
//class Flightplan;


enum Status {JustLanded, StandingAtGate, WaitingAtRunway, StandingAtRunway , Departure, InTheAir,FinalApproach,
    Approaching, EmergencyLanding};
class Airplane {
private:
    Airplane* _initcheck;
    Flightplan* _flightplan;

    unsigned int _status;
    unsigned int _fuel;
    unsigned int _height;
    unsigned int _passengers;

    bool _fueled;

    std::string _model;
    std::string _number;
    std::string _callsign;
    std::string _type;
    std::string _engine;
    std::string _size;
public:
    //    ENSURE(!_fueled, "Fueled must be false");
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(_height == 0 || _height == 10000, "Height must be either 0 or 10000");
    //    ENSURE(getNumber() == number && getCallsign() == callsign && getModel() == model && getStatus() == status &&
    //           getPassengers() == passengers && getFuel() == fuel && getType() == type && getEngine() == engine &&
    //    getSize() == size && getFlightplan() == flightp, "Airplane constructor failure");
    Airplane(std::string number,std::string callsign, std::string model,
             unsigned int status, unsigned int passengers, unsigned int fuel,
             std::string type, std::string engine, std::string size, Flightplan* flightp);
    //    Geen pre of post
    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getFlightplan");
    Flightplan *getFlightplan();

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling ascend()");
    void ascend();

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling descend()");
    void descend();

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling isFueled()");
    bool isFueled();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getFuel()");
    unsigned int getFuel();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getStatus()");
    unsigned int getStatus();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getHeight()");
    unsigned int getHeight();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getPassengers()");
    unsigned int getPassengers();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getModel()");
    const std::string &getModel();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getNumber()");
    const std::string &getNumber();
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling getCallsign()");
    const std::string &getCallsign();
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getSize()");
    const std::string &getSize();
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getType()");
    const std::string &getType();
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getEngine()");
    const std::string &getEngine();

    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFueled()");
    //    ENSURE(isFueled() == _fueled, "setFueled fail");
    void setFueled(bool _fueled);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFuel()");
    //    ENSURE(getFuel() == _fuel, "setFuel() failure");
    void setFuel(unsigned int _fuel);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setStatus()");
    //    ENSURE(getStatus() == _status, "setStatus() failure");
    void setStatus(unsigned int _status);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setHeight()");
    //    ENSURE(getHeight() == _height,"setHeight() failure");
    void setHeight(unsigned int _height);
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setSize()");
    //    ENSURE(getSize() == size, "setSize() failure");
    void setSize(const std::string &size);
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setType()");
    //    ENSURE(getType() == type,"setType() failure");
    void setType(const std::string &type);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setModel()");
    //    ENSURE(getModel() == _model, "setModel() failure");
    void setModel(const std::string &_model);
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setEngine()");
    //    ENSURE(getEngine() == engine, "setEngine() failure");
    void setEngine(const std::string &engine);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setNumber()");
    //    ENSURE(getNumber() == _number, "setNumber() failure");
    void setNumber(const std::string &_number);
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setFlightplan()");
    //    ENSURE(getFlightplan() == flightplan, "setFlightplan() failure");
    void setFlightplan(Flightplan *flightplan);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setPassengers()");
    //    ENSURE(getPassengers() == _passengers, "setPassengers() failure");
    void setPassengers(unsigned int _passengers);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setCallsign()");
    //    ENSURE(getCallsign() == _callsign, "setCallsign() failure");
    void setCallsign(const std::string &_callsign);
};


#endif //PARSER_AIRPLANE_H
