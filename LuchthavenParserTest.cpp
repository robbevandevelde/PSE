//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "Parsers/LuchthavenParser.h"
#include "AirportUtils.h"

using namespace std;

class LuchthavenParserTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    LuchthavenParser testParser;
};

// Tests the default constructor.
TEST_F(LuchthavenParserTest, InputHappyday) {
//    ASSERT_TRUE(DirectoryExists("testInput"));

    ofstream myfile;
//    enum importResult;
//    myfile.open("testInput/Input01.xml");
//    myfile << "<?xml version=\"1.0\" ?>" << endl
//           << "<SIMULATIE>" << endl
//           << "\t<AIRPORT>" << endl
//           << "\t\t<name>Antwerp International Airport</name>" << endl
//           << "\t\t<iata>ANR</iata>" << endl
//           << "\t\t<callsign>Antwerp Tower</callsign>" << endl
//           << "\t\t<gates>10</gates>" << endl
//            << "\t</AIRPORT>" << endl
//            << "</SIMULATIE>" << endl;
//    myfile.close();
//    myfile.open("testInput/zzzError.txt");
}