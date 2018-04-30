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
    string Model = readElement(elem, "model");
    string Callsign = readElement(elem, "callsign");
    string Status = readElement(elem, "status");
    unsigned int Passengers = atoi(readElement(elem, "passengers").c_str());
    unsigned int Fuel = atoi(readElement(elem, "fuel").c_str());
    string Type = readElement(elem, "type");
    string Engine = readElement(elem, "engine");
    string Size = readElement(elem, "size");
    Flightplan* fp = NULL;

    for (TiXmlElement *p = elem->FirstChildElement(); p != NULL; p = p->NextSiblingElement()) {
        string elemName = p->Value();
        if (elemName == "FLIGHTPLAN") {
            FlightplanParser fpp;
            fp = fpp.parseFlightplan(p);
        }
    }
    Airplane* airplane = new Airplane(Number, Callsign, Model, Statuscheck(Status), Passengers, Fuel, Type, Engine, Size, fp);


    return airplane;}

Airplane *AirplaneParser::getAirplane() {
    return airplane;
}

unsigned int AirplaneParser::Statuscheck(string St) {
    if (St== "Approaching"){
        return Approaching;
    }
    if (St == "StandingAtGate"){
        return StandingAtGate;
    }
    if( St == "Departure"){
        return  Departure;
    }
    if (St == "InTheAir"){
        return InTheAir;
    }
    if(St == "JustLanded"){
        return JustLanded;
    }
    return -1;
}
