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
//int main() {
//    LuchthavenParser parser;
//    if(parser.loadFile("luchthaven.xml")){
//        parser.parseItems(parser.getRoot());
//
//        vector<Runway*> runwaysVect = parser.getRunways();
//        vector<Airport*> airportsVect = parser.getAirports();
//        vector<Airplane*> airplanesVect = parser.getAirplanes();
//        parser.isRunAirEqual(runwaysVect,airportsVect);
//        parser.writeToFile(runwaysVect, airportsVect, airplanesVect);
//
//        for (unsigned int itRW=0 ; itRW < runwaysVect.size(); itRW++) {
//            cout << "------------------------------------------\n";
//            cout << runwaysVect[itRW]->get_name() << endl;
//            cout << runwaysVect[itRW]->get_airport() << endl;
////            for (unsigned int taxIT=0 ; itRW < runwaysVect[itRW]->getTaxiRoute().size(); itRW++) {
////
////                cout << runwaysVect[itRW]->getTaxiRoute()[taxIT] << endl;
////            }
//            cout << runwaysVect[itRW]->get_length() << endl;
//            cout << runwaysVect[itRW]->get_type() << endl;
////            runwaysVect[itRW]->getTaxiRoute()[0];
//        }
//        for (unsigned int itAPO=0 ; itAPO < airportsVect.size(); itAPO++) {
//            cout << "------------------------------------------\n";
//            cout << airportsVect[itAPO]->get_name() << endl;
//            cout << airportsVect[itAPO]->get_iata() << endl;
//            cout << airportsVect[itAPO]->get_callsign() << endl;
//            cout << airportsVect[itAPO]->get_gatesize() << endl;
//        }
//        for (unsigned int itAPL=0 ; itAPL < airplanesVect.size(); itAPL++) {
//            cout << "------------------------------------------\n";
//            cout << airplanesVect[itAPL]->get_number() << endl;
//            cout << airplanesVect[itAPL]->get_callsign() << endl;
//            cout << airplanesVect[itAPL]->get_model() << endl;
//            cout << airplanesVect[itAPL]->get_status() << endl;
//            cout << "Type: " <<airplanesVect[itAPL]->get_type() << endl;
//            cout << "Engine: " <<airplanesVect[itAPL]->get_engine() << endl;
//            cout << "Size: " << airplanesVect[itAPL]->get_size() << endl;
//            cout << "Max Fuel: " << airplanesVect[itAPL]->get_fuel() << endl;
//            cout << "Max passengers: "<<airplanesVect[itAPL]->get_passengers() << endl;
//            cout << "Flightplan: "<<endl;
//            cout << "\tDeparture: "<<airplanesVect[itAPL]->get_Flightplan()->getDeparture()<<endl;
//            cout << "\tDest: "<<airplanesVect[itAPL]->get_Flightplan()->getDestination()<<endl;
//            cout << "\tArrival: "<<airplanesVect[itAPL]->get_Flightplan()->getArrival()<<endl;
//            cout << "\tInterval: "<<airplanesVect[itAPL]->get_Flightplan()->getInterval()<<endl;
//
//        }
//        cout << "------------------------------------------\n" << endl;
//        airportsVect[0]->completeLandingSequence(airplanesVect[0]);
////        airportsVect[0]->StandingAtGateprotocol(*airplanesVect[0]);
//    }else{
//        cout<< "unable to parse file" << endl;
//    }
//
//}
#include <iostream>
#include "Airplane.h"
#include "Runway.h"
#include "Airport.h"

int main() {
    std::string naam = "kanker";
    Flightplan* fl = new Flightplan(naam,5,6,7);
    Airplane* airplane = new Airplane("1","EF566","Winchester",Approaching,5,5, "tumor","5","6",fl);
    std::cout<< airplane->get_callsign() << std::endl;
    std::cout<< airplane->get_number() << std::endl;
    std::cout<< airplane->get_model() << std::endl;
    std::cout<< airplane->get_status() << std::endl;

    Airplane* airplane1 = new Airplane("556", "F16", "Win100", Approaching,5,5, "tumor","5","6",fl);

//    Runway runway(1,"boo", "blau", "donau");
//    runway.addAirplane(airplane);
//    runway.removeAirplane();
//    std::cout<< runway.get_type() << std::endl;
//    std::cout<< runway.get_airport() << std::endl;
//    std::cout<< runway.get_name() << std::endl;
//    std::cout<< runway.get_length() << std::endl;
//    std::cout<< runway.get_airplane() << std::endl;


    Runway* runway = new Runway(50, "kk", "hoertjeeeeee", "f444");
    Airport airport(2,"Zaventem","f444","Echo");
    airport.addRunway(runway);
    airport.completeLandingSequence(airplane);
    airport.completeLandingSequence(airplane1);
    airport.completeTakeOffsequence(airplane);
//    airplane->set_status(Approaching);
//    airplane->set_height(10000);
    airport.completeLandingSequence(airplane);
    return 0;
}