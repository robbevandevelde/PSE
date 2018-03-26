//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "RunwayParser.h"

string RunwayParser::readElement(TiXmlElement *elem, const char *tag) {
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();}

RunwayParser::RunwayParser() {
    runway= new Runway();

}

RunwayParser::~RunwayParser() {

}

Runway *RunwayParser::parseRunway(TiXmlElement *elem) {
    string Airport = readElement(elem, "airport");
    runway->setAirport(Airport);
    string Name = readElement(elem, "name");
    runway->setName(Name);

    return runway;}

Runway *RunwayParser::getRunway() {
    return runway;
}
