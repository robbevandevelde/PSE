
#include <iostream>
#include "Airport.h"

/*For loop die number aantal keren gates aan de gate vector toevoegd
 *@param int number
 *@return niks void functie
 */
void Airport::setAmountOfGates(int amount){
    for(int i = 0; i < amount; i++){
        Gates gate(i + 1);
        gates.push_back(gate);
    }
}

//Itereert over de vector van gates en checkt of dat er een op false staat ==> niet empty
bool Airport::isGateEmpty() {
    for(unsigned int x = 0; x < gates.size();x++) {
        if(!gates[x].getStatus()) {
            return true;
        }
    }
    return false;
}

//Itereert over de vector van runways en checkt of dat er een op false staat ==> niet empty
bool Airport::isRunwayEmpty() {
    for(unsigned int x = 0; x < runways.size();x++) {
        if(!runways[x].getStatus()) {
            return true;
        }
    }
    return false;
}

/*Standing at gate protocol wordt hierdoor opgeroepen, vlieguit wordt gecheckt en passagiers kunnen op- of afstappen
 *@param airplane airplane
 *return niks void functie
 */
void Airport::StandingAtGateprotocol(Airplane & airplane) {
    //Itereert over de gates
    for(unsigned int x = 0; x < gates.size();x++)
    {
        //Checkt of dat de status vande airplane standing at gate is (moet zwz), en checkt of dat de name van de airplane overeenkomt met de gevraagde airplane
        if(airplane.getStatus() == "Standing at gate" && gates[x].getAirplane().getCallsign() == airplane.getCallsign())
        {
            //Output hoeveel passengers eruit zijn
            cout << airplane.getPassengers() << " passengers exited " << airplane.getCallsign() << " at Gate" << gates[x].getName() << " of " << Name << endl;
            //Set de amount of passengers naar 0 (aangezien er mensen uit de airplane ginge)
            gates[x].getAirplane().setPassengers(0);
            //Output om te zeggen dat de airplane werd gecheckt voor technical malfunctions
            cout << gates[x].getAirplane().getCallsign() << " has been checked for technical malfunctions" << endl;
            break;
        }
        //Niet voltooid: #passengers
        if(airplane.getStatus()== "Departure" && gates[x].getAirplane().getCallsign() == airplane.getCallsign())
        {
            cout << airplane.getCallsign() << " has been refueled" << endl;
            cout << "#passengers" << " boarded " << airplane.getCallsign() << " at gate" << gates[x].getName() << " of " << Name << endl;
            break;

        }
    }

}

/*Hier wordt de landing protocol uitgevoerd. Landing sequence wordt uitgevoerd van de plane als het kan landen
 *@param airplane airplane
 *return bool als succesvol
 */
bool Airport::Landingprotocol(Airplane &airplane) {
    //Checkt of dat de status van de airplane approaching is
    if(airplane.getStatus() == "Approaching") {
        //Zegt op hoeveel meter de airplane boven de grond is
        cout << airplane.getCallsign() << " is approaching " << Name << " at 10 000 ft." << endl;
        //Temp variable om positie in de vector te onthouden
        int temp=0;
        //Checkt of dat er een runway empty is, als dat niet zo is kan de airplane niet landen
        if(this->isRunwayEmpty()) {
            for(unsigned int x = 0; x < runways.size(); x++) {
                //Landing sequence van de airplane uitvoeren
                airplane.Landing();
                temp = x;
                //Positie van de vector
                if(!runways[x].getStatus()) {
                    //Zegt dat de airplane gaat landen
                    cout << airplane.getCallsign() << " is landing at " << Name << " on runway " << runways[x].getName() << endl;
                    //Plaats airplane in de runway
                    runways[x].setAirplane(airplane);
                    //Zegt dat de airplane is geland
                    cout << airplane.getCallsign() << " has landed at " << Name << " on runway " << runways[x].getName() << endl;
                    break;
                }
            }
        } else {
            cout << "Error" << endl;
            return false;
        }
        //Checkt of dat er een gate empty is zo niet kan de plane niet naar een gate taxien
        if(this->isGateEmpty()) {
            for(unsigned int x = 0; x < gates.size(); x++) {
                if(!gates[x].getStatus()) {
                    //Zegt dat de plane aant taxien is
                    cout << airplane.getCallsign() << " is taxiing to Gate " << gates[x].getName() << endl;
                    //Remove de airplane van de runway
                    runways[temp].removeAirplane();
                    //Set de airplane in de gate dat leeg is
                    gates[x].setAirplane(airplane);
                    //Zegt dat de airplane in gate x staat
                    cout << airplane.getCallsign() << " is standing at Gate " << gates[x].getName() << endl;
                    break;
                }
            }

        } else {
            cout << "Error" << endl;
            return false;
        }
        return true;
    } else {
        return false;
    }
}

