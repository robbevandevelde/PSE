//
// Created by uauser on 6/15/18.
//

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "../../Parsers/LuchthavenParser.h"
#include "../../AirportUtils.h"
#include "../../Airport.h"



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
        testAirplane = new Airplane("32", "callsign", "model", Approaching, 50, 500, Airline, Jet,Medium, testFlightplan);
        APU = new AirportUtils();
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
    AirportUtils* APU;
};
//initcheck
TEST_F(OutputTest, InitCheck)
{
    EXPECT_TRUE(testParser->properlyInitialised());
}
//tests output of landingprotocol
TEST_F(OutputTest, LandingProtocolOutput)
{
    EXPECT_TRUE(APU->DirectoryExists("testOutput"));
    ofstream myfile;
    myfile.open("testOutput/testOutput01.txt");
    testAirport->landingSequence(testAirplane, myfile);
    myfile.close();
//    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    EXPECT_TRUE(APU->FileExists("testOutput/testOutput01.txt"));
    EXPECT_TRUE(APU->FileExists("testOutput/compareLandingStep.txt"));
    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput01.txt", "testOutput/compareLandingStep.txt"));
}
TEST_F(OutputTest, LandingProtocolFullOutput)
{
    EXPECT_TRUE(APU->DirectoryExists("testOutput"));
    ofstream myfile;
    myfile.open("testOutput/testOutput04.txt");
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);

    myfile.close();
//    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    EXPECT_TRUE(APU->FileExists("testOutput/testOutput04.txt"));
    EXPECT_TRUE(APU->FileExists("testOutput/compareLandingFull.txt"));
    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput04.txt", "testOutput/compareLandingFull.txt"));
}
////tests output of gateprotocol
TEST_F(OutputTest, gateProtocolOutput)
{
    EXPECT_TRUE(APU->DirectoryExists("testOutput"));
    ofstream myfile;
    myfile.open("testOutput/testOutput02.txt");
    testAirplane->setStatus(JustLanded);
    testAirplane->setHeight(0);
    testAirport->addAirplaneToGate(testAirplane, myfile);
    testAirport->gateprotocol(testAirplane, 100, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    EXPECT_TRUE(APU->FileExists("testOutput/testOutput02.txt"));
    EXPECT_TRUE(APU->FileExists("testOutput/compareGateprot.txt"));
    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput02.txt", "testOutput/compareGateprot.txt"));
}
////tests output of takeoffprotocol
//TEST_F(OutputTest, takeoffOutput)
//{
//    EXPECT_TRUE(APU->DirectoryExists("testOutput"));
//    ofstream myfile;
//    ofstream myfile2;
//    myfile.open("testOutput/testOutput03.txt");
//    myfile2.open("testOutput/extra.txt");
////    Runway* testRunway = new Runway(2000,"R11",Asphalt,"ANT");
//
//    testAirport->removeAirplaneFromGate(testAirplane, myfile2);
//    testAirport->addAirplaneToRunway(testAirplane, myfile);
//    testAirport->takeOffSequence(testAirplane, myfile);
//    myfile.close();
//    myfile2.close();
//    EXPECT_EQ((unsigned int)5000, testAirplane->getHeight());
//    EXPECT_TRUE(APU->FileExists("testOutput/testOutput03.txt"));
//    EXPECT_TRUE(APU->FileExists("testOutput/compareTakeOff.txt"));
//    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput03.txt", "testOutput/compareTakeOff.txt"));
//}
////Tests the writetofile of a complete simulation
//TEST_F(OutputTest, simulatieTest)
//{
//    ASSERT_TRUE(APU->DirectoryExists("testInput"));
//    SuccessEnum yes= PartialImport;
//    testParser->setSuccessEnum(yes);
//    ASSERT_TRUE(APU->FileExists("testInput/Input03.xml"));
//    testParser->loadFile("testInput/Input03.xml");
//    testParser->parseItems("testInput/Input03.xml");
//    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
//    vector<Runway*> runwaysVect = testParser->getRunways();
//    vector<Airport*> airportsVect = testParser->getAirports();
//    vector<Airplane*> airplanesVect = testParser->getAirplanes();
//    testParser->writeToFile(runwaysVect, airportsVect, airplanesVect, "testOutput/simulatieTest.txt");
//    EXPECT_TRUE(APU->compareFiles("testOutput/simulatieTest.txt", "testOutput/compareSimulatie.txt"));
//}
//
