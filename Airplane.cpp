
#include <iostream>
#include "Airplane.h"

//Take off sequence van de vliegtuig
void Airplane::TakeOff() {
    //Checkt of dat status standing at gate is
    if(status == "Standing at gate") {
        //Begin van opstijgen
        int x = 1000;
        while( x < 5001) {
        //console output hoeveel men al heeft gestegen
            cout << callsign << " ascended to " << x <<" ft." << endl;
            x+=1000;
        }
        //Set de status van dit airplane naar approaching(flying)
        this->setStatus("Approaching");
    } else {
        cout << callsign << " is not in the airport." << endl;
    }
}
//Landing sequence van de vliegtuig
void Airplane::Landing(){
    //Checkt of dat de status approaching is
    if(status == "Approaching") {
        //Begin van het dalen
        int x = 9000;
        while(x > 999) {
            //Console output hoeveel men heeft gedaald
            cout << callsign << " descended to " << x <<" ft."<<endl;
            x-=1000;
        }
        //Succesvol geland ==> status = standing at gate
        this->setStatus("Standing at gate");
    } else {
        cout << callsign << " is not approaching." << endl;
    }
}

//Return de number van de airplane
string Airplane::getNumber() const {
    return number;
}

/*Set de number van de airplane
 *@param int number
 *@return niks void functie
 */
void Airplane::setNumber(string number) {
    Airplane::number = number;
}

//Return de callsign van de airplane
const string &Airplane::getCallsign() const {
    return callsign;
}

/*Set de de callsign
 *@param string callsign
 *@return niks void functie
 */
void Airplane::setCallsign(const string &callsign) {
    Airplane::callsign = callsign;
}

//Return de model
const string &Airplane::getModel() const {
    return model;
}

/*Set de model van de airplane
 *@param string model
 *@return niks void functie
 */
void Airplane::setModel(const string &model) {
    Airplane::model = model;
}

//return de status
const string &Airplane::getStatus() const {
    return status;
}

/*Set de status
 *@param string status
 *@return niks void functie
 */
void Airplane::setStatus(const string &status) {
    Airplane::status = status;
}

//Return de passengers
int Airplane::getPassengers() const {
    return passengers;
}

/*Set de hoeveelheid passengers
 *@param int passengers
 *@return niks void functie
 */
void Airplane::setPassengers(int passengers) {
    Airplane::passengers = passengers;
}

/*Constructor
 *@param string number, string callsign, int passengers, string model, string status
 *@return niks void functie
 */
Airplane::Airplane(const string &number, const string &callsign, const string &model, const string &status,
                   int passengers) : number(number), callsign(callsign), model(model), status(status),
                                     passengers(passengers) {}

//Lege constructor
Airplane::Airplane() {
    number = "";
    callsign= "";
    model = "";
    status = "";
    passengers = 0;
}

int Airplane::getFuel() const {
    return fuel;
}

void Airplane::setFuel(int fuel) {
    Airplane::fuel = fuel;
}

const string &Airplane::getType() const {
    return type;
}

void Airplane::setType(const string &type) {
    Airplane::type = type;
}

const string &Airplane::getEngine() const {
    return engine;
}

void Airplane::setEngine(const string &engine) {
    Airplane::engine = engine;
}

const string &Airplane::getSize() const {
    return size;
}

void Airplane::setSize(const string &size) {
    Airplane::size = size;
}
