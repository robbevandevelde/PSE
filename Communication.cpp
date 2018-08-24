//
// Created by uauser on 8/14/18.
//

#include "Airport.h"
#include "Airplane.h"
#include "AirTrafficController.h"
#include "Gate.h"
#include "Runway.h"
#include "Communication.h"

Communication::Communication() {
    _initcheck = this;
    ENSURE(properlyInitialised(), "Communication constructor failure");
}
bool Communication::properlyInitialised() {
    return _initcheck == this;
}

std::string Communication::NATOtranslator(const std::string string) {
    REQUIRE(this->properlyInitialised(), "NATOTranslator initialise error");
    std::string string1 = "";
    for(unsigned int x = 0; x < string.size(); x++){
        if(string[x] == 'A' || string[x] == 'a'){
            string1 = string1 + "ALFA ";
        }
        if(string[x] == 'B' || string[x] == 'b'){
            string1 = string1 + "BRAVO ";
        }
        if(string[x] == 'C' || string[x] == 'c'){
            string1 = string1 + "CHARLIE ";
        }
        if(string[x] == 'D' || string[x] == 'd'){
            string1 = string1 + "DELTA ";
        }
        if(string[x] == 'E' || string[x] == 'e'){
            string1 = string1 + "ECHO ";
        }
        if(string[x] == 'F' || string[x] == 'f'){
            string1 = string1 + "FOXTROT ";
        }
        if(string[x] == 'G' || string[x] == 'g'){
            string1 = string1 + "GOLF ";
        }
        if(string[x] == 'H' || string[x] == 'h'){
            string1 = string1 + "HOTEL ";
        }
        if(string[x] == 'I' || string[x] == 'i'){
            string1 = string1 + "INDIA ";
        }
        if(string[x] == 'J' || string[x] == 'j'){
            string1 = string1 + "JULIETT ";
        }
        if(string[x] == 'K' || string[x] == 'k'){
            string1 = string1 + "KILO ";
        }
        if(string[x] == 'L' || string[x] == 'l'){
            string1 = string1 + "LIMA ";
        }
        if(string[x] == 'M' || string[x] == 'm'){
            string1 = string1 + "MIKE ";
        }
        if(string[x] == 'N' || string[x] == 'n'){
            string1 = string1 + "NOVEMBER ";
        }
        if(string[x] == 'O' || string[x] == 'o'){
            string1 = string1 + "OSCAR ";
        }
        if(string[x] == 'P' || string[x] == 'p'){
            string1 = string1 + "PAPA ";
        }
        if(string[x] == 'Q' || string[x] == 'q'){
            string1 = string1 + "QUEBEC ";
        }
        if(string[x] == 'R' || string[x] == 'r'){
            string1 = string1 + "ROMEO ";
        }
        if(string[x] == 'S' || string[x] == 's'){
            string1 = string1 + "SIERRA ";
        }
        if(string[x] == 'T' || string[x] == 't'){
            string1 = string1 + "TANGO ";
        }
        if(string[x] == 'U' || string[x] == 'u'){
            string1 = string1 + "UNIFORM ";
        }
        if(string[x] == 'V' || string[x] == 'v'){
            string1 = string1 + "VICTOR ";
        }
        if(string[x] == 'W' || string[x] == 'w'){
            string1 = string1 + "WHISKEY ";
        }
        if(string[x] == 'X' || string[x] == 'x'){
            string1 = string1 + "XRAY ";
        }
        if(string[x] == 'Y' || string[x] == 'y'){
            string1 = string1 + "YANKEE ";
        }
        if(string[x] == 'Z' || string[x] == 'z'){
            string1 = string1 + "ZULU ";
        }
        if(string[x] == '1'){
            string1 = string1 + "ONE ";
        }
        if(string[x] == '2'){
            string1 = string1 + "TWO ";
        }
        if(string[x] == '3'){
            string1 = string1 + "THREE ";
        }
        if(string[x] == '4'){
            string1 = string1 + "FOUR ";
        }
        if(string[x] == '5'){
            string1 = string1 + "FIVE ";
        }
        if(string[x] == '6'){
            string1 = string1 + "SIX ";
        }
        if(string[x] == '7'){
            string1 = string1 + "SEVEN ";
        }
        if(string[x] == '8'){
            string1 = string1 + "EIGHT ";
        }
        if(string[x] == '9'){
            string1 = string1 + "NINE ";
        }
        if(string[x] == '0'){
            string1 = string1 + "ZERO ";
        }
    }
    return string1;
}

