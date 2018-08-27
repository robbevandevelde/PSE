/*Dit is de communicatie klasse waar bijna alle couts zitten
 *@author: Thimoty
 *@date: 14/08/2018
 *@version: 2.0
 */

#ifndef PSE_COMMUNICATION_H
#define PSE_COMMUNICATION_H

class Airport;
class Airplane;
class Runway;
class Gate;
class AirTrafficController;

#include <string>
#include <vector>
#include "DesignByContract.h"

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
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_10000ft_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_WaitPattern_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_5000ft_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_3000ft_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_After_Landing_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream& out);

    //For Take off sequence
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_At_Gate_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_At_Gate_After_IFR_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_Of_Gate_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_Wait_At_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_Enter_Permission_Granted_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_Enter_TakeOff_Permission_Granted_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_TakeOff_Permission_Granted_Runway_Comm(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);

    //For Emergency
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_More_Than_3000ft_Emergency(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
    //    REQUIRE(this->properlyInitialised(), "Initialise error");
    //    REQUIRE(airTrafficController != NULL && airplane != NULL, "ATC and airplane can't be NULL");
    void ATC_Airplane_Less_Than_3000ft_Emergency(AirTrafficController* airTrafficController, Airplane* airplane, std::ostream &out);
};


#endif //PSE_COMMUNICATION_H
