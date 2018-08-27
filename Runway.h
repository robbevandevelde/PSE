/*Dit is de runway waar de vliegtuigen in kunnen geplaatst worden
 *Author: Thimoty
 *Date: 20/04/2018
 *Version: 2.0
 */


#ifndef PSE_RUNWAY_H
#define PSE_RUNWAY_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

enum rwType {Grass, Asphalt};

class Airplane;

class Runway {
private:
    Runway* _initcheck;


    Airplane* _airplane;
    Airplane* _goingtobeusedby;
    unsigned int _length;
    std::string _name;
    unsigned int _rwType;
    std::string _airport;

    bool _status;
    bool _goingtobeused;



public:
    //    REQUIRE(_rwType<2, "type enum must be smaller than 2");
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(!isStatus() && !isGoingToBeUsed(), "Status must be false after initialising");
    //    ENSURE(getAirplane() == NULL, "Airplane must point to a nullptr after initialising");
    Runway(unsigned int _length, const std::string &_name, unsigned int _type, const std::string &_airport);

    //  Geen pre of post condities
    bool properlyInitialised();

    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getStatus()");
    bool isOccupied();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirplane()");
    Airplane *getAirplane();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getLength()");
    unsigned int getLength();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getName()");
    std::string &getName();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getType()");
    unsigned int getType();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirport()");
    std::string &getAirport();

    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling removeAirplane()");
    //    REQUIRE(getAirplane() != NULL, "Airplane must point to an airplane and not a nullptr");
    //    REQUIRE(isStatus(), "Status must be true because the space is occupied");
    //    ENSURE(!isGoingToBeUsed(), " remove airplane failure");
    //    ENSURE(getAirplane() == NULL && getGoingtobeusedby() == NULL, "Airplane must point to a nullptr after removing a plane");
    //    ENSURE(!isStatus(),"Status must be false after removing a plane");
    void removeAirplane();

    //    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setStatus()");
    //    ENSURE(isOccupied() == _status, "setStatus() failure");
    void setStatus(bool _status);
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setLength()");
    //    ENSURE(getLength() == _length, "setLength() failure");
    void setLength(unsigned int _length);

    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling addAirplane()");
    //    REQUIRE(!isStatus(), "Status must be false");
    //    REQUIRE(getAirplane() == NULL, "Airplane must point to a nullptr");
    //    REQUIRE(getGoingtobeusedby()== airplane, "Airplanes don't match");
    //    ENSURE(getAirplane()->getHeight() == 0, "Added airplane's height isn't set to 0");
    //    ENSURE(getAirplane() == airplane, "Added airplane doesn't match airplane");
    //    ENSURE(getAirplane() == airplane, "Airplane must point to the given airplane");
    //    ENSURE(isStatus(),"Status must be true after adding an airplane");
    void addAirplane(Airplane* airplane);

    //    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirplane()");
    //    ENSURE(getAirplane() == _airplane, "setAirplane() failure");
    void setAirplane(Airplane *_airplane);
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setName()");
    //    ENSURE(getName() == _name, "setName() failure");
    void setName(const std::string &_name);

    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setType()");
    //    ENSURE(getType() == _type, "setType() failure");
    //    REQUIRE(_type < 2, "type enum must be smaller than 2");
    //    ENSURE(getType() == _rwType, "setType() failure");
    void setType(unsigned int _type);

    //    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirport()");
    //    ENSURE(getAirport() == _airport, "setAirport failure");
    void setAirport(const std::string &_airport);

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling setUsedStatus()");
    //    REQUIRE(!isGoingToBeUsed(), "setUsedSatus() failure");
    //    ENSURE(isGoingToBeUsed(), "setUsedStatus() failure");
    void setUsedStatus();

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling removeUsedStatus()");
    //    ENSURE(!isGoingToBeUsed(), "removeUsedStatus() failure");
    void removeUsedStatus();

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isUsedStatus()");
    bool isGoingToBeUsed();
    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling getGoingtobeusedby()");
    Airplane *getGoingtobeusedby();
    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling setGoingtobeusedby");
    //    ENSURE(getAirplane() == _goingtobeusedby, "setGoingtobeusedby() failure");
    void setGoingtobeusedby(Airplane *_goingtobeusedby);

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isStatus()");
    bool isStatus();
};


#endif //PSE_RUNWAY_H
