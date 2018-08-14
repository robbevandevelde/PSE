//
// Created by uauser on 8/14/18.
//

#ifndef PSE_COMMUNICATION_H
#define PSE_COMMUNICATION_H

class Airport;
class Airplane;
class AirTrafficController;

#include <string>
#include <vector>
#include "DesignByContract.h"
//TODO: ZEGGEN TEGEN ROBBE DA DIE OOK SQUAWK CODE MOET KUNNEN PARSEN

//TODO: PROPERLY INITIALISED MAKEN

class Communication {
private:
    Communication* _initcheck;

public:
    //TODO: Functies maken voor communicatie
    Communication();
    bool properlyInitialised();
    std::string NATOtranslator(const std::string string);
    //For Landing sequence
    void ATC_Airplane_10000ft_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    void ATC_Airplane_WaitPattern_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    void ATC_Airplane_5000ft_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    void ATC_Airplane_3000ft_Comm(AirTrafficController* airTrafficController, Airplane* airplane, Airport* airport, std::ostream& out);
    void ATC_Airplane_After_Landing_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);

    //TODO:Finish communication functions
    //For Take off sequence
    void ATC_Airplane_At_Gate_Comm(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_At_Gate_After_IFR_Comm(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_Of_Gate_Comm(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_Wait_At_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_Enter_Permission_Granted_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_Enter_TakeOff_Permission_Granted_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_TakeOff_Permission_Granted_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane);

    //For Emergency
    void ATC_Airplane_More_Than_3000ft_Emergency(AirTrafficController* airTrafficController, Airplane* airplane);
    void ATC_Airplane_Less_Than_3000ft_Emergency(AirTrafficController* airTrafficController, Airplane* airplane);
};


#endif //PSE_COMMUNICATION_H
