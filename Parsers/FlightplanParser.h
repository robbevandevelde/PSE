//
// Created by Robbe Van de Velde on 24/04/18.
//

#ifndef PSE_FLIGHTPLANPARSER_H
#define PSE_FLIGHTPLANPARSER_H
#include <string>
#include "AirplaneParser.h"
#include "../TinyXML/tinyxml.h"
using namespace std;

class FlightplanParser {
private:
    string readElement(TiXmlElement* elem, const char* tag);
    Flightplan* flightplan;
public:
    FlightplanParser();
    virtual ~FlightplanParser();
    Flightplan* parseFlightplan(TiXmlElement* elem);
    Flightplan* getFlightplan();
};


#endif //PSE_FLIGHTPLANPARSER_H
