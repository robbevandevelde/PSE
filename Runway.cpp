
#include "Runway.h"

//Lege constructor
Runway::Runway() {
    _initCheck = this;
    status = false;
    ENSURE(properlyInitialiazed(),"constructor must end");
}

/*@Constructor
 *@param string voor de naam en string voor de airport
 *@return niks constructor
 */
Runway::Runway(const string &Name, const string &Airport) : Name(Name), Airport(Airport) {
    _initCheck = this;
    status = false;
    ENSURE(properlyInitialiazed(),"constructor must end");
}

//Deconstructor
Runway::~Runway() {

}

//Delete een airplane van de runway (vervangt airplane met een lege airplane en zet status op false)
void Runway::removeAirplane()
{
    //REQUIRE(properlyInitialiazed(),"Runway isn't properly initiliazed when calling removeAirplane");
    airplane = Airplane();
    status = false;
}
//return de airplane
Airplane Runway::getAirplane() const {
    //REQUIRE(properlyInitialiazed(),"Runway isn't properly initiliazed when calling getAirplane");
    return airplane;
}

/*@Set de airplane
 *@param airplane
 *@return niks void functie
 */
void Runway::setAirplane(Airplane &airplane) {

    Runway::airplane = airplane;
    status = true;
}
//return de Name van de runway
const string &Runway::getName() const {
    return Name;
}

/*@Set de name van de runway
 *@param een string met de naam
 *@return niks void functie
 */
void Runway::setName(const string &newName) {
    Name= newName;
}

//return de airport
const string &Runway::getAirport() const {
    return Airport;
}
/*@Set de airport
 *@param een airport
 *return niks void functie
 */
void Runway::setAirport(const string &newAirport) {
    Airport=newAirport;
}

bool Runway::getStatus() const {
    return status;
}

/* @Set de status
 * @param status bool
 * @return niks void functie
 */
void Runway::setStatus(bool status) {
    Runway::status = status;
}

//Checkt voor de initialisatie
bool Runway::properlyInitialiazed() {
    return _initCheck == this;
}


