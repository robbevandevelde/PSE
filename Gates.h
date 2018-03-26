/*Dit is  de gate klasse, hierin worden vliegtuigen in opgeslagen
 *@author: Thimoty
 *@author: 06/03/2018
 *@version : 1.0
 */

#ifndef PROJECT_SOFTWARE_ENGINEERING_GATES_H
#define PROJECT_SOFTWARE_ENGINEERING_GATES_H

#include "Airplane.h"
#include "DesignByContract.h"
class Gates {
private:
    Gates* _initCheck;
    bool status; //True als vliegtuig, false als leeg
    Airplane airplane;
    int name;
public:
    bool properlyInitialiazed();
    Gates(int name);
    int getName();
    bool getStatus() const;

    void setStatus(bool status);

    Airplane getAirplane() const;

    void setAirplane(Airplane &airplane);

    void removeAirplane();
};


#endif //PROJECT_SOFTWARE_ENGINEERING_GATES_H
