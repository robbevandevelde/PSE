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
    * PRE:
    * POST:
    */
    RunwayParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~RunwayParser();
    /* Contract
    * PRE:
    * POST:
    */
    Runway* parseRunway(TiXmlElement* elem);
    /* Contract
    * PRE:
    * POST:
    */
    Runway* getRunway();
    /* Contract
    * PRE:
    * POST:
    */
};






#endif //PARSER_RUNWAYPARSER_H
