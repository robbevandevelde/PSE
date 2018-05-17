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
    //    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling readElement");
    string readElement(TiXmlElement* elem, const char* tag);
    Flightplan* flightplan;
    FlightplanParser* initCheck;
public:
    bool properlyInitialised();
    //    ENSURE(properlyInitialised(), "FlightplanParser wasn't properly initialised when calling constructor");
    FlightplanParser();
    //    ENSURE(properlyInitialised(), "FlightplanParser wasn't properly initialised when calling destructor");
    virtual ~FlightplanParser();
    //    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling parseFlightplan");
    //    ENSURE(flightplan->getDeparture() == Departure, "Departure not equal");
    //    ENSURE(flightplan->getArrival() == Arrival, "Arrival not equal");
    //    ENSURE(flightplan->getDestination() == Destination, "Destination not equal");
    //    ENSURE(flightplan->getInterval() == Interval, "Interval not equal");
    Flightplan* parseFlightplan(TiXmlElement* elem);
    //    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling parseFlightplan");
    Flightplan* getFlightplan();
};


#endif //PSE_FLIGHTPLANPARSER_H
