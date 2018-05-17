/*Hulpcklasse voor de mainparser
 *@Author: Robbe
 *@Date: 05/06/2018
 */


#ifndef PARSER_RUNWAYPARSER_H
#define PARSER_RUNWAYPARSER_H
#include <string>
#include "../Runway.h"
#include "../TinyXML/tinyxml.h"
#include "../DesignByContract.h"
using namespace std;

class RunwayParser{
private:
    RunwayParser* initCheck;
    string readElement(TiXmlElement* elem, const char* tag);
    Runway* runway;
public:
    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Runwayparser has been constructed
    */
    RunwayParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~RunwayParser();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Runway elements are parsed
    */
    Runway* parseRunway(TiXmlElement* elem);
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Runway is returned
    */
    Runway* getRunway();

    unsigned int rwTypeCheck(string rw);


};






#endif //PARSER_RUNWAYPARSER_H
