//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "RunwayParser.h"

string RunwayParser::readElement(TiXmlElement *elem, const char *tag)
{
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();}

RunwayParser::RunwayParser()
{
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");

}

RunwayParser::~RunwayParser()
{

}

Runway *RunwayParser::parseRunway(TiXmlElement *elem)
{
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling parseRunway()");
    string Airport = readElement(elem, "airport");
    string Name = readElement(elem, "name");
    string Type = readElement(elem, "type");
    unsigned int Length = atoi(readElement(elem, "length").c_str());
    REQUIRE(Airport != "", "Airport cannot be none");
    REQUIRE(Name != "", "Name cannot be none");
    REQUIRE(Type != "", "Type cannot be none");
    REQUIRE(readElement(elem, "length") != "", "Length cannot be none");
    Runway* runway = new Runway(Length, Name, rwTypeCheck(Type), Airport);
    ENSURE(runway->getLength() == Length, "Length is not equal");
    ENSURE(runway->getName() == Name, "Length is not equal");
    ENSURE(runway->getType() == rwTypeCheck(Type), "Type is not equal");
    ENSURE(runway->getAirport() == Airport, "Airport is not equal");
    return runway;}

Runway *RunwayParser::getRunway()
{
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    return runway;
}

bool RunwayParser::properlyInitialised()
{
    return initCheck == this;
}

unsigned int RunwayParser::rwTypeCheck(string rw)
{
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    if(rw == "asphalt"){
        return Asphalt;
    }
    if(rw == "grass"){
        return Grass;
    }
    return 0;
}
