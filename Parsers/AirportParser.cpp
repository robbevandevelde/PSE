//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "AirportParser.h"

string AirportParser::readElement(TiXmlElement *elem, const char *tag) {
    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

AirportParser::AirportParser() {
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

AirportParser::~AirportParser() {

}

Airport *AirportParser::parseAirport(TiXmlElement *elem) {
    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling parseAirport()");
    string Iata = readElement(elem, "iata");
    string Name = readElement(elem, "name");
    string Callsign = readElement(elem, "callsign");
    unsigned int Gates = atoi(readElement(elem, "gates").c_str());

     Airport* airport = new Airport(Gates, Name, Iata, Callsign);
    return airport;
}

Airport *AirportParser::getAirport() {
    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling getAirport()");
    return airport;
}

bool AirportParser::properlyInitialised() {
    return initCheck == this;
}
