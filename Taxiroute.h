//
// Created by uauser on 4/23/18.
//

#ifndef PSE_TAXIROUTE_H
#define PSE_TAXIROUTE_H
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Taxiroute {
private:
    string taxipoint1;
    string crossing;
public:
    const string &getTaxipoint1() const;

    void setTaxipoint1(const string &taxipoint1);

    const string &getCrossing() const;

    void setCrossing(const string &crossing);

    Taxiroute(string& point, string& cross){taxipoint1 = point, crossing = cross;};

    Taxiroute(string& point) {taxipoint1 = point;};


};


#endif //PSE_TAXIROUTE_H
