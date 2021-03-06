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
        APU = new AirportUtils();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    LuchthavenParser* testParser;
    AirportUtils* APU;
};
//initcheck
TEST_F(LuchthavenParserTest, InitCheck)
{
    EXPECT_EQ(testParser->properlyInitialised(), true);
}
// Tests the input, happy day.
TEST_F(LuchthavenParserTest, InputHappyday1)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_FALSE(APU->DirectoryExists("testIut"));
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
    ASSERT_TRUE(APU->FileExists("testInput/Input01.xml"));
    testParser->loadFile("testInput/Input01.xml");
    testParser->parseItems("testInput/Input01.xml");
    EXPECT_TRUE(testParser->getSuccessEnum() == PartialImport);
}
//Second happy day, now with pre loaded file
TEST_F(LuchthavenParserTest, InputHappyday2)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_TRUE(APU->FileExists("testInput/Input03.xml"));
    testParser->loadFile("testInput/Input03.xml");
    testParser->parseItems("testInput/Input03.xml");
    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
}
//Failtest, not able to parse "<AL>"
TEST_F(LuchthavenParserTest, FalseTest)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    testParser->loadFile("testInput/Input02.xml");
    EXPECT_DEATH(testParser->parseItems("testInput/Input02.xml"), "The element is not recognised");
//    EXPECT_TRUE(testParser->getSuccessEnum() == ImportAborted);
}
//Tests if it cannot open false files
TEST_F(LuchthavenParserTest, Fileopen)
{
    ASSERT_FALSE(APU->DirectoryExists("rwrwe"));
    ASSERT_FALSE(APU->FileExists("dvd"));
    ASSERT_FALSE(APU->FileIsEmpty("testInput/Input02.xml"));
}
//Tests wrongly build xml file
TEST_F(LuchthavenParserTest, FalseTest2)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    testParser->loadFile("testInput/Input04.xml");
    EXPECT_DEATH(testParser->parseItems("testInput/Input04.xml"), "The simulation could not start");
    //EXPECT_DEATH(testParser->parseItems(testParser->getRoot()), "");
    //EXPECT_TRUE(testParser->getSuccessEnum() == ImportAborted);
}
//tests good file without any names
TEST_F(LuchthavenParserTest, FalseTest3)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    testParser->loadFile("testInput/Input05.xml");
    EXPECT_DEATH(testParser->parseItems("testInput/Input05.xml"), "An item in airport is none, cannot parse further");
//    EXPECT_TRUE(testParser->getSuccessEnum() == ImportAborted);
}
TEST_F(LuchthavenParserTest, FalseTest4)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_TRUE(APU->FileExists("testInput/Input06.xml"));
    EXPECT_DEATH(testParser->loadFile("testInput/Input06.xml"), "Error reading the end or begin tags");

}
TEST_F(LuchthavenParserTest, FalseTest5)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    EXPECT_DEATH(testParser->loadFile("testInput/Input07.xml"), "Error reading the end or begin tags");
}
TEST_F(LuchthavenParserTest, FalseTest6)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_TRUE(testParser->loadFile("testInput/Input08.xml"));
    EXPECT_DEATH(testParser->parseItems("testInput/Input08.xml"), "Please check if the tags in airport are either: iata, name, callsign or gates.");
}
 TEST_F(LuchthavenParserTest, FalseTest7)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    EXPECT_DEATH(testParser->loadFile("testInput/Input09.xml"), "Error reading the end or begin tags");
}
TEST_F(LuchthavenParserTest, FalseTest8)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    EXPECT_DEATH(testParser->loadFile("testInput/Input10.xml"), "Error reading the end or begin tags");
}
TEST_F(LuchthavenParserTest, FalseTest9)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_TRUE(testParser->loadFile("testInput/Input11.xml"));
    EXPECT_DEATH(testParser->parseItems("testInput/Input11.xml"), "Please check if the tags in airplane are either:"
            " model, number, callsign, status, passengers, fuel, type, engine or size.");
}

TEST_F(LuchthavenParserTest, FalseTest10)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_TRUE(testParser->loadFile("testInput/Input12.xml"));
    EXPECT_DEATH(testParser->parseItems("testInput/Input12.xml"), "Please check if the tags in airport are either:"
            " iata, name, callsign or gates.");

}
TEST_F(LuchthavenParserTest, FalseTest11)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    EXPECT_DEATH(testParser->loadFile("testInput/Input13.xml"), "Error reading the end or begin tags");

}
//Test the inputted values
TEST_F(LuchthavenParserTest, InputValueTest)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    SuccessEnum yes= PartialImport;
    testParser->setSuccessEnum(yes);
    ASSERT_TRUE(APU->FileExists("testInput/Input03.xml"));
    testParser->loadFile("testInput/Input03.xml");
    testParser->parseItems("testInput/Input03.xml");
    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
    EXPECT_EQ(Small, testParser->getAirplanes()[0]->getSize());
    EXPECT_EQ("Cessna 842", testParser->getAirplanes()[0]->getCallsign());
    EXPECT_EQ(Propeller, testParser->getAirplanes()[0]->getEngine());
    EXPECT_EQ(Approaching, testParser->getAirplanes()[0]->getStatus());
    EXPECT_EQ(EmergencyLanding, testParser->getAirplanes()[1]->getStatus());
}