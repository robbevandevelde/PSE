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
#include "../../Simulator.h"


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
        testRunway1 = new Runway(2000, "Bravo", Asphalt, "Zaventem");
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
    Runway* testRunway1;

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
TEST_F(OutputTest, takeoffOutput)
{

    EXPECT_TRUE(APU->DirectoryExists("testOutput"));
    ofstream myfile;
    ofstream myfile2;
    myfile.open("testOutput/testOutput03.txt");
    myfile2.open("testOutput/extra.txt");

    testAirport->addRunway(testRunway1);

    testAirplane->setStatus(Approaching);

    testAirplane->setHeight(0);

    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());

    testAirplane->setStatus(Departure);

    EXPECT_EQ(Departure,testAirplane->getStatus());

    testAirport->addAirplaneToRunway(testAirplane, myfile);

    testAirport->takeOffSequence(testAirplane, myfile);

    EXPECT_TRUE(testAirplane->getHeight() != 0);

    testAirport->takeOffSequence(testAirplane, myfile);
    testAirport->takeOffSequence(testAirplane, myfile);
    testAirport->takeOffSequence(testAirplane, myfile);
    testAirport->takeOffSequence(testAirplane, myfile);

    myfile.close();
    myfile2.close();
    EXPECT_TRUE(APU->FileExists("testOutput/testOutput03.txt"));
    EXPECT_TRUE(APU->FileExists("testOutput/compareTakeOff.txt"));
    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput03.txt", "testOutput/compareTakeOff.txt"));
}
////Tests the writetofile of a complete simulation
TEST_F(OutputTest, simulatieTest)
{
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    ASSERT_TRUE(APU->FileExists("testInput/Input03.xml"));
    testParser->loadFile("testInput/Input03.xml");
    testParser->parseItems("testInput/Input03.xml");
    EXPECT_TRUE(testParser->getSuccessEnum() == Success);
    vector<Runway*> runwaysVect = testParser->getRunways();
    vector<Airport*> airportsVect = testParser->getAirports();
    vector<Airplane*> airplanesVect = testParser->getAirplanes();
    testParser->writeToFile(runwaysVect, airportsVect, airplanesVect, "testOutput/simulatieTest.txt");
    EXPECT_TRUE(APU->compareFiles("testOutput/simulatieTest.txt", "testOutput/compareSimulatie.txt"));
}
////Tests the writetofile of a complete simulation
TEST_F(OutputTest, fullSimulation)
{
    ofstream myfile;
    myfile.open("testOutput/testOutput05.txt");
    ASSERT_TRUE(APU->DirectoryExists("testInput"));
    Airport *airport = new Airport(2, "Zaventem", "f444", "Echo");
    AirTrafficController *John = new AirTrafficController(airport, "John");
    airport->assignController(John);
    std::string naam = "LAX";

    //Runways
    Flightplan *fl = new Flightplan(naam, 5, 6, 7);
    Runway* runway = new Runway(3000, "Alpha", Asphalt, "Zaventem");
    Runway* runway1 = new Runway(500,"Bravo", Grass, "Zaventem");
    vector<Runway*> runways;
    runways.push_back(runway);
    runways.push_back(runway1);

    //Airplanes
    Airplane* airplane = new Airplane("Klein", "Propeller", "EF11",Approaching,50,50,Airline, Propeller, Small,fl);
    airplane->setHeight(10000);
    Airplane* airplane2 = new Airplane("Medium", "Jet","EFEF", Approaching, 50,50, Airline,Jet, Medium,fl);
    vector<Airplane*> airplanes;
    airplanes.push_back(airplane);
    airplanes.push_back(airplane2);

    Simulator* sim = new Simulator(runways,airplanes,airport);
    sim->addRunways();
    sim->Simulate(myfile);
    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput05.txt", "testOutput/compareFullSimulation.txt"));
    myfile.close();
}
TEST_F(OutputTest, emergencySimulation){
    ofstream myfile;
    myfile.open("testOutput/testOutput06.txt");
    Airport *airport = new Airport(10, "Zaventem", "f444", "Echo");

    AirTrafficController *John = new AirTrafficController(airport, "John");
    airport->assignController(John);

    std::string naam = "LAX";
    Flightplan *fl = new Flightplan(naam, 5, 6, 7);

    Airplane *airplane = new Airplane("Small", "Small Propeller", "Winchester", Approaching, 50, 50, Airline, Propeller, Small, fl);
    airplane->setHeight(5000);
    airplane->setFuel(0);
    Airplane *airplane1 = new Airplane("556", "F16", "Win100", Approaching, 50, 50, Airline, Jet, Medium, fl);
    airplane1->setHeight(6000);
    Airplane *airplane2 = new Airplane("6969", "HI99", "Wallonie", Approaching, 50,50 ,Airline, Jet, Medium, fl);
    airplane2->setHeight(6000);
    Airplane *airplane3 = new Airplane("420", "W2", "Winchester", Approaching, 50, 50, Airline, Propeller, Small, fl);
    airplane3->setHeight(5000);

    Runway *runway = new Runway(500, "Alpha", Grass, "Zaventem");

    Runway *runway1 = new Runway(2000, "Bravo", Asphalt, "Zaventem");

    Runway *runway2 = new Runway(9000, "Charlie", Asphalt, "Zaventem");

    vector<Runway *> runways;

    runways.push_back(runway);
    runways.push_back(runway1);
    runways.push_back(runway2);

    vector<Airplane *> airplanes;
    airplanes.push_back(airplane);
    airplanes.push_back(airplane1);
    airplanes.push_back(airplane2);
    airplanes.push_back(airplane3);

    Simulator *sim = new Simulator(runways, airplanes, airport);
    sim->addRunways();
    sim->Simulate(myfile);
    EXPECT_TRUE(APU->compareFiles("testOutput/testOutput06.txt", "testOutput/compareEmergency.txt"));
    myfile.close();

}