/*Dit is de airplae, airplane heeft verschillende functies om variabelen van de airplane zelf te geven en te setten
 *@author: Thimoty
 *@date: 20/04/2018
 *@version: 2.0
 */

#ifndef PSE_AIRPLANE_H
#define PSE_AIRPLANE_H

#include "DesignByContract.h"
#include "Flightplan.h"
#include <iostream>

enum Status {JustLanded, StandingAtGate, WaitingAtRunway, StandingAtRunway , Departure, InTheAir,FinalApproach,
    Approaching, EmergencyLanding, EmergencyControle1, EmergencyControle2};

enum Type {Private, Airline, Militairy, Emergency};
enum Size {Small, Medium, Large};
enum Engine {Propeller, Jet};

class Airplane {
private:
    Airplane* _initcheck;
    Flightplan* _flightplan;

    unsigned int _status;
    unsigned int _type;
    unsigned int _engine;
    unsigned int _size;
    unsigned int _fuel;
    unsigned int _height;
    unsigned int _passengers;

    bool _fueled;
    bool _controle;
    std::string _model;
    std::string _number;
    std::string _callsign;
public:
    //    REQUIRE(status<9, "This status enum doesn't exist");
    //    REQUIRE(type<4, "This type enum doesn't exist");
    //    REQUIRE(size<3, "This size enum doesn't exist");
    //    REQUIRE(engine<2, "This engine enum doesn't exist");
    //    ENSURE(!_fueled, "Fueled must be false");
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(_height == 0 || _height == 10000, "Height must be either 0 or 10000");
    //    ENSURE(getNumber() == number && getCallsign() == callsign && getModel() == model && getStatus() == status &&
    //           getPassengers() == passengers && getFuel() == fuel && getType() == type && getEngine() == engine &&
    //    getSize() == size && getFlightplan() == flightp, "Airplane constructor failure");
    Airplane(std::string number,std::string callsign, std::string model,
             unsigned int status, unsigned int passengers, unsigned int fuel,
             unsigned int type, unsigned int engine, unsigned int size, Flightplan* flightp);
    //    Geen pre of post
    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getFlightplan");
    Flightplan *getFlightplan();

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling ascend()");
    //    ENSURE(getHeight() == _height, "Height is not altered");

    void ascend(std::ostream& out = std::cout);

    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling descend()");
    //    ENSURE(getHeight() == _height, "Height is not altered");
    void descend(std::ostream& out = std::cout);

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
    unsigned int getSize();
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getType()");
    unsigned int getType();
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling getEngine()");
    unsigned int getEngine();

    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFueled()");
    //    ENSURE(isFueled() == _fueled, "setFueled fail");
    void setFueled(bool _fueled);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFuel()");
    //    ENSURE(getFuel() == _fuel, "setFuel() failure");
    void setFuel(unsigned int _fuel);
    //    REQUIRE(status<9, "This status enum doesn't exist");
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setStatus()");
    //    ENSURE(getStatus() == _status, "setStatus() failure");
    void setStatus(unsigned int _status);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setHeight()");
    //    ENSURE(getHeight() == _height,"setHeight() failure");
    void setHeight(unsigned int _height);
    //    REQUIRE(size<3, "This size enum doesn't exist");
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setSize()");
    //    ENSURE(getSize() == size, "setSize() failure");
    void setSize(unsigned int _size);
    //    REQUIRE(type<4, "This type enum doesn't exist");
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setType()");
    //    ENSURE(getType() == type,"setType() failure");
    void setType(unsigned int _type);
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setModel()");
    //    ENSURE(getModel() == _model, "setModel() failure");
    void setModel(const std::string &_model);
    //    REQUIRE(engine<2, "This engine enum doesn't exist");
    //    REQUIRE(this->properlyInitialised(), "Airplane wasn't properly initialised when calling setEngine()");
    //    ENSURE(getEngine() == engine, "setEngine() failure");
    void setEngine(unsigned int _engine);
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
    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setFueled()");
    //    ENSURE(_size == Small, "Airplane is too big to land on grass");
    //    ENSURE(_engine == Propeller, "This engine is not a propeller");
    bool isAllowedToLandOnGrass();

    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling isControle()");
    bool isControle();

    //    REQUIRE(this->properlyInitialised(),"Airplane wasn't properly initialised when calling setControle()");
    void setControle(bool _controle);
};


#endif //PSE_AIRPLANE_H
