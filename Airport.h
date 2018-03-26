/*Dit is de airport, dit bevat runways en gates en deze kunnen vliegtuig bevatten.
 *Airport heeft 3 belangrijke functies en dat zijn landing take off en gate protocols.
 *@Author: Thimoty
 *@Date: 06/03/2018
 */

#ifndef PARSER_AIRPORT_H
#define PARSER_AIRPORT_H

#include <string>
#include <algorithm>
#include <vector>
#include "Airplane.h"
#include "Gates.h"
#include "Runway.h"

using namespace std;
class Airport {
private:
    string Name;
    string iata;
    string callsign;
    int gate;
    int runws;
    bool isValidString(const string& str);
    vector<Gates> gates;
    vector<Runway> runways;

public:

    void setAmountOfGates(int amount);
    const vector<Runway> &getRunways() const;

    int getRunws() const;
    void addRunway( Runway & runway);
    void setRunws(int runws);
    void StandingAtGateprotocol(Airplane & airplane);
    bool Landingprotocol(Airplane& airplane);

    void TakeOffprotocol(Airplane& airplane);

    bool isGateEmpty();
    bool isRunwayEmpty();

    Airport();

    Airport(string airportname);

    ~Airport();

    const string &getName() const;

    void setName(const string &Name);

    const string &getIata() const;

    void setIata(const string &iata);

    const string &getCallsign() const;

    void setCallsign(const string &callsign);

    int getGates() const;

    void setGates(int gates);



};


#endif //PARSER_AIRPORT_H
