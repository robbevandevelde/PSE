//
// Created by Robbe Van de Velde on 7/03/18.
//

#include "RunwayParser.h"

string RunwayParser::readElement(TiXmlElement *elem, const char *tag) {
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    TiXmlElement* e = elem->FirstChildElement(tag);
    TiXmlNode* node = e->FirstChild();
    TiXmlText* text = node->ToText();
    return text->Value();}

RunwayParser::RunwayParser() {
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");

}

RunwayParser::~RunwayParser() {

}

Runway *RunwayParser::parseRunway(TiXmlElement *elem) {
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling parseRunway()");
    string Airport = readElement(elem, "airport");
    string Name = readElement(elem, "name");
    string Type = readElement(elem, "type");
    unsigned int Length = atoi(readElement(elem, "length").c_str());
    Runway* runway = new Runway(Length, Name, rwTypeCheck(Type), Airport);
    ENSURE(runway->getLength() == Length, "Length is not equal");
    ENSURE(runway->getName() == Name, "Length is not equal");
    ENSURE(runway->getType() == rwTypeCheck(Type), "Type is not equal");
    ENSURE(runway->getAirport() == Airport, "Airport is not equal");
//    for (TiXmlElement *e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
//        string elemName = e->Value();
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
//    }
    return runway;}

Runway *RunwayParser::getRunway() {
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    return runway;
}

bool RunwayParser::properlyInitialised() {
    return initCheck == this;
}

unsigned int RunwayParser::rwTypeCheck(string rw) {
    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    if(rw == "asphalt"){
        return Asphalt;
    }
    if(rw == "grass"){
        return Grass;
    }
    return 0;
}
