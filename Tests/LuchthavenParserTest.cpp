//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "../Parsers/LuchthavenParser.h"
#include "../AirportUtils.h"

using namespace std;

class LuchthavenParserTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
//        testParser = new LuchthavenParser();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    LuchthavenParser testParser;
};
TEST_F(LuchthavenParserTest, InitCheck) {
    EXPECT_EQ(testParser.properlyInitialised(), true);
}
// Tests the default constructor.
TEST_F(LuchthavenParserTest, InputHappyday1) {
//    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser.setSuccessEnum(yes);
    ofstream myfile;
    myfile.open("../testInput/Input01.xml");
    myfile << "<?xml version=\"1.0\" ?>" << endl
           << "<SIMULATIE>" << endl
           << "\t<AIRPORT>" << endl
           << "\t\t<name>Antwerp International Airport</name>" << endl
           << "\t\t<iata>ANR</iata>" << endl
           << "\t\t<callsign>Antwerp Tower</callsign>" << endl
           << "\t\t<gates>10</gates>" << endl
            << "\t</AIRPORT>" << endl
            << "</SIMULATIE>" << endl;
    myfile.close();
    myfile.open("../testInput/zzzError.txt");
    testParser.loadFile("../testInput/Input01.xml");
    testParser.parseItems(testParser.getRoot());
    EXPECT_TRUE(testParser.getSuccessEnum() == Success);

}
TEST_F(LuchthavenParserTest, InputHappyday2) {
//    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser.setSuccessEnum(yes);
    testParser.loadFile("../testInput/Input03.xml");
    testParser.parseItems(testParser.getRoot());
    EXPECT_TRUE(testParser.getSuccessEnum() == Success);
}
TEST_F(LuchthavenParserTest, FalseTest) {
//    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser.setSuccessEnum(yes);
    testParser.loadFile("../testInput/Input02.xml");
    testParser.parseItems(testParser.getRoot());
    EXPECT_TRUE(testParser.getSuccessEnum() == 0);
}
//    if(parser.loadFile("luchthaven.xml")){
//parser.parseItems(parser.getRoot());