void Communication::ATC_Airplane_10000ft_Comm(AirTrafficController *airTrafficController, Airplane *airplane,
                                              std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");

    unsigned int counter= 1;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ " << airTrafficController->getName() << ", " << NATOtranslator(airplane->getCallsign()) << ", arriving at "
        << airTrafficController->getAirport()->getName() << "." << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "$ " << NATOtranslator(airplane->getCallsign()) << ", radar contact, descend and maintain "
            "five thousand feet, squawk " <<  airplane->get_squawkcode() << "." <<std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ " << "Descend and maintain five thousand feet, squawking " << airplane->get_squawkcode()
        << " , " << NATOtranslator(airplane->getCallsign()) << "."<< std::endl;

}

void Communication::ATC_Airplane_WaitPattern_Comm(AirTrafficController *airTrafficController, Airplane *airplane,
                                                  std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "$ " << NATOtranslator(airplane->getCallsign()) << ", hold south on the eighty radial, "
            "except further clearance." << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Holding south on the eighty radial " << NATOtranslator(airplane->getCallsign()) << "."
                                                                                        << std::endl;

}

void Communication::ATC_Airplane_5000ft_Comm(AirTrafficController *airTrafficController, Airplane *airplane,
                                             std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "$ " << NATOtranslator(airplane->getCallsign()) << " descend and maintain three thousand feet."
                                                           <<std::endl;
    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Descend and maintain three thousand feet " << NATOtranslator(airplane->getCallsign())
        << "." << std::endl;
}

void Communication::ATC_Airplane_3000ft_Comm(AirTrafficController *airTrafficController, Airplane *airplane,
                                             Airport* airport, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;

    out << "$ " << NATOtranslator(airplane->getCallsign()) << " cleared ILS approach runway " << "runwayname"
                                                                        << "." << std::endl;
    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    for(unsigned int x=0; x < airTrafficController->getAirport()->getRunways().size();x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << "$ Cleared ILS approach runway " << airTrafficController->getAirport()->getRunways()[x]->getName()
                << " "<< NATOtranslator(airplane->getCallsign()) << "." << std::endl;
            break;
        }
    }
}

void Communication::ATC_Airplane_After_Landing_Comm(AirTrafficController *airTrafficController, Airplane *airplane,
                                                    std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    //TODO:: Runway naam erbij zetten
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;

    for(unsigned int x=0; x < airTrafficController->getAirport()->getRunways().size();x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << "$ " << airTrafficController->getName() << ", " << NATOtranslator(airplane->getCallsign())
                << " , runway " << airTrafficController->getAirport()->getRunways()[x]->getName() << "vacated." << std::endl;
            break;
        }
    }

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << " Proceed to an empty gate. " << std::endl;
}

void Communication::ATC_Airplane_At_Gate_Comm(AirTrafficController *airTrafficController, Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");

    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ " << airTrafficController->getName() << ", " << airplane->getCallsign() << ", requesting IFR clearancy." << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "$ " << airplane->getCallsign() << ", " << airTrafficController->getName() << ", cleared to destination, "
            "maintain five thousand, expect flight level one zero zero - ten minutes after departure, squawk."
                                                                              << std::endl;

    counter ++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Cleared to destination, initial altitude five thousand, expecting one zero zero in ten, squawk, "
        << airplane->getCallsign() << "." << std::endl;
}

void
Communication::ATC_Airplane_At_Gate_After_IFR_Comm(AirTrafficController *airTrafficController, Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");

    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    for(unsigned int x = 0; x < airTrafficController->getAirport()->getGatesize(); x++){
        out << "$ " << airTrafficController->getName() << ", " << airplane->getCallsign() << " at gate " <<
        airTrafficController->getAirport()->getGates()[x]->getName() << ", requesting pushback." << std::endl;
        break;
    }

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;

    out << "$ " << airplane->getCallsign() << ", " << airTrafficController->getName() << ", pushback approved" << std::endl;

    counter ++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Pushback approved, " << airplane->getCallsign() << "." << std::endl;
}

void Communication::ATC_Airplane_Of_Gate_Comm(AirTrafficController *airTrafficController, Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ " << airplane->getCallsign() << " is ready to taxi."<< std::endl;
    counter ++;
    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "Proceed." << std::endl;

}

void Communication::ATC_Airplane_Wait_At_Runway_Comm(AirTrafficController *airTrafficController, Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ " << airTrafficController->getName() << ", " << airplane->getCallsign() << ", holding short." << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "$ " << airplane->getCallsign() << ", hold position." << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Holding position, " << airplane->getCallsign() << "." << std::endl;
}

