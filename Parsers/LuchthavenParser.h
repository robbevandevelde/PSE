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
    * PRE:Must be Properly initialised, Have 2 vectors as input
    * POST:runway is added to airport if needed
    */
    void isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Runways is returned as vector
    */
    vector<Runway*> getRunways();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Airplanes is returned as vector
    */
    vector<Airplane*> getAirplanes();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Airports is returned as vector
    */
    vector<Airport*> getAirports();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Luchthaven has been constructed
    */
    LuchthavenParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~LuchthavenParser();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Items must be parsed
    */
    void parseItems(TiXmlElement* elem);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Information has been written to file
    */
    void writeToFile(vector<Runway*> runwaysVect, vector<Airport*> airportsVect, vector<Airplane*> airplanesVect);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:file is loaded in
    */
    bool loadFile(string filename);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Element Root is returned
    */
    TiXmlElement *getRoot();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Root has been set to given element
    */
    void setRoot(TiXmlElement *root);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Enum is returend
    */
    SuccessEnum getSuccessEnum();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Succes enum has been set to given item
    */
    void setSuccessEnum(SuccessEnum successEnum);
};


#endif //PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H
