/*Dit zijn de airplanes, deze hebben een take off en een landing sequence die men kan oproepen
 *@author: Thimoty
 *@date: 06/03/2018
 */

#ifndef PARSER_AIRPLANE_H
#define PARSER_AIRPLANE_H

#include "DesignByContract.h"
#include <iostream>

enum Status {JustLanded, StandingAtGate, Departure, InTheAir, Approaching};

class Airplane {
private:
    //Airplane* _initCheck;
    Airplane* _initcheck;

    unsigned int _status;
    unsigned int _fuel;
    unsigned int _height;
    unsigned int _passengers;

    std::string _model;
    std::string _number;
    std::string _callsign;
    std::string _type;
    std::string _engine;
    std::string _size;
public:
    Airplane(std::string number,std::string callsign, std::string model, unsigned int status);

    bool properlyInitialised();

    unsigned int get_fuel();
    unsigned int get_status();
    unsigned int get_height();
    unsigned int get_passengers();
    const std::string &get_model();
    const std::string &get_number();
    const std::string &get_callsign();
    const std::string &get_size() const;
    const std::string &get_type() const;
    const std::string &get_engine() const;

    void set_fuel(unsigned int _fuel);
    void set_status(unsigned int _status);
    void set_height(unsigned int _height);
    void set_passengers(unsigned int _passengers);
    void set_model(const std::string &_model);
    void set_number(const std::string &_number);
    void set_callsign(const std::string &_callsign);
    void set_size(const std::string &size);
    void set_engine(const std::string &engine);
    void set_type(const std::string &type);

};


#endif //PARSER_AIRPLANE_H
