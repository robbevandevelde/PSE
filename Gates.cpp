

#include "Gates.h"
//Checkt de initialisatie
bool Gates::properlyInitialiazed() {
    return _initCheck == this;
}

/*Constructor
 *@param int name van de gate
 *@return niks constructor
 */
Gates::Gates(int name) : name(name) {
    _initCheck = this;
    status = false;
    ENSURE(!status, "status must be false");
    ENSURE(properlyInitialiazed()," the constructor must end");
}

//Return de name
int Gates::getName() {
    return name;
}

//Return de status
bool Gates::getStatus() const {
    return status;
}

/*Set de status
 *@param bool status
 *@return niks void functie
 */
void Gates::setStatus(bool status) {
    Gates::status = status;
}

//Return de airplane
Airplane Gates::getAirplane() const {
    return airplane;
}

/*Set de airplane en zet bool op true dat het bezet is
 *@param airplane
 *@return niks
 */
void Gates::setAirplane(Airplane &airplane) {
    Gates::airplane = airplane;
    status = true;
}

//Maakt airplane default airplane en zet status op false
void Gates::removeAirplane() {
    airplane = Airplane();
    status = false;
}


