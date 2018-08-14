//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "AirportParser.h"

string AirportParser::readElement(TiXmlElement *elem, const char *tag)
{
    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    ENSURE(text != NULL, "the element cannot be none");
    return text->Value();
}

AirportParser::AirportParser()
{
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

AirportParser::~AirportParser()
{
    ENSURE(properlyInitialised(), "Destructor must end");

}

Airport *AirportParser::parseAirport(TiXmlElement *elem)
{
    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling parseAirport()");
    string Iata = readElement(elem, "iata");
    string Name = readElement(elem, "name");
    string Callsign = readElement(elem, "callsign");
    unsigned int Gates = atoi(readElement(elem, "gates").c_str());
    REQUIRE(Iata != "", "IATA has not been set properly");
    REQUIRE(Name != "", "Name has not been set properly");
    REQUIRE(Callsign != "", "Callsign has not been set properly");
    REQUIRE(readElement(elem, "gates") != "", "gates has not been set properly");

     Airport* airport = new Airport(Gates, Name, Iata, Callsign);
    ENSURE(airport->getGatesize() == Gates, "Gates not equal");
    ENSURE(airport->getName() == Name, "Name not equal");
    ENSURE(airport->getIata() == Iata, "Iata not equal");
    ENSURE(airport->getCallsign() == Callsign, "Callsign not equal");
    return airport;
}

Airport *AirportParser::getAirport()
{
    REQUIRE(this->properlyInitialised(), "AirportParser wasn't properly initialised when calling getAirport()");
    return airport;
}

bool AirportParser::properlyInitialised()
{
    return initCheck == this;
}
