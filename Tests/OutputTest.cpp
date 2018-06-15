//
// Created by uauser on 6/15/18.
//

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "../Parsers/LuchthavenParser.h"
#include "../AirportUtils.h"
#include "../Airport.h"



using namespace std;

class OutputTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testParser = new LuchthavenParser();
        testAirport = new Airport(10, "Antwerp Airport", "ANR", "callsign");
        John = new AirTrafficController(testAirport,"John");
        testAirport->assignController(John);
        string name = "LAX";
        testFlightplan = new Flightplan(name, 15, 45, 1);
        testAirplane = new Airplane("32", "callsign", "model", Approaching, 110, 5000, 1, 1, 2, testFlightplan);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    LuchthavenParser* testParser;
    Airport* testAirport;
    AirTrafficController* John;
    Flightplan* testFlightplan;
    Airplane* testAirplane;
};
TEST_F(OutputTest, InitCheck) {
    EXPECT_TRUE(testParser->properlyInitialised());
}
TEST_F(OutputTest, LandingProtocolOutput){
    EXPECT_TRUE(DirectoryExists("testOutput"));
    ofstream myfile;
    myfile.open("testOutput/testOutput01.txt");
    testAirport->landingprotocol(testAirplane, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    EXPECT_TRUE(FileExists("testOutput/testOutput01.txt"));
    EXPECT_TRUE(FileExists("testOutput/compareLanding.txt"));
    EXPECT_TRUE(FileCompare("testOutput/testOutput01.txt", "testOutput/compareLanding.txt"));
}
TEST_F(OutputTest, gateProtocolOutput){
    EXPECT_TRUE(DirectoryExists("testOutput"));
    ofstream myfile;
    myfile.open("testOutput/testOutput02.txt");
    testAirplane->setStatus(JustLanded);
    testAirplane->setHeight(0);
    testAirport->addAirplaneToGate(testAirplane, myfile);
    testAirport->gateprotocol(testAirplane, 10, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    EXPECT_TRUE(FileExists("testOutput/testOutput02.txt"));
    EXPECT_TRUE(FileExists("testOutput/compareGateprot.txt"));
    EXPECT_TRUE(FileCompare("testOutput/testOutput02.txt", "testOutput/compareGateprot.txt"));
}
TEST_F(OutputTest, takeoffOutput){
    EXPECT_TRUE(DirectoryExists("testOutput"));
    ofstream myfile;
    ofstream myfile2;
    myfile.open("testOutput/testOutput03.txt");
    myfile2.open("testOutput/extra.txt");
    Runway* testRunway = new Runway(1,"R11",2,"ANT");
    testAirport->addRunway(testRunway);
    testAirplane->setStatus(Approaching);
    testAirplane->setHeight(10000);
    testAirport->landingprotocol(testAirplane, myfile2);
    testAirport->addAirplaneToRunway(testAirplane, myfile2);
    testAirport->removeAirplaneFromRunway(testAirplane);
    testAirport->addAirplaneToGate(testAirplane, myfile2);

    testAirport->gateprotocol(testAirplane, 0, myfile2);

    testAirport->removeAirplaneFromGate(testAirplane, myfile2);
    testAirport->addAirplaneToRunway(testAirplane, myfile);
    testAirport->takeOffprotocol(testAirplane, myfile);
    myfile.close();
    myfile2.close();
    EXPECT_EQ((unsigned int)5000, testAirplane->getHeight());
    EXPECT_TRUE(FileExists("testOutput/testOutput03.txt"));
    EXPECT_TRUE(FileExists("testOutput/compareTakeOff.txt"));
    EXPECT_TRUE(FileCompare("testOutput/testOutput03.txt", "testOutput/compareTakeOff.txt"));
}
