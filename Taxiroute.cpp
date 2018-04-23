//
// Created by uauser on 4/23/18.
//

#include "Taxiroute.h"

const string &Taxiroute::getTaxipoint1() const {
    return taxipoint1;
}

void Taxiroute::setTaxipoint1(const string &taxipoint1) {
    Taxiroute::taxipoint1 = taxipoint1;
}

const string &Taxiroute::getTaxipoint2() const {
    return taxipoint2;
}

void Taxiroute::setTaxipoint2(const string &taxipoint2) {
    Taxiroute::taxipoint2 = taxipoint2;
}

const string &Taxiroute::getCrossing() const {
    return crossing;
}

void Taxiroute::setCrossing(const string &crossing) {
    Taxiroute::crossing = crossing;
}
