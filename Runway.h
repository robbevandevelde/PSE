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

    unsigned int _length;
    std::string _name;
    unsigned int _rwType;
    std::string _airport;

    bool _status;
    bool _goingtobeused;



public:
    //    ENSURE(properlyInitialised(), "Constructor must end");
    //    ENSURE(!_status && !_goingtobeused, "Status must be false after initialising");
    //    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after initialising");
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
    const std::string &getName();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getType()");
    unsigned int getType();
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling getAirport()");
    const std::string &getAirport();

    //  REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling removeAirplane()");
    //    REQUIRE(_airplane != NULL, "Airplane must point to an airplane and not a nullptr");
    //    REQUIRE(_status, "Status must be true because the space is occupied");
    //    ENSURE(!_goingtobeused, " remove airplane failure");
    //    ENSURE(_airplane == NULL, "Airplane must point to a nullptr after removing a plane");
    //    ENSURE(!_status,"Status must be false after removing a plane");
    void removeAirplane();

    //    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setStatus()");
    //    REQUIRE(!_goingtobeused, "setUsedSatus() failure");
    //    ENSURE(_goingtobeused, "setUsedStatus() failure");
    void setStatus(bool _status);
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setLength()");
    //    ENSURE(getLength() == _length, "setLength() failure");
    void setLength(unsigned int _length);

    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling addAirplane()");
    //    REQUIRE(!_status, "Status must be false");
    //    REQUIRE(_airplane == NULL, "Airplane must point to a nullptr");
    //    ENSURE(_airplane->getHeight() == 0, "Added airplane's height isn't set to 0");
    //    ENSURE(getAirplane() == airplane, "Added airplane doesn't match airplane");
    //    ENSURE(getAirplane() == airplane, "Airplane must point to the given airplane");
    //    ENSURE(_status,"Status must be true after adding an airplane");
    void addAirplane(Airplane* airplane);

    //    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirplane()");
    //    ENSURE(getAirplane() == _airplane, "setAirplane() failure");
    void setAirplane(Airplane *_airplane);
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setName()");
    //    ENSURE(getName() == _name, "setName() failure");
    void setName(const std::string &_name);
    //    REQUIRE(this->properlyInitialised(), "Runway wasn't properly initialised when calling setType()");
    //    ENSURE(getType() == _type, "setType() failure");


    ///////
    void setType(unsigned int _type);

    //    REQUIRE(this->properlyInitialised(),"Runway wasn't properly initialised when calling setAirport()");
    //    ENSURE(getAirport() == _airport, "setAirport failure");
    void setAirport(const std::string &_airport);

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling setUsedStatus()");
    //    REQUIRE(!_goingtobeused, "setUsedSatus() failure");
    //    ENSURE(_goingtobeused, "setUsedStatus() failure");
    void setUsedStatus();

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling removeUsedStatus()");
    //    ENSURE(!_goingtobeused, "removeUsedStatus() failure");
    void removeUsedStatus();

    //    REQUIRE(this->properlyInitialised(), "Gate wasn't properly initialised when calling isUsedStatus()");
    bool isGoingToBeUsed();
};


#endif //PSE_RUNWAY_H
