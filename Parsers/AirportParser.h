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
    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Constructed
    */
    AirportParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~AirportParser();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Airport items must be parsed
    */
    Airport* parseAirport(TiXmlElement* elem);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Airport is returned
    */
    Airport* getAirport();
};


#endif //PARSER_AIRPORTPARSER_H

