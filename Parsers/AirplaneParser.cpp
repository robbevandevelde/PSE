//
// Created by Robbe Van de Velde on 7/03/18.
//

#include <iostream>
#include "AirplaneParser.h"
#include "FlightplanParser.h"

string AirplaneParser::readElement(TiXmlElement *elem, const char *tag) {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();
}

AirplaneParser::AirplaneParser() {
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

AirplaneParser::~AirplaneParser() {

}

Airplane *AirplaneParser::parseAirplane(TiXmlElement *elem) {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling parseAirplane()");
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
    Airplane* airplane = new Airplane(Number, Callsign, Model, Statuscheck(Status), Passengers, Fuel, Typecheck(Type),
                                      Enginecheck(Engine), Sizecheck(Size), fp);


    return airplane;}

Airplane *AirplaneParser::getAirplane() {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    return airplane;
}

unsigned int AirplaneParser::Statuscheck(string St) {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
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

bool AirplaneParser::properlyInitialised() {
    return initCheck == this;
}

unsigned int AirplaneParser::Enginecheck(string En) {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    if (En== "jet"){
        return Jet;
    }
    if (En== "propeller"){
        return Propeller;
    }
    return  -1;

}

unsigned int AirplaneParser::Typecheck(string Ty) {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    if (Ty== "private"){
        return Private;
    }
    if (Ty== "militairy"){
        return Militairy;
    }
    if (Ty== "airline"){
        return Airline;
    }
    if (Ty== "emergency"){
        return Emergency;
    }
    return -1;
}

unsigned int AirplaneParser::Sizecheck(string Si) {
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    if (Si== "small"){
        return Small;
    }
    if (Si== "medium"){
        return Medium;
    }
    if (Si== "large"){
        return Large;
    }
    return 0;
}
