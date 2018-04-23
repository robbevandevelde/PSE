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
    string Type = readElement(elem, "type");
    runway->setType(Type);
    string Length = readElement(elem, "length");
    runway->setLength(atoi(Length.c_str()));
//    for (TiXmlElement *e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
//        string elemName = e->Value();
//        if (elemName == "TAXIROUTE") {
//            Taxiroute* taxiroute = new Taxiroute;
//            string taxipoint1 = readElement(e, "taxipoint");
//            taxiroute->setTaxipoint1(taxipoint1);
//            string crossing = readElement(e, "crossing");
//            taxiroute->setCrossing(crossing);
//            string taxipoint2 = readElement(e, "taxipoint");
//            taxiroute->setTaxipoint2(taxipoint2);
//            runway->pushbackTaxi(taxiroute);
//        }
//    }
    return runway;}

Runway *RunwayParser::getRunway() {
    return runway;
}
