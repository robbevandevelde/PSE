//
// Created by uauser on 3/22/18.
//

#ifndef PSE_AIRPORTUTILS_H
#define PSE_AIRPORTUTILS_H

#include <iostream>


    bool DirectoryExists(const std::string dirname);

    bool FileExists(const std::string dirname);

    bool FileIsEmpty(const std::string filename);

    bool FileCompare(const std::string leftFileName, const std::string rightFileName);

    bool compareFiles(const std::string leftFileName, const std::string rightFileName);

    std::string to_string(int i);



#endif //PSE_AIRPORTUTILS_H
