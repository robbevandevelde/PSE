//
// Created by Robbe Van de Velde on 24/04/18.
//

#include "FlightplanParser.h"
/*
 * reads element
 * @param, xml element and tag
 * @return string of value
 */
string FlightplanParser::readElement(TiXmlElement *elem, const char *tag)
{
    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    REQUIRE(e != NULL, "Please check if the tags in flightplan are either: destination, departure, arrival or interval.");
    TiXmlNode* node = e->FirstChild();
    REQUIRE(node != NULL, "An item in flightplan is none, cannot parse further");
    TiXmlText* text = node->ToText();
    ENSURE(text != NULL, "the element cannot be none");
    return text->Value();
}
/*
 * constructor
 */
FlightplanParser::FlightplanParser()
{
    initCheck=this;
    ENSURE(properlyInitialised(), "FlightplanParser wasn't properly initialised when calling constructor");
}
/*
 * destructor
 */
FlightplanParser::~FlightplanParser()
{
    ENSURE(properlyInitialised(), "FlightplanParser wasn't properly initialised when calling destructor");

}
/*
 * parses al the elements
 * @param XML element
 * @return flightplane
 */
Flightplan *FlightplanParser::parseFlightplan(TiXmlElement *elem)
{
    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling parseFlightplan");
    string Destination = readElement(elem, "destination");
    unsigned int Departure = atoi(readElement(elem, "departure").c_str());
    unsigned int Arrival = atoi(readElement(elem, "arrival").c_str());
    unsigned int Interval = atoi(readElement(elem, "interval").c_str());
    REQUIRE(Destination!= "", "Destination cannot be None");
    REQUIRE(readElement(elem, "departure")!= "", "Departure cannot be None");
    REQUIRE(readElement(elem, "arrival")!= "", "Arrival cannot be None");
    REQUIRE(readElement(elem, "interval")!= "", "Interval cannot be None");
    Flightplan* flightplan = new Flightplan(Destination, Departure, Arrival, Interval);
    ENSURE(flightplan->getDeparture() == Departure, "Departure not equal");
    ENSURE(flightplan->getArrival() == Arrival, "Arrival not equal");
    ENSURE(flightplan->getDestination() == Destination, "Destination not equal");
    ENSURE(flightplan->getInterval() == Interval, "Interval not equal");
    return flightplan;

}
/*
 * returns the flightplane
 * @param none
 * @return flightplan
 */
Flightplan *FlightplanParser::getFlightplan()
{
    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling parseFlightplan");
    return flightplan;
}

bool FlightplanParser::properlyInitialised()
{
    return initCheck == this;
}
