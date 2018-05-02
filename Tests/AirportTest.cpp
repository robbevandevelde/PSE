//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <gtest/gtest.h>
#include "../Airport.h"

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
    EXPECT_EQ(testAirport->getGatesize(),3);
    EXPECT_EQ(testAirport->getName(),"name");
    EXPECT_EQ(testAirport->getCallsign(),"callsign");
    EXPECT_EQ(testAirport->getIata(),"IATA");
}
TEST_F(AirportTest, LandingProtocol){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", Approaching, 110, 5000, "militairy", "jet", "small", testFlightplan);
    EXPECT_EQ(testAirplane->getHeight(), 10000);
    testAirport->Landingprotocol(testAirplane);
    EXPECT_EQ(testAirplane->getHeight(), 0);
}

TEST_F(AirportTest, TakeoffProtocol){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", Departure, 110, 5000, "militairy", "jet", "small", testFlightplan);
    EXPECT_EQ(testAirplane->getHeight(), 0);
    testAirport->TakeOffprotocol(testAirplane);
    EXPECT_EQ(testAirplane->getStatus(), 4);
}
TEST_F(AirportTest, GateProtocol){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", StandingAtGate, 110, 5000, "militairy", "jet", "small", testFlightplan);
    EXPECT_EQ(testAirplane->getHeight(), 0);
    testAirport->gateprotocol(testAirplane, 110);
    EXPECT_EQ(testAirplane->getStatus(), StandingAtGate);
}
TEST_F(AirportTest, AirplaneToRun){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", Departure, 110, 5000, "militairy", "jet", "small", testFlightplan);
    EXPECT_EQ(testAirplane->getHeight(), 0);
    testAirport->addAirplaneToRunway(testAirplane);
    testAirport->removeAirplaneOfRunway(testAirplane);
}TEST_F(AirportTest, Controller){
    AirTrafficController* John = new AirTrafficController(testAirport,"John");
    testAirport->assignController(John);
    EXPECT_EQ(testAirport->getController(), John);
}
