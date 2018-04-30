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

}

RunwayParser::~RunwayParser() {

}

Runway *RunwayParser::parseRunway(TiXmlElement *elem) {
    string Airport = readElement(elem, "airport");
    string Name = readElement(elem, "name");
    string Type = readElement(elem, "type");
    unsigned int Length = atoi(readElement(elem, "length").c_str());
    Runway* runway = new Runway(Length, Name, Type, Airport);
    for (TiXmlElement *e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        string elemName = e->Value();
//        if (elemName == "TAXIROUTE") {
//            for(TiXmlElement * p = e->FirstChildElement(); p != NULL; p = e->NextSiblingElement()){
//                string elnm = e->Value();
//                string txpt;
//                string crs;
//                if (elnm == "taxipoint"){
//                    txpt = readElement(e, "taxipoint");
//                    cout<< elnm<<"!!fefefefe"<<endl;
//                }
//                if (elnm == "crossing"){
//                    crs = readElement(e, "crossing");
//                    cout<<crs<< "111111111111"<<endl;
//                }
////                Taxiroute *taxiroute = new Taxiroute(txpt, crs);
//
//            }
//            vector <Taxiroute*> taxi;
//            string taxipoint1 = readElement(e, "taxipoint");
//            string crossing = readElement(e, "crossing");
//            string taxipoint2 = readElement(e, "taxipoint");
//
//            cout << taxipoint1 << endl;
//            cout << crossing << endl;
//            Taxiroute *taxiroute = new Taxiroute(taxipoint1, crossing);
//            taxi.push_back(taxiroute);
//            runway->setTaxiRoute(taxi);
//        }
    }
    return runway;}

Runway *RunwayParser::getRunway() {
    return runway;
}
