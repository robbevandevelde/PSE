/*Hulpcklasse voor de mainparser
 *@Author: Robbe
 *@Date: 05/06/2018
 */

#ifndef PARSER_AIRPORTPARSER_H
#define PARSER_AIRPORTPARSER_H
#include <string>
#include "../Airport.h"
#include "../TinyXML/tinyxml.h"
using namespace std;

class AirportParser{
private:
    AirportParser* initCheck;
    //    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling readElement()");
    string readElement(TiXmlElement* elem, const char* tag);
    Airport* airport;
public:

    bool properlyInitialised();
    //    ENSURE(properlyInitialised(), "Constructor must end");
    AirportParser();
    //    ENSURE(properlyInitialised(), "Destructor must end");
    virtual ~AirportParser();
    //    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling parseAirport()");
    //    ENSURE(airport->getGatesize() == Gates, "Gates not equal");
    //    ENSURE(airport->getName() == Name, "Name not equal");
    //    ENSURE(airport->getIata() == Iata, "Iata not equal");
    //    ENSURE(airport->getCallsign() == Callsign, "Callsign not equal");
    Airport* parseAirport(TiXmlElement* elem);
    //    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling getAirport()");
    Airport* getAirport();
};


#endif //PARSER_AIRPORTPARSER_H

