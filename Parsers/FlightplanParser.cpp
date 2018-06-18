//
// Created by Robbe Van de Velde on 24/04/18.
//

#include "FlightplanParser.h"

string FlightplanParser::readElement(TiXmlElement *elem, const char *tag)
{
    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling readElement");
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

FlightplanParser::FlightplanParser()
{
    initCheck=this;
    ENSURE(properlyInitialised(), "FlightplanParser wasn't properly initialised when calling constructor");
}

FlightplanParser::~FlightplanParser()
{
    ENSURE(properlyInitialised(), "FlightplanParser wasn't properly initialised when calling destructor");

}

Flightplan *FlightplanParser::parseFlightplan(TiXmlElement *elem)
{
    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling parseFlightplan");
    string Destination = readElement(elem, "destination");
    unsigned int Departure = atoi(readElement(elem, "departure").c_str());
    unsigned int Arrival = atoi(readElement(elem, "arrival").c_str());
    unsigned int Interval = atoi(readElement(elem, "interval").c_str());
    Flightplan* flightplan = new Flightplan(Destination, Departure, Arrival, Interval);
    ENSURE(flightplan->getDeparture() == Departure, "Departure not equal");
    ENSURE(flightplan->getArrival() == Arrival, "Arrival not equal");
    ENSURE(flightplan->getDestination() == Destination, "Destination not equal");
    ENSURE(flightplan->getInterval() == Interval, "Interval not equal");
    return flightplan;

}

Flightplan *FlightplanParser::getFlightplan()
{
    REQUIRE(this->properlyInitialised(), "FlightplanParser wasn't properly initialised when calling parseFlightplan");
    return flightplan;
}

bool FlightplanParser::properlyInitialised()
{
    return initCheck == this;
}
