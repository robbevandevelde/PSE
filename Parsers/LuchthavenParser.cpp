//
// Created by robbe on 19/03/2018.
//

#include "LuchthavenParser.h"

//Return vector runways
vector<Runway *> LuchthavenParser::getRunways() {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getRunways");
    return runways;
}

//REturn vector airplanes
vector<Airplane *> LuchthavenParser::getAirplanes() {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getAirplanes");
    return airplanes;
}

//Return vector airports
vector<Airport *> LuchthavenParser::getAirports() {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getAirports");
    return airports;
}

//Default constructor
LuchthavenParser::LuchthavenParser() {
    runways = vector<Runway*>();
    airplanes= vector<Airplane*>();
    airports = vector<Airport*>();
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

//Default destructor
LuchthavenParser::~LuchthavenParser() {
    ENSURE(properlyInitialised(), "Destructor must end");

}

/*Kijkt na of bepaalde runways aan een airport kan worden toegevoegd
 *@param vector van runways en airport
 *@return niks void functie
 */
void LuchthavenParser::isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect){
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling isRunAirEqual()");
    for(unsigned int RW = 0; RW < runwaysVect.size(); RW++){
        for(unsigned int AIR = 0; AIR < airportsVect.size(); AIR++){
            if (runwaysVect[RW]->getAirport() == airportsVect[AIR]->getIata())
            {
                airportsVect[AIR]->addRunway(runwaysVect[RW]);
            }
        }
    }
}

/*Kijkt eerst na of dat datatype runway of airplane is en gebruikt dan de juiste parser van de hulpparsers om het te parsen
 *@param eerste element van xml file
 *@return niks void functie
 */
void LuchthavenParser::parseItems(TiXmlElement *elem) {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling parseItems()");
    successEnum = ImportAborted;
    if (elem != NULL) {
        for (TiXmlElement *e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
            string elemName = e->Value();
            if (elemName == "RUNWAY") {
                RunwayParser rwp;
                Runway *rw = rwp.parseRunway(e);
                //if(rw->isConsistent()){
                runways.push_back(rw);
                successEnum= Success;

                //}
            }
            if (elemName == "AIRPLANE") {
                AirplaneParser aplp;
                Airplane *apl = aplp.parseAirplane(e);
                //if(apl->isConsistent()){
                airplanes.push_back(apl);
                successEnum= Success;

                //}
            }
            if (elemName == "AIRPORT") {
                AirportParser apop;
                Airport *apo = apop.parseAirport(e);
                //if(apo->isConsistent()){
                airports.push_back(apo);
                successEnum= Success;

                //}
            }
        }
    }
}

/*Loopt over de verschillende vectoren en print deze uit in een file in het juiste formaat
 *@param alle vectoren
 *@return niks void functie
 */
void LuchthavenParser::writeToFile(vector<Runway *> runwaysVect, vector<Airport *> airportsVect,
                                   vector<Airplane *> airplanesVect) {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling writeToFile()");
    ofstream myfile;
    myfile.open ("Simulation.txt");
    for (unsigned int itAPO=0 ; itAPO < airportsVect.size(); itAPO++) {
        myfile << "\n";
        myfile << "Airport: "<< airportsVect[itAPO]->getName() << " (" << airportsVect[itAPO]->getIata()<<")"<< endl;
        myfile <<"-> gates: "<< airportsVect[itAPO]->getGatesize() << endl;
        myfile <<"-> runways: "<<  runwaysVect.size() << endl;
    }


    for (unsigned int itAPL=0 ; itAPL < airplanesVect.size(); itAPL++) {
        myfile << "\n";
        myfile << "Airplane: "<< airplanesVect[itAPL]->getCallsign() << " (" << airplanesVect[itAPL]->getNumber()<<")"<< endl;
        myfile <<"-> model: "<< airplanesVect[itAPL]->getModel() << endl;
        if(airplanesVect[itAPL]->getType() == 0){
            myfile <<"-> type: Private" << endl;
        }
        if(airplanesVect[itAPL]->getType() == 1){
            myfile <<"-> type: Airline" << endl;
        }
        if(airplanesVect[itAPL]->getType() == 2){
            myfile <<"-> type: Militairy" << endl;
        }
        if(airplanesVect[itAPL]->getType() == 3){
            myfile <<"-> type: Emergency" << endl;
        }
        if(airplanesVect[itAPL]->getEngine() == 0){
            myfile <<"-> engine: Propeller"<< endl;
        }
        if(airplanesVect[itAPL]->getEngine() == 1){
            myfile <<"-> engine: Jet"<< endl;
        }
        if(airplanesVect[itAPL]->getSize() == 0){
            myfile <<"-> size: Small"<< endl;
        }
        if(airplanesVect[itAPL]->getSize() == 1){
            myfile <<"-> size: Medium"<< endl;
        }
        if(airplanesVect[itAPL]->getSize() == 2){
            myfile <<"-> size: Large"<< endl;
        }
        }

    myfile.close();

}
/*
 * loads the given file
 */
bool LuchthavenParser::loadFile(string filename) {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    if(!doc.LoadFile(filename.c_str())){
        cerr << doc.ErrorDesc() << endl;
        return false;
    }

    root = doc.FirstChildElement();
    if(root == NULL){
        cerr << "Failed to load file: No root element." << endl;
        doc.Clear();
        return false;
    }
    return true;
}
/*
 * returns te element that is the root
 */
TiXmlElement *LuchthavenParser::getRoot() {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getRoot");
    return root;
}
/*
 * sets the given element as root
 */
void LuchthavenParser::setRoot(TiXmlElement *root) {
    LuchthavenParser::root = root;
}
/*
 * returns the succesEnum
 */
SuccessEnum LuchthavenParser::getSuccessEnum() {
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getSuccesEnum");
    return successEnum;
}
/*
 * sets succesenum
 */
void LuchthavenParser::setSuccessEnum(SuccessEnum successEnum) {
    LuchthavenParser::successEnum = successEnum;
}
/*
 * propely initialised function
 */
bool LuchthavenParser::properlyInitialised() {
    return initCheck == this;
}

