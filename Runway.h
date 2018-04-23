/*Dit is de runway waar de vliegtuigen in kunnen geplaatst worden
 *Author: Thimoty
 *Date: 06/03/2018
 *Version: 1.0
 */


#ifndef PARSER_RUNWAY_H
#define PARSER_RUNWAY_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Airplane.h"
#include "Taxiroute.h"
#include "DesignByContract.h"
using namespace std;

class Runway {
private:
    Airplane airplane;
    string Name;
    string Airport;
    bool status; //True als vliegtuig, false als leeg
    string type;
    int length;
    vector <Taxiroute*> taxiRoute;
    Runway* _initCheck;
public:
    const vector<Taxiroute *> &getTaxiRoute() const;

    void setTaxiRoute(const vector<Taxiroute *> &taxiRoute);

    void pushbackTaxi(Taxiroute* taxiroute);

    const string &getType() const;

    void setType(const string &type);

    int getLength() const;

    void setLength(int length);

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