void Communication::ATC_Airplane_Enter_Permission_Granted_Runway_Comm(AirTrafficController *airTrafficController,
                                                                      Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ " << airplane->getCallsign() << ", " << airTrafficController->getName() << ", holding short at runway."
        << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    for(unsigned int x=0; x < airTrafficController->getAirport()->getRunways().size();x++) {
        if(airTrafficController->getAirport()->validRunwayForPlane(airplane,airTrafficController->getAirport()->getRunways()[x])){
            out << "$ " << airplane->getCallsign() << ", line-up runway " << airTrafficController->getAirport()->getRunways()[x]->getName()
                                                                         << " and wait." << std::endl;

        }
        break;
    }
    counter ++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    for(unsigned int x=0; x < airTrafficController->getAirport()->getRunways().size(); x++) {
        if(airTrafficController->getAirport()->validRunwayForPlane(airplane,airTrafficController->getAirport()->getRunways()[x])){
            out << "$ Lining up runway " << airTrafficController->getAirport()->getRunways()[x]->getName() << " and wait, "
                << airplane->getCallsign() << "." << std::endl;
        }
        break;
    }
}

void
Communication::ATC_Airplane_Enter_TakeOff_Permission_Granted_Runway_Comm(AirTrafficController *airTrafficController,
                                                                         Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    for(unsigned int x = 0; x < airTrafficController->getAirport()->getRunways().size(); x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << "$ " << airTrafficController->getName() << ", "  << airplane->getCallsign()
                << ", holding short at " << airTrafficController->getAirport()->getRunways()[x]->getName() << "."
                <<std::endl;

        }
    break;
    }

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    for(unsigned int x = 0; x < airTrafficController->getAirport()->getRunways().size(); x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << "$ " << airplane->getCallsign() << ", runway " << airTrafficController->getAirport()->getRunways()[x]->getName()
                                                                  <<  " cleared to take-off" << std::endl;
        }
        break;
    }

    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    for(unsigned int x = 0; x < airTrafficController->getAirport()->getRunways().size(); x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << "$ Runway" << airTrafficController->getAirport()->getRunways()[x]->getName()
                << " cleared for take-off, " << airplane->getCallsign() << "." << std::endl;
        }
        break;
    }
}

void Communication::ATC_Airplane_TakeOff_Permission_Granted_Runway_Comm(AirTrafficController *airTrafficController,
                                                                        Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    for(unsigned int x = 0; x < airTrafficController->getAirport()->getRunways().size(); x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << airplane->getCallsign() << ", runway " << airTrafficController->getAirport()->getRunways()[x]->getName()
                                                          << " cleared for take-off." << std::endl;
        }
        break;
    }

    counter++;

    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    for(unsigned int x = 0; x < airTrafficController->getAirport()->getRunways().size(); x++){
        if(airTrafficController->getAirport()->getRunways()[x]->getAirplane() == airplane){
            out << "$ Runway" << airTrafficController->getAirport()->getRunways()[x]->getName()
                << " cleared for take-off, " << airplane->getCallsign() << "." << std::endl;
        }
        break;
    }
}

void
Communication::ATC_Airplane_More_Than_3000ft_Emergency(AirTrafficController *airTrafficController, Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Mayday mayday mayday, " << airTrafficController->getName() << ", " << airplane->getCallsign()
        << " out of fuel, performing emergency landing, " << airplane->getPassengers() << " passengers on board."
                                                                                       << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    //TODO: runway name erbij zetten
    out << "$ " << airplane->getCallsign() << ", roger mayday, squawk seven seven zero zero, cleared"
            "ILS landing runway." << std::endl;
}

void
Communication::ATC_Airplane_Less_Than_3000ft_Emergency(AirTrafficController *airTrafficController, Airplane *airplane, std::ostream &out) {
    REQUIRE(this->properlyInitialised(), "Initialise error");
    unsigned int counter = 1;
    out << "[" << counter << "] " << "[" << airplane->getCallsign() << "]" << std::endl;
    out << "$ Mayday mayday mayday, " << airTrafficController->getName() << ", " << airplane->getCallsign()
        << " out of fuel, performing emergency landing, " << airplane->getPassengers() << " passengers on board."
        << std::endl;

    counter++;

    out << "[" << counter << "] " << "[" << airTrafficController->getName() << "]" << std::endl;
    out << "$ " << airplane->getCallsign() << ", roger mayday, squawk seven seven zero zero, emergency"
            "personal on standby, good luck!" << std::endl;
}

