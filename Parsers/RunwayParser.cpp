//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "RunwayParser.h"
/*
 * reads element
 * @param, xml element and tag
 * @return string of value
 */
string RunwayParser::readElement(TiXmlElement *elem, const char *tag)
{
    REQUIRE(this->properlyInitialised(), "RunwayParser wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    REQUIRE(e != NULL, "Please check if the tags in runway are either: airport, type or length.");
    TiXmlNode* node = e->FirstChild();
    REQUIRE(node != NULL, "An item in airport is none, cannot parse further");
    TiXmlText* text = node->ToText();
    ENSURE(text != NULL, "the element cannot be none");
    return text->Value();
}
/*
 * constructor
 */
RunwayParser::RunwayParser()
{
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");

}
/*
 * destructor
 */
RunwayParser::~RunwayParser()
{

}
/*
 * parses al the elements
 * @param XML element
 * @return runway
 */
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
/*
 * returns runway
 * @param none
 * @return runway
 */
Runway *RunwayParser::getRunway()
{
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    return runway;
}

bool RunwayParser::properlyInitialised()
{
    return initCheck == this;
}
/*
 * gives strings the right enum
 * @param the string
 * @return enum
 */
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