/*Take off protocol voor de airplane, voert take off sequence van de plane uit als het kan opstijgen
 *@param airplane airplane
 *@return niks void functie
 */
void Airport::TakeOffprotocol(Airplane &airplane) {
    //Checkt of dat de airplane Standing at gate is
    if(airplane.getStatus()== "Standing at gate") {
        //Temp int om de index in een vector bij te houden
        int temp=0;
        if (this->isGateEmpty()) {

            for (unsigned int x = 0; x < gates.size(); x++) {
                //Zoekt naar de plane in de gates
                if (gates[x].getAirplane().getCallsign() == airplane.getCallsign()) {
                    //Airplane staat op gate x
                    cout << gates[x].getAirplane().getCallsign() << " is standing at Gate " << gates[x].getName() << endl;
                    //Index temp wordt x
                    temp = x;
                    break;
                }
            }
        }


        if (this->isGateEmpty()) {
            //tweede index temp
            int temp2=0;
            //Checkt naar een vrije runway
            for (unsigned int x = 0; x < runways.size(); x++) {
                if (!runways[x].getStatus()) {
                    //Zegt dat de airplane aan het taxien is naar de runway
                    cout << gates[temp].getAirplane().getCallsign() << " is taxiing to runway " << runways[x].getName() << endl;
                    //Remove de airplane van de gate
                    gates[temp].removeAirplane();
                    //Set de airplane op de runway
                    runways[x].setAirplane(airplane);
                    //Index wordt index van de runway
                    temp2 = x;
                    break;
                }
            }
            //Take off sequence van de airplane
            airplane.TakeOff();
            //Zegt dat de airplane airport heeft verlaten
            cout << runways[temp2].getAirplane().getCallsign() << " has left " << Name << endl;
            //Verwijder de airplane van de runway
            runways[temp2].removeAirplane();
        }
    }
}

//Return de name
const string &Airport::getName() const {
    return Name;
}

/*Set de name
 *@param string name
 *@return niks void functie
 */
void Airport::setName(const string &Name) {
    Airport::Name = Name;
}

//Return de iata
const string &Airport::getIata() const {
    return iata;
}

/*Set de iata
 *@param string iata
 *@return niks void functie
 */
void Airport::setIata(const string &iata) {
    Airport::iata = iata;
}

//Return de callsign
const string &Airport::getCallsign() const {
    return callsign;
}

/*Set de callsign
 *@param string callsign
 *@return niks void functie
 */
void Airport::setCallsign(const string &callsign) {
    Airport::callsign = callsign;
}

//return de gate
int Airport::getGates() const {
    return gate;
}

/*Set de hoeveelheid gates
 *@param int gate
 *@return niks void functie
 */
void Airport::setGates(int gates) {
    Airport::gate = gates;
}

/*Constructor
 *@param string airportname
 *@return niks constructor
 */
Airport::Airport(string airportname)
{
    runws = 0;
    Name = airportname;
}

/*Voegt een runway aan de runway vector toe
 *@param runway
 *@return niks void functie
 */
void Airport::addRunway(Runway & runway){
    runways.push_back(runway);
    runws +=1;
}

//Lege airport deconstructor
Airport::~Airport() {

}

//Lege constructor
Airport::Airport() {}

//return runws
int Airport::getRunws() const {
    return runws;
}

/*Set de runws nummer
 *@param int runws
 *@return niks void functie
 */
void Airport::setRunws(int runws) {
    Airport::runws = runws;
}

//Return runway
const vector<Runway> &Airport::getRunways() const {
    return runways;
}

