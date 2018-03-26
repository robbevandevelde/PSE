//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "AirportParser.h"

string AirportParser::readElement(TiXmlElement *elem, const char *tag) {
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

AirportParser::AirportParser() {
    airport= new Airport();
}

AirportParser::~AirportParser() {

}

Airport *AirportParser::parseAirport(TiXmlElement *elem) {
    string Iata = readElement(elem, "iata");
    airport->setIata(Iata);
    string Name = readElement(elem, "name");
    airport->setName(Name);
    string Callsign = readElement(elem, "callsign");
    airport->setCallsign(Callsign);
    string Gates = readElement(elem, "gates");
    airport->setGates(atoi(Gates.c_str()));
    airport->setAmountOfGates(atoi(Gates.c_str()));
    return airport;
}

Airport *AirportParser::getAirport() {
    return airport;
}
