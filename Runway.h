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

    Airplane* _airplane;

    unsigned int _length;

    bool _status;

    std::string _name;
    std::string _type;
    std::string _airport;

    std::vector <Taxiroute*> taxiRoute;
public:

    Runway(int _length, const std::string &_name, const std::string &_type, const std::string &_airport);
    bool properlyInitialised();

    bool is_status();
    unsigned int get_length();
    Airplane *get_airplane();
    const std::string &get_name();
    const std::string &get_type();
    const std::string &get_airport();
    const std::vector<Taxiroute *> &getTaxiRoute() const;


    void set_length(unsigned int _length);
    void set_name(const std::string &_name);
    void set_type(const std::string &_type);
    void set_airport(const std::string &_airport);
    void pushbackTaxi(Taxiroute* taxiroute);
    void setTaxiRoute(const std::vector<Taxiroute *> &taxiRoute);
    void addAirplane(Airplane* airplane);
    void removeAirplane();

};


#endif //PARSER_RUNWAY_H
