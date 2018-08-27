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
    //    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    //    REQUIRE(e != NULL, "Please check if the tags in runway are either: airport, type or length.");
    //    REQUIRE(node != NULL, "An item in airport is none, cannot parse further");
    //    ENSURE(text != NULL, "the element cannot be none");
    string readElement(TiXmlElement* elem, const char* tag);
    Runway* runway;
public:

    bool properlyInitialised();
    //    ENSURE(properlyInitialised(), "Constructor must end");
    RunwayParser();
    //    ENSURE(properlyInitialised(), "Constructor must end");
    virtual ~RunwayParser();
    //    REQUIRE(Airport != "", "Airport cannot be none");
    //    REQUIRE(Name != "", "Name cannot be none");
    //    REQUIRE(Type != "", "Type cannot be none");
    //    REQUIRE(readElement(elem, "length") != "", "Length cannot be none");
    //    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling parseRunway()");
    //    ENSURE(runway->getLength() == Length, "Length is not equal");
    //    ENSURE(runway->getName() == Name, "Length is not equal");
    //    ENSURE(runway->getType() == rwTypeCheck(Type), "Type is not equal");
    //    ENSURE(runway->getAirport() == Airport, "Airport is not equal");
    Runway* parseRunway(TiXmlElement* elem);
    //    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    Runway* getRunway();
    //    REQUIRE(this->properlyInitialised(), "RunwayParse wasn't properly initialised when calling readElement()");
    unsigned int rwTypeCheck(string rw);


};






#endif //PARSER_RUNWAYPARSER_H
