//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "AirplaneParser.h"

string AirplaneParser::readElement(TiXmlElement *elem, const char *tag) {
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

AirplaneParser::AirplaneParser() {
    airplane= new Airplane();

}

AirplaneParser::~AirplaneParser() {

}

Airplane *AirplaneParser::parseAirplane(TiXmlElement *elem) {
    string Number = readElement(elem, "number");
    airplane->setNumber(Number);
    string Model = readElement(elem, "model");
    airplane->setModel(Model);
    string Callsign = readElement(elem, "callsign");
    airplane->setCallsign(Callsign);
    string Status = readElement(elem, "status");
    airplane->setStatus(Status);
    return airplane;}

Airplane *AirplaneParser::getAirplane() {
    return airplane;
}
