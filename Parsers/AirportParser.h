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
    string readElement(TiXmlElement* elem, const char* tag);
    Airport* airport;
public:
    bool properlyInitialised();
    AirportParser();
    virtual ~AirportParser();
    Airport* parseAirport(TiXmlElement* elem);
    Airport* getAirport();
};


#endif //PARSER_AIRPORTPARSER_H

