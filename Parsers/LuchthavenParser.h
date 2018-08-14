/*Parse de xml file en gebruikt andere parsers als hulpmechanisme
 *@Author: Robbe
 *@Date: 05/06/2018
 */

#ifndef PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H
#define PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H

#include <vector>
#include <string>
#include <fstream>
#include "AirplaneParser.h"
#include "AirportParser.h"
#include "RunwayParser.h"
#include "../TinyXML/tinyxml.h"
#include "../Runway.h"
#include "../Airplane.h"
#include "../Airport.h"
enum SuccessEnum {ImportAborted, PartialImport, Success};

class LuchthavenParser{
private:
    vector<Runway*> runways;
    vector<Airplane*> airplanes;
    vector<Airport*> airports;
    TiXmlDocument doc;
    TiXmlElement * root;
    SuccessEnum successEnum;
    LuchthavenParser* initCheck;

public:

    bool properlyInitialised();
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    void isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect);
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    vector<Runway*> getRunways();
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    vector<Airplane*> getAirplanes();
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    vector<Airport*> getAirports();
    //    ENSURE(properlyInitialised(), "Constructor must end");
    LuchthavenParser();
    //    ENSURE(properlyInitialised(), "Destructor must end");
    virtual ~LuchthavenParser();

    //    REQUIRE(elemName == "RUNWAY" || elemName == "AIRPLANE" || elemName == "AIRPORT", "The element is not recognised");
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    void parseItems(TiXmlElement* elem);
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    void writeToFile(vector<Runway*> runwaysVect, vector<Airport*> airportsVect, vector<Airplane*> airplanesVect, string name);
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    bool loadFile(string filename);
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    TiXmlElement *getRoot();
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    void setRoot(TiXmlElement *root);
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    SuccessEnum getSuccessEnum();
    //    REQUIRE(this->properlyInitialised(), "Parser wasn't properly initialised when calling loadFile()");
    void setSuccessEnum(SuccessEnum successEnum);
};


#endif //PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H
