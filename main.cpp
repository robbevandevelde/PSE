#include <iostream>
#include "TinyXML/tinyxml.h"
#include <string>
#include "Runway.h"
#include "Airport.h"
#include "Airplane.h"
#include "Parsers/LuchthavenParser.h"
/*
 * TODO: zorgen dat de geparsede runways worden toegevoegd aan de airports met dezelfde IATA (mss door in runway ipv string Airport , Airport airport te zetten)
 * Testfile(met happyday enz.) toevoegen
 * Makefile toevoegen
 * Codeconventions volgen
 *
 * Als dit klaart is: TODO: (robbe) isConsistent van airport en runway in orde maken!!!
 */

using namespace std;
int main() {
    LuchthavenParser parser;
    if(parser.loadFile("luchthaven.xml")){
        parser.parseItems(parser.getRoot());

        vector<Runway*> runwaysVect = parser.getRunways();
        vector<Airport*> airportsVect = parser.getAirports();
        vector<Airplane*> airplanesVect = parser.getAirplanes();
        parser.isRunAirEqual(runwaysVect,airportsVect);
        parser.writeToFile(runwaysVect, airportsVect, airplanesVect);

        for (unsigned int itRW=0 ; itRW < runwaysVect.size(); itRW++) {
            cout << "------------------------------------------\n";
            cout << runwaysVect[itRW]->getName() << endl;
            cout << runwaysVect[itRW]->getAirport() << endl;
//            for (unsigned int taxIT=0 ; itRW < runwaysVect[itRW]->getTaxiRoute().size(); itRW++) {
//
//                cout << runwaysVect[itRW]->getTaxiRoute()[taxIT] << endl;
//            }
            cout << runwaysVect[itRW]->getLength() << endl;
            cout << runwaysVect[itRW]->getType() << endl;
//            runwaysVect[itRW]->getTaxiRoute()[0];
        }
        for (unsigned int itAPO=0 ; itAPO < airportsVect.size(); itAPO++) {
            cout << "------------------------------------------\n";
            cout << airportsVect[itAPO]->getName() << endl;
            cout << airportsVect[itAPO]->getIata() << endl;
            cout << airportsVect[itAPO]->getCallsign() << endl;
            cout << airportsVect[itAPO]->getGates() << endl;
        }
        for (unsigned int itAPL=0 ; itAPL < airplanesVect.size(); itAPL++) {
            cout << "------------------------------------------\n";
            cout << airplanesVect[itAPL]->getNumber() << endl;
            cout << airplanesVect[itAPL]->getCallsign() << endl;
            cout << airplanesVect[itAPL]->getModel() << endl;
            cout << airplanesVect[itAPL]->getStatus() << endl;
            cout << "Type: " <<airplanesVect[itAPL]->getType() << endl;
            cout << "Engine: " <<airplanesVect[itAPL]->getEngine() << endl;
            cout << "Size: " << airplanesVect[itAPL]->getSize() << endl;
            cout << "Max Fuel: " << airplanesVect[itAPL]->getFuel() << endl;
            cout << "Max passengers: "<<airplanesVect[itAPL]->getPassengers() << endl;
            cout << "Flightplan: "<<endl;
//            cout << "\tDeparture: "<<airplanesVect[itAPL]->getFlightplan()->getDeparture()<<endl;
//            cout << "\tDest: "<<airplanesVect[itAPL]->getFlightplan()->getDestination()<<endl;
//            cout << "\tArrival: "<<airplanesVect[itAPL]->getFlightplan()->getArrival()<<endl;
//            cout << "\tInterval: "<<airplanesVect[itAPL]->getFlightplan()->getInterval()<<endl;
        }
        cout << "------------------------------------------\n" << endl;
//        airportsVect[0]->Landingprotocol(*airplanesVect[0]);
//        airportsVect[0]->StandingAtGateprotocol(*airplanesVect[0]);
    }else{
        cout<< "unable to parse file" << endl;
    }

}