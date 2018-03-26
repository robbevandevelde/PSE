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

class LuchthavenParser: public Parser {
private:
    vector<Runway*> runways;
    vector<Airplane*> airplanes;
    vector<Airport*> airports;
public:
    void isRunAirEqual(vector<Runway*> runwaysVect, vector<Airport*> airportsVect);
    vector<Runway*> getRunways() const;

    vector<Airplane*> getAirplanes() const;

    vector<Airport*> getAirports() const;

    LuchthavenParser();

    virtual ~LuchthavenParser();

    void parseItems(TiXmlElement* elem);

    void writeToFile(vector<Runway*> runwaysVect, vector<Airport*> airportsVect, vector<Airplane*> airplanesVect);

};


#endif //PROJECT_SOFTWARE_ENGINEERING_LUCHTHAVENPARSER_H
