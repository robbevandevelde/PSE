//
// Created by robbe on 19/03/2018.
//

#include "LuchthavenParser.h"

//Return vector runways
vector<Runway *> LuchthavenParser::getRunways() const {
    return runways;
}

//REturn vector airplanes
vector<Airplane *> LuchthavenParser::getAirplanes() const {
    return airplanes;
}

//Return vector airports
vector<Airport *> LuchthavenParser::getAirports() const {
    return airports;
}

//Default constructor
LuchthavenParser::LuchthavenParser() {

}

//Default destructor
LuchthavenParser::~LuchthavenParser() {

}

/*Kijkt na of bepaalde runways aan een airport kan worden toegevoegd
 *@param vector van runways en airport
 *@return niks void functie
 */
void LuchthavenParser::isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect){
    for(unsigned int RW = 0; RW < runwaysVect.size(); RW++){
        for(unsigned int AIR = 0; AIR < airportsVect.size(); AIR++){
            if (runwaysVect[RW]->getAirport() == airportsVect[AIR]->getIata())
            {
                airportsVect[AIR]->addRunway(*runwaysVect[RW]);
            }
        }
    }
}

/*Kijkt eerst na of dat datatype runway of airplane is en gebruikt dan de juiste parser van de hulpparsers om het te parsen
 *@param eerste element van xml file
 *@return niks void functie
 */
void LuchthavenParser::parseItems(TiXmlElement *elem) {
    for(TiXmlElement* e = elem->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
        string elemName = e->Value();
        if (elemName == "RUNWAY") {
            RunwayParser rwp;
            Runway* rw = rwp.parseRunway(e);
            //if(rw->isConsistent()){
                runways.push_back(rw);
            //}
        }
        if (elemName == "AIRPLANE") {
            AirplaneParser aplp;
            Airplane* apl= aplp.parseAirplane(e);
            //if(apl->isConsistent()){
                airplanes.push_back(apl);
            //}
        }
        if (elemName == "AIRPORT") {
            AirportParser apop;
            Airport* apo= apop.parseAirport(e);
            //if(apo->isConsistent()){
                airports.push_back(apo);
            //}
        }
    }
}

/*Loopt over de verschillende vectoren en print deze uit in een file in het juiste formaat
 *@param alle vectoren
 *@return niks void functie
 */
void LuchthavenParser::writeToFile(vector<Runway *> runwaysVect, vector<Airport *> airportsVect,
                                   vector<Airplane *> airplanesVect) {
    ofstream myfile;
    myfile.open ("Simulation.txt");
    for (unsigned int itAPO=0 ; itAPO < airportsVect.size(); itAPO++) {
        myfile << "\n";
        myfile << "Airport: "<<airportsVect[itAPO]->getName() << " (" << airportsVect[itAPO]->getIata()<<")"<< endl;
        myfile <<"-> gates: "<<  airportsVect[itAPO]->getGates() << endl;
        myfile <<"-> runways: "<<  runwaysVect.size() << endl;
    }


    for (unsigned int itAPL=0 ; itAPL < airplanesVect.size(); itAPL++) {
        myfile << "\n";
        myfile << "Airplane: "<< airplanesVect[itAPL]->getCallsign() << " (" << airplanesVect[itAPL]->getNumber()<<")"<< endl;
        myfile <<"-> model: "<<  airplanesVect[itAPL]->getModel() << endl;
    }

    myfile.close();

}

