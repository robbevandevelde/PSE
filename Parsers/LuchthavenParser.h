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
    void isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect);
    vector<Runway*> getRunways();

    vector<Airplane*> getAirplanes();

    vector<Airport*> getAirports();

    LuchthavenParser();

    virtual ~LuchthavenParser();

    void parseItems(TiXmlElement* elem);

    void writeToFile(vector<Runway*> runwaysVect, vector<Airport*> airportsVect, vector<Airplane*> airplanesVect);

    bool loadFile(string filename);

    TiXmlElement *getRoot();

    void setRoot(TiXmlElement *root);

    SuccessEnum getSuccessEnum();

    void setSuccessEnum(SuccessEnum successEnum);
};


#endif //PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H
