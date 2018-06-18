//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <gtest/gtest.h>
#include "../Airport.h"
#include <iostream>
#include <fstream>

class AirportTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testAirport = new Airport(10, "Antwerp Airport", "ANR", "callsign");
        AirTrafficController* John = new AirTrafficController(testAirport,"John");
        testAirport->assignController(John);
        string name = "LAX";
        testFlightplan = new Flightplan(name, 15, 45, 1);
        testAirplane = new Airplane("32", "callsign", "model", Departure, 110, 5000, 1, 1, 1, testFlightplan);


    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Airport* testAirport;
    AirTrafficController* John;
    Flightplan* testFlightplan;
    Airplane* testAirplane;
};

// Tests the initialisation.
TEST_F(AirportTest, InitTest)
{
    EXPECT_TRUE(testAirport->properlyInitialised());
}
//Tests the default constructor
TEST_F(AirportTest, DefaultConstructorTest)
{
    EXPECT_EQ(testAirport->getName(),"Antwerp Airport");
}
//Tests the getters and setters
TEST_F(AirportTest, gettersEnSetters)
{
    testAirport->setGatesize(3);
    testAirport->setCallsign("callsign");
    testAirport->setIata("IATA");
    testAirport->setName("name");
    EXPECT_EQ((unsigned int)3, testAirport->getGatesize());
    EXPECT_EQ("name", testAirport->getName());
    EXPECT_EQ("callsign", testAirport->getCallsign());
    EXPECT_EQ("IATA", testAirport->getIata());
}
//Tests the landing protocol
TEST_F(AirportTest, LandingProtocol)
{
    testAirplane->setStatus(Approaching);
    testAirplane->setHeight(10000);
    EXPECT_EQ((unsigned int)10000, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    testAirport->landingprotocol(testAirplane, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
}
//Tests the takeoff protocol
TEST_F(AirportTest, TakeoffProtocol)
{
    testAirplane->setStatus(Departure);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output02.txt");
    testAirport->takeOffprotocol(testAirplane, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)4, testAirplane->getStatus());
}
//Tests the gate protocol
TEST_F(AirportTest, GateProtocol)
{
    testAirplane->setStatus(StandingAtGate);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output03.txt");
    testAirport->gateprotocol(testAirplane, 110, myfile);
    myfile.close();
    EXPECT_EQ(StandingAtGate, testAirplane->getStatus());
}
//Tests the airplane to runway function
TEST_F(AirportTest, AirplaneToRun)
{
    testAirplane->setStatus(Departure);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    testAirport->addAirplaneToRunway(testAirplane);
    testAirport->removeAirplaneFromRunway(testAirplane);
}
//Tests the added controller
TEST_F(AirportTest, Controller)
{
    EXPECT_EQ("John", testAirport->getController()->getName());
}
//Tests the landing protocol with expected death
TEST_F(AirportTest, landingDeathtest)
{
    testAirplane->setStatus(JustLanded);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->landingprotocol(testAirplane, myfile), "Airplane must be approaching in order to land");
    myfile.close();
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
}
////Tests the gate protocol with expected death
TEST_F(AirportTest,  gateprotDeathtest)
{
    testAirplane->setStatus(Approaching);
    testAirplane->setHeight(500);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->gateprotocol(testAirplane, 20), "Airplane must be on the ground");
    myfile.close();
}
//Tests the takeoff protocol with expected death
TEST_F(AirportTest,  takeOffDeathtest)
{
    testAirplane->setStatus(Approaching);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->takeOffprotocol(testAirplane, myfile), "Airplane must be departure");
    myfile.close();
}
//Tests the takeoff protocol with expected death
TEST_F(AirportTest,  takeOffDeathtest2)
{
    testAirplane->setStatus(Departure);
    testAirplane->setHeight(50);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->takeOffprotocol(testAirplane, myfile), "Airplane must be on the ground");
    myfile.close();
}
//Tests the airplane to gate with expected death
TEST_F(AirportTest,  apl2gtDeathtest)
{
    testAirplane->setStatus(Departure);
    testAirplane->setHeight(0);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->addAirplaneToGate(testAirplane, myfile), "Airplane has to be just landed at the runway in order to taxi");
    myfile.close();
}

