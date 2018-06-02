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

    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Airport* testAirport;
};

// Tests the default constructor.
TEST_F(AirportTest, InitTest){
    EXPECT_TRUE(testAirport->properlyInitialised());
}
TEST_F(AirportTest, DefaultConstructorTest){
    EXPECT_EQ(testAirport->getName(),"Antwerp Airport");
}
TEST_F(AirportTest, gettersEnSetters){
    testAirport->setGatesize(3);
    testAirport->setCallsign("callsign");
    testAirport->setIata("IATA");
    testAirport->setName("name");
    EXPECT_EQ((unsigned int)3, testAirport->getGatesize());
    EXPECT_EQ("name", testAirport->getName());
    EXPECT_EQ("callsign", testAirport->getCallsign());
    EXPECT_EQ("IATA", testAirport->getIata());
}
TEST_F(AirportTest, LandingProtocol){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", Approaching, 110, 5000, 1, 1, 2, testFlightplan);
    EXPECT_EQ((unsigned int)10000, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    testAirport->landingprotocol(testAirplane, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
}

TEST_F(AirportTest, TakeoffProtocol){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", Departure, 110, 5000, 1, 1, 1, testFlightplan);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output02.txt");
    testAirport->takeOffprotocol(testAirplane, myfile);
    myfile.close();
    EXPECT_EQ((unsigned int)4, testAirplane->getStatus());
}
TEST_F(AirportTest, GateProtocol){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", StandingAtGate, 110, 5000, 1, 2, 2, testFlightplan);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output03.txt");
    testAirport->gateprotocol(testAirplane, 110, myfile);
    myfile.close();
    EXPECT_EQ(StandingAtGate, testAirplane->getStatus());
}
TEST_F(AirportTest, AirplaneToRun){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", Departure, 110, 5000, 1, 3, 1, testFlightplan);
    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    testAirport->addAirplaneToRunway(testAirplane);
    testAirport->removeAirplaneFromRunway(testAirplane);
}
TEST_F(AirportTest, Controller){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    EXPECT_EQ(John, testAirport->getController());
}
