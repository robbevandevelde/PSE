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

class Taxiroute;
class Airplane;

class Runway {
private:
    Runway* _initcheck;

    std::vector <Taxiroute*> _taxiRoute;

    Airplane* _airplane;

    unsigned int _length;

    bool _status;

    std::string _name;
    std::string _type;
    std::string _airport;
public:
    Runway(unsigned int _length, const std::string &_name, const std::string &_type, const std::string &_airport);

    bool properlyInitialised();

    bool isStatus();
    Airplane *getAirplane();
    unsigned int getLength();
    const std::string &getName();
    const std::string &getType();
    const std::string &getAirport();
    const std::vector<Taxiroute *> &getTaxiRoute();

    void removeAirplane();
    void setStatus(bool _status);
    void setLength(unsigned int _length);
    void addAirplane(Airplane* airplane);
    void setAirplane(Airplane *_airplane);
    void setName(const std::string &_name);
    void setType(const std::string &_type);
    void pushbackTaxi(Taxiroute* taxiroute);
    void setAirport(const std::string &_airport);
    void setTaxiRoute(const std::vector<Taxiroute *> &taxiRoute);
};


#endif //PARSER_RUNWAY_H
