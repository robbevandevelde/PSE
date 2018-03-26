/*Hulpcklasse voor de mainparser
 *@Author: Robbe
 *@Date: 05/06/2018
 */


#ifndef PARSER_RUNWAYPARSER_H
#define PARSER_RUNWAYPARSER_H
#include <string>
#include "../Runway.h"
#include "Parser.h"
#include "../TinyXML/tinyxml.h"
using namespace std;

class RunwayParser: public Parser {
private:

    string readElement(TiXmlElement* elem, const char* tag);
    Runway* runway;
public:
    RunwayParser();
    virtual ~RunwayParser();
    Runway* parseRunway(TiXmlElement* elem);

    Runway* getRunway();
};






#endif //PARSER_RUNWAYPARSER_H
