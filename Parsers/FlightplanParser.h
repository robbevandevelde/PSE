//
// Created by Robbe Van de Velde on 24/04/18.
//

#ifndef PSE_FLIGHTPLANPARSER_H
#define PSE_FLIGHTPLANPARSER_H

#include <string>
#include "../TinyXML/tinyxml.h"
#include "../Flightplan.h"


using namespace std;

class FlightplanParser {
private:
    string readElement(TiXmlElement* elem, const char* tag);
    Flightplan* flightplan;
    FlightplanParser* initCheck;
public:
    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Flightplan is constructed
    */
    FlightplanParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~FlightplanParser();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:
     * flightplan is parsed
    */
    Flightplan* parseFlightplan(TiXmlElement* elem);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Flightplan is returned
    */
    Flightplan* getFlightplan();
};


#endif //PSE_FLIGHTPLANPARSER_H
