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
    //    REQUIRE(this->properlyInitialised(), "AirplaneParser wasn't properly initialised when calling readElement()");
    //    REQUIRE(node != NULL, "An item in aiplane is none, cannot parse further");
    //    ENSURE(text != NULL, "the element cannot be none");
    //    REQUIRE(e != NULL, "Please check if the tags in airplane are either: model, number, callsign, status, passengers, fuel, type, engine or size.")
    string readElement(TiXmlElement* elem, const char* tag);
    Airplane* airplane;
public:

    bool properlyInitialised();
    //    ENSURE(properlyInitialised(), "Constructor must end");
    AirplaneParser();
    //    ENSURE(properlyInitialised(), "Constructor must end");
    virtual ~AirplaneParser();

    //    REQUIRE(Number != "", "Number cannot be set to none");
    //    REQUIRE(Model != "", "Model cannot be set to none");
    //    REQUIRE(Callsign != "", "Callsign cannot be set to none");
    //    REQUIRE(Status != "", "Status cannot be set to none");
    //    REQUIRE(readElement(elem, "passengers") != "", "Passengers cannot be set to none");
    //    REQUIRE(readElement(elem, "fuel") != "", "Fuel cannot be set to none");
    //    REQUIRE(Type != "", "Type cannot be set to none");
    //    REQUIRE(Engine != "", "Engine cannot be set to none");
    //    REQUIRE(Size != "", "Size cannot be set to none");
    //    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling parseAirplane()");
    //    ENSURE( airplane->getNumber() == Number, "number not equal");
    //    ENSURE( airplane->getCallsign() == Callsign, "Callsign not equal");
    //    ENSURE( airplane->getModel() == Model, "Model not equal");
    //    ENSURE( airplane->getStatus() == Statuscheck(Status), "Status not equal");
    //    ENSURE( airplane->getFuel() == Fuel, "Fuel not equal");
    //    ENSURE( airplane->getType() == Typecheck(Type), "Type not equal");
    //    ENSURE( airplane->getEngine() == Enginecheck(Engine), "Engine not equal");
    //    ENSURE( airplane->getSize() == Sizecheck(Size), "Size not equal");
    //    ENSURE( airplane->getFlightplan() == fp, "Flightplan not equal");
    Airplane* parseAirplane(TiXmlElement* elem);
    //    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    Airplane* getAirplane();
    //    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    unsigned int Statuscheck(string St);
    //    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    unsigned int Enginecheck(string En);
    //    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    unsigned int Typecheck(string Ty);
    //    REQUIRE(this->properlyInitialised(), "airplaneParser wasn't properly initialised when calling readElement()");
    unsigned int Sizecheck(string Si);
};


#endif //PARSER_AIRPLANEPARSER_H
