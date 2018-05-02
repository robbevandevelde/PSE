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
    * PRE:
    * POST:
    */
    AirportParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~AirportParser();
    /* Contract
    * PRE:
    * POST:
    */
    Airport* parseAirport(TiXmlElement* elem);
    /* Contract
    * PRE:
    * POST:
    */
    Airport* getAirport();
};


#endif //PARSER_AIRPORTPARSER_H

