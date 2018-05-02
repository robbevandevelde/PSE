/*Dit zijn de airplanes, deze hebben een take off en een landing sequence die men kan oproepen
 *@author: Thimoty
 *@date: 06/03/2018
 */

#ifndef PARSER_AIRPLANE_H
#define PARSER_AIRPLANE_H

#include "DesignByContract.h"
#include "Flightplan.h"
#include <iostream>
//class Flightplan;


enum Status {JustLanded, StandingAtGate, StandingAtRunway, WaitingPattern, Departure, InTheAir,FinalApproach, Approaching};
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

    Airplane(std::string number,std::string callsign, std::string model,
             unsigned int status, unsigned int passengers, unsigned int fuel,
             std::string type, std::string engine, std::string size, Flightplan* flightp);

    bool properlyInitialised();

    Flightplan *getFlightplan();

    void ascend();
    void descend();

    bool isFueled();
    unsigned int getFuel();
    unsigned int getStatus();
    unsigned int getHeight();
    unsigned int getPassengers();
    const std::string &getModel();
    const std::string &getNumber();
    const std::string &getCallsign();
    const std::string &getSize();
    const std::string &getType();
    const std::string &getEngine();

    void setFueled(bool _fueled);
    void setFuel(unsigned int _fuel);
    void setStatus(unsigned int _status);
    void setHeight(unsigned int _height);
    void setSize(const std::string &size);
    void setType(const std::string &type);
    void setModel(const std::string &_model);
    void setEngine(const std::string &engine);
    void setNumber(const std::string &_number);
    void setFlightplan(Flightplan *flightplan);
    void setPassengers(unsigned int _passengers);
    void setCallsign(const std::string &_callsign);


};


#endif //PARSER_AIRPLANE_H
