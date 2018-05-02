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
    * PRE:
    * POST:
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
    * PRE:
    * POST:
    */
    Airplane* getAirplane();
    /* Contract
    * PRE:
    * POST:
    */
    unsigned int Statuscheck(string St);
};


#endif //PARSER_AIRPLANEPARSER_H
