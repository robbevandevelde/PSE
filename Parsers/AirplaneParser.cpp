//
// Created by Robbe Van de Velde on 7/03/18.
//

#include <iostream>
#include "AirplaneParser.h"
#include "FlightplanParser.h"
/*
 * reads element
 * @param, xml element and tag
 * @return string of value
 */
string AirplaneParser::readElement(TiXmlElement *elem, const char *tag)
{
    REQUIRE(this->properlyInitialised(), "AirplaneParser wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    REQUIRE(e != NULL, "Please check if the tags in airplane are either: model, number, callsign, status, passengers, fuel, type, engine or size.");
    TiXmlNode* node = e->FirstChild();
    REQUIRE(node != NULL, "An item in aiplane is none, cannot parse further");
    TiXmlText* text = node->ToText();
    ENSURE(text != NULL, "the element cannot be none");
    return text->Value();
}
/*
 * constructor
 */
AirplaneParser::AirplaneParser()
{
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}
/*
 * destructor
 */
AirplaneParser::~AirplaneParser()
{
    ENSURE(properlyInitialised(), "Constructor must end");

}
/*
 * parses all the elements
 * @param XML element
 * @return Airplane
 */
Airplane *AirplaneParser::parseAirplane(TiXmlElement *elem)
{
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
    REQUIRE(Number != "", "Number cannot be set to none");
    REQUIRE(Model != "", "Model cannot be set to none");
    REQUIRE(Callsign != "", "Callsign cannot be set to none");
    REQUIRE(Status != "", "Status cannot be set to none");
    REQUIRE(readElement(elem, "passengers") != "", "Passengers cannot be set to none");
    REQUIRE(readElement(elem, "fuel") != "", "Fuel cannot be set to none");
    REQUIRE(Type != "", "Type cannot be set to none");
    REQUIRE(Engine != "", "Engine cannot be set to none");
    REQUIRE(Size != "", "Size cannot be set to none");
    Airplane* airplane = new Airplane(Number, Callsign, Model, Statuscheck(Status), Passengers, Fuel, Typecheck(Type),
                                      Enginecheck(Engine), Sizecheck(Size), fp);
    ENSURE( airplane->getNumber() == Number, "number not equal");
    ENSURE( airplane->getCallsign() == Callsign, "Callsign not equal");
    ENSURE( airplane->getModel() == Model, "Model not equal");
    ENSURE( airplane->getStatus() == Statuscheck(Status), "Status not equal");
    ENSURE( airplane->getFuel() == Fuel, "Fuel not equal");
    ENSURE( airplane->getType() == Typecheck(Type), "Type not equal");
    ENSURE( airplane->getEngine() == Enginecheck(Engine), "Engine not equal");
    ENSURE( airplane->getSize() == Sizecheck(Size), "Size not equal");
    ENSURE( airplane->getFlightplan() == fp, "Flightplan not equal");

    return airplane;}
/*
 * returns airplane
 * @param none
 * @return airplane
 */
Airplane *AirplaneParser::getAirplane()
{
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    return airplane;
}
/*
 * gives strings the right enum
 * @param the string
 * @return enum
 */
unsigned int AirplaneParser::Statuscheck(string St)
{
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
    if(St == "WaitingAtRunway"){
        return WaitingAtRunway;
    }
    if(St == "StandingAtRunway"){
        return StandingAtRunway;
    }
    if(St == "FinalApproach"){
        return FinalApproach;
    }
    if(St == "EmergencyLanding"){
        return EmergencyLanding;
    }
    if(St == "EmergencyControle1"){
        return EmergencyControle1;
    }
    if(St == "EmergencyControle2"){
        return EmergencyControle2;
    }
    return -1;
}

bool AirplaneParser::properlyInitialised()
{
    return initCheck == this;
}
/*
 * gives strings the right enum
 * @param the string
 * @return enum
 */
unsigned int AirplaneParser::Enginecheck(string En)
{
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    if (En== "jet"){
        return Jet;
    }
    if (En== "propeller"){
        return Propeller;
    }
    return  -1;

}
/*
 * gives strings the right enum
 * @param the string
 * @return enum
 */
unsigned int AirplaneParser::Typecheck(string Ty)
{
    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    if (Ty== "private"){
        return Private;
    }
    if (Ty== "military"){
        return Military;
    }
    if (Ty== "airline"){
        return Airline;
    }
    if (Ty== "emergency"){
        return Emergency;
    }
    return -1;
}
/*
 * gives strings the right enum
 * @param the string
 * @return enum
 */
unsigned int AirplaneParser::Sizecheck(string Si)
{
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
