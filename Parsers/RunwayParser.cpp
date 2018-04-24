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
    runway->setLength(stoi(Length.c_str()));
    for (TiXmlElement *e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        string elemName = e->Value();
        if (elemName == "TAXIROUTE") {
            vector <Taxiroute*> taxi;
            string taxipoint1 = readElement(e, "taxipoint");
            string crossing = readElement(e, "crossing");
            string taxipoint2 = readElement(e, "taxipoint");

            cout << taxipoint1 << endl;
            cout << crossing << endl;
            Taxiroute *taxiroute = new Taxiroute(taxipoint1, crossing);
            taxi.push_back(taxiroute);
            runway->setTaxiRoute(taxi);
        }
    }
    return runway;}

Runway *RunwayParser::getRunway() {
    return runway;
}
