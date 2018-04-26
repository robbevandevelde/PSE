//
// Created by Robbe Van de Velde on 7/03/18.
//

#include <iostream>
#include "AirplaneParser.h"
#include "FlightplanParser.h"

string AirplaneParser::readElement(TiXmlElement *elem, const char *tag) {
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

AirplaneParser::AirplaneParser() {

}

AirplaneParser::~AirplaneParser() {

}

Airplane *AirplaneParser::parseAirplane(TiXmlElement *elem) {
    string Number = readElement(elem, "number");
    airplane->set_number(Number);
    string Model = readElement(elem, "model");
    airplane->set_model(Model);
    string Callsign = readElement(elem, "callsign");
    airplane->set_callsign(Callsign);
    string Status = readElement(elem, "status");
    airplane->set_status(atoi(Status.c_str()));
    string passengers = readElement(elem, "passengers");
    airplane->set_passengers(atoi(passengers.c_str()));
    string fuel = readElement(elem, "fuel");
    airplane->set_fuel(atoi(fuel.c_str()));
    string Type = readElement(elem, "type");
    airplane->set_type(Type);
    string Engine = readElement(elem, "engine");
    airplane->set_engine(Engine);
    string size = readElement(elem, "size");
    airplane->set_size(size);

//    for (TiXmlElement *p = elem->FirstChildElement(); p != NULL; p = p->NextSiblingElement()) {
//        string elemName = p->Value();
//        if (elemName == "FLIGHTPLAN") {
//            FlightplanParser fpp;
//            Flightplan *fp = fpp.parseFlightplan(p);
//            airplane->setFlightplan(fp);
//        }
//    }

    return airplane;}

Airplane *AirplaneParser::getAirplane() {
    return airplane;
}
