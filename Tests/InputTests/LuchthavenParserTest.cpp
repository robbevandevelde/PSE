//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "../../Parsers/LuchthavenParser.h"
#include "../../AirportUtils.h"



using namespace std;

class LuchthavenParserTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testParser = new LuchthavenParser();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    LuchthavenParser* testParser;
};
//initcheck
TEST_F(LuchthavenParserTest, InitCheck)
{
    EXPECT_EQ(testParser->properlyInitialised(), true);
}
// Tests the input, happy day.
TEST_F(LuchthavenParserTest, InputHappyday1)
{
    ASSERT_TRUE(DirectoryExists("testInput"));
    ASSERT_FALSE(DirectoryExists("testIut"));
    testParser->setSuccessEnum(PartialImport);
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
    ASSERT_TRUE(FileExists("testInput/Input01.xml"));
    testParser->loadFile("testInput/Input01.xml");
    testParser->parseItems(testParser->getRoot());
    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
}
//Second happy day, now with pre loaded file
TEST_F(LuchthavenParserTest, InputHappyday2)
{
    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    ASSERT_TRUE(FileExists("testInput/Input03.xml"));
    testParser->loadFile("testInput/Input03.xml");
    testParser->parseItems(testParser->getRoot());
    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
}
//Failtest, not able to parse "<AL>"
TEST_F(LuchthavenParserTest, FalseTest)
{
    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    testParser->loadFile("testInput/Input02.xml");
    testParser->parseItems(testParser->getRoot());
    EXPECT_TRUE(testParser->getSuccessEnum() == ImportAborted);
}
//Tests if it cannot open false files
TEST_F(LuchthavenParserTest, Fileopen)
{
    ASSERT_FALSE(DirectoryExists("rwrwe"));
    ASSERT_FALSE(FileExists("dvd"));
    ASSERT_FALSE(FileIsEmpty("testInput/Input02.xml"));
}
//Tests wrongly build xml file
TEST_F(LuchthavenParserTest, FalseTest2)
{
    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    testParser->loadFile("testInput/Input04.xml");
    testParser->parseItems(testParser->getRoot());
    EXPECT_TRUE(testParser->getSuccessEnum() == ImportAborted);
}
//tests good file without any names
TEST_F(LuchthavenParserTest, FalseTest3)
{
    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    testParser->loadFile("testInput/Input05.xml");
    testParser->parseItems(testParser->getRoot());
    EXPECT_TRUE(testParser->getSuccessEnum() == ImportAborted);
}
//Test the iputted values
TEST_F(LuchthavenParserTest, InputValueTest)
{
    ASSERT_TRUE(DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    ASSERT_TRUE(FileExists("testInput/Input03.xml"));
    testParser->loadFile("testInput/Input03.xml");
    testParser->parseItems(testParser->getRoot());
    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
    EXPECT_EQ(Small, testParser->getAirplanes()[0]->getSize());
    EXPECT_EQ("Cessna 842", testParser->getAirplanes()[0]->getCallsign());
    EXPECT_EQ(Propeller, testParser->getAirplanes()[0]->getEngine());
    EXPECT_EQ(Approaching, testParser->getAirplanes()[0]->getStatus());
    EXPECT_EQ(EmergencyLanding, testParser->getAirplanes()[1]->getStatus());
}