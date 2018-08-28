//
// Created by uauser on 3/22/18.
//

#include "AirportUtils.h"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <cstdio>
#include <string>

using namespace std;

/*
 * checks if the directory exists
 * @param directory name
 * @return bool
 */
bool AirportUtils::DirectoryExists(const std::string dirname) {
    REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling directoryExists()");
    struct stat st;
    return stat(dirname.c_str(), &st) == 0;
}
/*
 * checks if the file exists
 * @param filename
 * @return bool
 */
bool AirportUtils::FileExists(const std::string filename) {
    REQUIRE(this->properlyInitialised(), "Flightplan wasn't properly initialised when calling fileExists()");
    struct stat st;
    if (stat(filename.c_str(), &st) != 0) return false;
    ifstream f(filename.c_str());
    if (f.good()) {
        f.close();
        return true;
    } else {
        f.close();
        return false;
    }
}
/*
 * check if a given file is empty
 * @param filename
 * @return bool
 */
bool AirportUtils::FileIsEmpty(const std::string filename) {
    REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling FileIsempty()");
    struct stat st;
    if (stat(filename.c_str(), &st) != 0) return true; // File does not exist; thus it is empty
    return st.st_size == 0;
}
/*
 * compares 2 files
 * @param 2 files
 * @return bool
 */
bool AirportUtils::compareFiles(const std::string leftFileName, const std::string rightFileName)
    {
        REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling compareFiles()");
        ifstream leftFile;
        ifstream rightFile;
        bool equal = true;
        leftFile.open(leftFileName.c_str());
        if (!leftFile.is_open()) {
            return false;
        };
        rightFile.open(rightFileName.c_str());
        if (!rightFile.is_open()) {
            leftFile.close();
            return false;
        };

        //start comparing lines
        while ((!leftFile.eof()) && (!rightFile.eof())) {

            string line,line2;
            getline(leftFile,line);
            getline(rightFile,line2);
            if(line ==line2){
                equal = true;
            }
            else{
                equal = false;
                break;
            }
        }

        leftFile.close();
        rightFile.close();   //close them

        return equal;  //open your out file and enjoy
    }

/*
 * int to string
 * @param int
 * @return the string version of the int
 */
string AirportUtils::to_string( int x ) {
    REQUIRE(this->properlyInitialised(), "AirportUtils wasn't properly initialised when calling to_string()");
    int length = snprintf( NULL, 0, "%d", x );
    char* buf = new char[length + 1];
    snprintf( buf, length + 1, "%d", x );
    string str( buf );
    delete[] buf;
    return str;
}

bool AirportUtils::properlyInitialised()
{
    return _initCheck==this;
}
