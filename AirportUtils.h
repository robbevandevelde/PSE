//
// Created by uauser on 3/22/18.
//

#ifndef PSE_AIRPORTUTILS_H
#define PSE_AIRPORTUTILS_H

#include <iostream>
#include "DesignByContract.h"

class AirportUtils{
private:
    AirportUtils* _initCheck;
public:
    AirportUtils(){
        _initCheck = this;
        ENSURE(properlyInitialised(), "Airportutils wasn't properly initialised");
    }
    //    REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling directoryExists()");
    bool DirectoryExists(const std::string dirname);

    //    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling fileExists()");
    bool FileExists(const std::string dirname);

    //    REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling FileIsempty()");
    bool FileIsEmpty(const std::string filename);

    //    REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling compareFiles()");
    //    ENSURE(line== line2, "Lines are not equal");
    //    ENSURE(line!= line2, "Lines are equal");
    bool compareFiles(const std::string leftFileName, const std::string rightFileName);

    std::string to_string(int i);

    bool properlyInitialised();

};

#endif //PSE_AIRPORTUTILS_H
