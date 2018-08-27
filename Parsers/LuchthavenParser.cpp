//
// Created by robbe on 19/03/2018.
//

#include "LuchthavenParser.h"

/*
 * returns runways vect
 * @param none
 * @return reunways vector
 */
vector<Runway *> LuchthavenParser::getRunways()
{
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getRunways");
    return runways;
}

/*
 * returns airplanes vect
 * @param none
 * @returnairplanes vector
 */vector<Airplane *> LuchthavenParser::getAirplanes()
{
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getAirplanes");
    return airplanes;
}
/*
 * returns airports vect
 * @param none
 * @return vector of airports
 */
vector<Airport *> LuchthavenParser::getAirports()
{
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getAirports");
    return airports;
}
/*
 * constructs parser
 */
LuchthavenParser::LuchthavenParser()
{
    runways = vector<Runway*>();
    airplanes= vector<Airplane*>();
    airports = vector<Airport*>();
    initCheck = this;
    ENSURE(properlyInitialised(), "Constructor must end");
}

/*
 * destructs parser
 */
LuchthavenParser::~LuchthavenParser()
{
    ENSURE(properlyInitialised(), "Destructor must end");

}

/*Kijkt na of bepaalde runways aan een airport kan worden toegevoegd
 *@param vector van runways en airport
 *@return niks void functie
 */
void LuchthavenParser::isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect)
{
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
 *@param file naam
 *@return niks void functie
 */
void LuchthavenParser::parseItems(const char* file) {

    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling parseItems()");
    successEnum = ImportAborted;
    TiXmlDocument doc;
    if (!doc.LoadFile(file)) {
        cerr << doc.ErrorDesc() << endl;
    }
    string elemName = root->Value();
    REQUIRE(elemName == "SIMULATIE", "The simulation could not start");
    if (elemName == "SIMULATIE") {
        for (TiXmlElement *e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
            string elemName = e->Value();
            REQUIRE(elemName == "RUNWAY" || elemName == "AIRPLANE" || elemName == "AIRPORT",
                    "The element is not recognised");

            if (elemName == "AIRPORT") {
                AirportParser apop;
                Airport *apo = apop.parseAirport(e);
                airports.push_back(apo);
            }
            if (elemName == "RUNWAY") {
                RunwayParser rwp;
                Runway *rw = rwp.parseRunway(e);
                bool hasAirport = false;
                for(unsigned int i= 0; i < airports.size();i++){
                    if(airports[i]->getIata() == rw->getAirport()){
                        hasAirport = true;
                    }
                }
                if(hasAirport == false){
                    cerr<< "There was no existing Airport assigned to that runway"<<endl;
                }
                runways.push_back(rw);
            }
            if (elemName == "AIRPLANE") {
                AirplaneParser aplp;
                Airplane *apl = aplp.parseAirplane(e);
                airplanes.push_back(apl);
            }
        }
        if(airports.size() == 0 and runways.size() == 0 and airplanes.size() == 0){
            setSuccessEnum(ImportAborted);
            cerr<<"Import has been aborted"<<endl;
        }
        else if(airports.size() != 0 and runways.size() != 0 and airplanes.size() != 0){
            setSuccessEnum(Success);
        }
        else{
            setSuccessEnum(PartialImport);
        }
    }

}

/*Loopt over de verschillende vectoren en print deze uit in een file in het juiste formaat
 *@param alle vectoren
 *@return niks void functie
 */
void LuchthavenParser::writeToFile(vector<Runway *> runwaysVect, vector<Airport *> airportsVect,
                                   vector<Airplane *> airplanesVect, string name)
{
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling writeToFile()");
    ofstream myfile;
    myfile.open(name.c_str());
    for (unsigned int itAPO=0 ; itAPO < airportsVect.size(); itAPO++) {
        myfile << "Airport: "<< airportsVect[itAPO]->getName() << " (" << airportsVect[itAPO]->getIata()<<")"<< endl;
        myfile <<"-> gates: "<< airportsVect[itAPO]->getGatesize() << endl;
        myfile <<"-> runways: "<<  runwaysVect.size() << endl;
        myfile << "\n";

    }


    for (unsigned int itAPL=0 ; itAPL < airplanesVect.size(); itAPL++)
    {
        myfile << "Airplane: "<< airplanesVect[itAPL]->getCallsign() << " (" << airplanesVect[itAPL]->getNumber()<<")"<< endl;
        myfile <<"-> model: "<< airplanesVect[itAPL]->getModel() << endl;
        if(airplanesVect[itAPL]->getType() == 0){
            myfile <<"-> type: Private" << endl;
        }
        if(airplanesVect[itAPL]->getType() == 1){
            myfile <<"-> type: Airline" << endl;
        }
        if(airplanesVect[itAPL]->getType() == 2){
            myfile <<"-> type: Military" << endl;
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
        myfile << "\n";
        }


    myfile.close();

}
/*
 * loads the given file, requires right syntax
 * @param filename
 * @return bool
 */
bool LuchthavenParser::loadFile(string filename)
{
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    bool result = doc.LoadFile(filename.c_str());
    REQUIRE(result, "Error reading the end or begin tags");

    root = doc.FirstChildElement();
    REQUIRE(root!=NULL, "root cannot be NULL");
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
TiXmlElement *LuchthavenParser::getRoot()
{
    REQUIRE(root!= NULL, "Root is not found");
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getRoot");
    return root;
}
/*
 * sets the given element as root
 */
void LuchthavenParser::setRoot(TiXmlElement *root)
{
    LuchthavenParser::root = root;
}
/*
 * returns the succesEnum
 */
SuccessEnum LuchthavenParser::getSuccessEnum()
{
    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling getSuccesEnum");
    return successEnum;
}
/*
 * sets succesenum
 */
void LuchthavenParser::setSuccessEnum(SuccessEnum successEnum)
{
    LuchthavenParser::successEnum = successEnum;
}
/*
 * propely initialised function
 */
bool LuchthavenParser::properlyInitialised()
{
    return initCheck == this;
}

