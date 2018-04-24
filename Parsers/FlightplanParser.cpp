//
// Created by Robbe Van de Velde on 24/04/18.
//

#include "FlightplanParser.h"

string FlightplanParser::readElement(TiXmlElement *elem, const char *tag) {
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

FlightplanParser::FlightplanParser() {
    flightplan= new Flightplan();

}

FlightplanParser::~FlightplanParser() {

}

Flightplan *FlightplanParser::parseFlightplan(TiXmlElement *elem) {
    string Destination = readElement(elem, "destination");
    flightplan->setDestination(Destination);
    string Departure = readElement(elem, "departure");
    flightplan->setDeparture(atoi(Departure.c_str()));
    string Arrival = readElement(elem, "arrival");
    flightplan->setArrival(atoi(Arrival.c_str()));
    string Interval = readElement(elem, "interval");
    flightplan->setInterval(atoi(Interval.c_str()));
    return flightplan;

}

Flightplan *FlightplanParser::getFlightplan() {
    return flightplan;
}
