#include <iostream>
#include "TinyXML/tinyxml.h"
#include <string>
#include "Runway.h"
#include "Airport.h"
#include "Airplane.h"
#include "Parsers/LuchthavenParser.h"
#include "Simulator.h"
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
//    LuchthavenParser* parser = new LuchthavenParser();
//    if(parser->loadFile("luchthaven.xml")){
//        parser->parseItems(parser->getRoot());
//
//        vector<Runway*> runwaysVect = parser->getRunways();
//        vector<Airport*> airportsVect = parser->getAirports();
//        vector<Airplane*> airplanesVect = parser->getAirplanes();
//        //parser.isRunAirEqual(runwaysVect,airportsVect);
//        parser->writeToFile(runwaysVect, airportsVect, airplanesVect, "simulatie.txt");
//        AirTrafficController* Alain = new AirTrafficController(airportsVect[0],"Alain Clement");
//        airportsVect[0]->assignController(Alain);
////        airportsVect[0]->completeLandingSequence(airplanesVect[0]);
////        airportsVect[0]->StandingAtGateprotocol(*airplanesVect[0]);
//        Simulator* sim = new Simulator(runwaysVect,airplanesVect,airportsVect[0]);
//        sim->addRunways();
//        sim->Simulate();
//        airplanesVect[0]->setStatus(8);
//        airplanesVect[0]->getStatus();
//    }else{
//        cout<< "unable to parse file" << endl;
//    }
////    Airport* testAirport = new Airport(10, "Antwerp Airport", "ANR", "callsign");
////    string name = "gggg";
////    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
////    Airplane* testAirplane = new Airplane("32", "callsign", "model", JustLanded, 110, 5000, 1, 1, 2, testFlightplan);
////    testAirport->landingprotocol(testAirplane);
//}
#include <iostream>
#include "Airplane.h"
#include "Runway.h"
#include "Airport.h"
#include "AirTrafficController.h"

/**
 *
 * TEST VOOR EMERGENCY LANDING
 */
int main() {

    Airport *airport = new Airport(10, "Zaventem", "f444", "Echo");


    AirTrafficController *John = new AirTrafficController(airport, "John");
    airport->assignController(John);

    std::string naam = "kanker";
    Flightplan *fl = new Flightplan(naam, 5, 6, 7);

    Airplane *airplane = new Airplane("Small", "Small Propeller", "Winchester", Approaching, 50, 50, Airline, Propeller, Small, fl);
    airplane->setHeight(4000);
    airplane->setFuel(0);
    Airplane *airplane1 = new Airplane("556", "F16", "Win100", Approaching, 50, 50, Airline, Jet, Medium, fl);
    airplane1->setHeight(4000);
    Airplane *airplane2 = new Airplane("6969", "HI99", "Wallonie", Approaching, 50,50 ,Airline, Jet, Medium, fl);
    airplane2->setHeight(4000);
    Airplane *airplane3 = new Airplane("420", "Allahu akbar", "Winchester", Approaching, 50, 50, Airline, Propeller, Small, fl);
    airplane3->setHeight(4000);

    Runway *runway = new Runway(500, "Alpha", Grass, "Zaventem");

    Runway *runway1 = new Runway(2000, "Bravo", Asphalt, "Zaventem");

    Runway *runway2 = new Runway(9000, "Charlie", Asphalt, "Zaventem");

    vector<Runway *> runways;

    runways.push_back(runway);
    runways.push_back(runway1);
    runways.push_back(runway2);

    vector<Airplane *> airplanes;
    airplanes.push_back(airplane);
    airplanes.push_back(airplane1);
    airplanes.push_back(airplane2);
    airplanes.push_back(airplane3);

    Simulator *sim = new Simulator(runways, airplanes, airport);
    sim->addRunways();
    sim->Simulate();
    return 0;
}
//int main(){
//    Airport *airport = new Airport(2, "Zaventem", "f444", "Echo");
//    AirTrafficController *John = new AirTrafficController(airport, "John");
//    airport->assignController(John);
//    std::string naam = "kanker";
//
//    //Runways
//    Flightplan *fl = new Flightplan(naam, 5, 6, 7);
//    Runway* runway = new Runway(3000, "Alpha", Asphalt, "Zaventem");
//    Runway* runway1 = new Runway(500,"Bravo", Grass, "Zaventem");
//    vector<Runway*> runways;
//    runways.push_back(runway);
//    runways.push_back(runway1);
//
//    //Airplanes
//    Airplane* airplane = new Airplane("Klein", "Propeller", "EF11",Approaching,50,50,Airline, Propeller, Small,fl);
//    airplane->setHeight(10000);
//    Airplane* airplane2 = new Airplane("Medium", "Jet","EFEF", Approaching, 50,50, Airline,Jet, Medium,fl);
//    vector<Airplane*> airplanes;
//    airplanes.push_back(airplane);
//    airplanes.push_back(airplane2);
//
//    Simulator* sim = new Simulator(runways,airplanes,airport);
//    sim->addRunways();
//    sim->Simulate();
//
//    return 0;
//};




////    airport->addRunway(runway);
////    airport->completeLandingSequence(airplane);
////    airport->completeLandingSequence(airplane1);
////    airport->completeTakeOffsequence(airplane);
////    airplane->setStatus(Approaching);
////    airplane->setHeight(10000);
////    airport->completeLandingSequence(airplane);
//}