/*Hulpcklasse voor de mainparser
 *@Author: Robbe
 *@Date: 05/06/2018
 */

#ifndef PARSER_AIRPLANEPARSER_H
#define PARSER_AIRPLANEPARSER_H
#include <string>
#include "../Airplane.h"
#include "../TinyXML/tinyxml.h"
using namespace std;

class AirplaneParser{
private:
    AirplaneParser* initCheck;
    string readElement(TiXmlElement* elem, const char* tag);
    Airplane* airplane;
public:
    /* Contract
    * PRE:
    * POST:
    */
    bool properlyInitialised();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:Must be constructed
    */
    AirplaneParser();
    /* Contract
    * PRE:
    * POST:
    */
    virtual ~AirplaneParser();
    /* Contract
    * PRE:
    * POST:
    */
    Airplane* parseAirplane(TiXmlElement* elem);
    /* Contract
    * PRE:Must be Properly initialised
    * POST: Airplane returned
    */
    Airplane* getAirplane();
    /* Contract
    * PRE:Must be Properly initialised
    * POST:status is returned(enum)
    */
    unsigned int Statuscheck(string St);
    unsigned int Enginecheck(string En);
    unsigned int Typecheck(string Ty);
    unsigned int Sizecheck(string Si);
};


#endif //PARSER_AIRPLANEPARSER_H
