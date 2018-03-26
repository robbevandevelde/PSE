/*Dit is de runway waar de vliegtuigen in kunnen geplaatst worden
 *Author: Thimoty
 *Date: 06/03/2018
 *Version: 1.0
 */


#ifndef PARSER_RUNWAY_H
#define PARSER_RUNWAY_H
#include <string>
#include <iostream>
#include <algorithm>
#include "Airplane.h"
#include "DesignByContract.h"
using namespace std;

class Runway {
private:
    Airplane airplane;
    string Name;
    string Airport;
    bool status; //True als vliegtuig, false als leeg
    Runway* _initCheck;

public:
    bool properlyInitialiazed();
    bool getStatus() const;

    void setStatus(bool status);

    Runway(const string &Name, const string &Airport);

    Airplane getAirplane() const;

    void setAirplane(Airplane &airplane);
    void removeAirplane();
    Runway();
    virtual ~Runway();

    const string& getName() const;

    void setName(const string& newName);

    const string& getAirport() const;

    void setAirport(const string& newAirport);


};


#endif //PARSER_RUNWAY_H
