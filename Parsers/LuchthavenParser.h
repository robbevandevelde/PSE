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
    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();
    /* Contract
    * PRE:
    * POST:
    */
    void isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect);
    /* Contract
    * PRE:
    * POST:
    */
    vector<Runway*> getRunways();
    /* Contract
    * PRE:
    * POST:
    */
    vector<Airplane*> getAirplanes();
    /* Contract
    * PRE:
    * POST:
    */
    vector<Airport*> getAirports();
    /* Contract
    * PRE:
    * POST:
    */
    LuchthavenParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~LuchthavenParser();
    /* Contract
    * PRE:
    * POST:
    */
    void parseItems(TiXmlElement* elem);
    /* Contract
    * PRE:
    * POST:
    */
    void writeToFile(vector<Runway*> runwaysVect, vector<Airport*> airportsVect, vector<Airplane*> airplanesVect);
    /* Contract
    * PRE:
    * POST:
    */
    bool loadFile(string filename);
    /* Contract
    * PRE:
    * POST:
    */
    TiXmlElement *getRoot();
    /* Contract
    * PRE:
    * POST:
    */
    void setRoot(TiXmlElement *root);
    /* Contract
    * PRE:
    * POST:
    */
    SuccessEnum getSuccessEnum();
    /* Contract
    * PRE:
    * POST:
    */
    void setSuccessEnum(SuccessEnum successEnum);
};


#endif //PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H
