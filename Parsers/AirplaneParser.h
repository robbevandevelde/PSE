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

    string readElement(TiXmlElement* elem, const char* tag);
    Airplane* airplane;
public:
    AirplaneParser();
    virtual ~AirplaneParser();
    Airplane* parseAirplane(TiXmlElement* elem);
    Airplane* getAirplane();
    unsigned int Statuscheck(string St);
};


#endif //PARSER_AIRPLANEPARSER_H
