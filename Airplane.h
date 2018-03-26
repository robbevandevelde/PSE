/*Dit zijn de airplanes, deze hebben een take off en een landing sequence die men kan oproepen
 *@author: Thimoty
 *@date: 06/03/2018
 */

#ifndef PARSER_AIRPLANE_H
#define PARSER_AIRPLANE_H

#include <string>
#include <algorithm>
using namespace std;

class Airplane {
private:
    Airplane* _initCheck;
    string number;
    string callsign;
    string model;
    string status;
    int passengers;

public:
    Airplane();

    Airplane(const string &number, const string &callsign, const string &model, const string &status, int passengers);

    void TakeOff();
    void Landing();

    int getPassengers() const;

    void setPassengers(int passengers);

    string getNumber() const;

    void setNumber(string number);

    const string &getCallsign() const;

    void setCallsign(const string &callsign);

    const string &getModel() const;

    void setModel(const string &model);

    const string &getStatus() const;

    void setStatus(const string &status);


};


#endif //PARSER_AIRPLANE_H
