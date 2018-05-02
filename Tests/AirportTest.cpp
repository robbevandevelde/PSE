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
//TEST_F(AirportTest, LandingProtocols){
//    string name = "LAX";
//    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
//    Airplane* testAirplane = new Airplane("32", "callsign", "model", Approaching, 110, 5000, "militairy", "jet", "small", testFlightplan);
//    EXPECT_EQ(testAirplane->getHeight(), 10000);
//    testAirport->Landingprotocol(testAirplane);
//    EXPECT_EQ(testAirplane->getHeight(), 1000);
//}
//TEST_F(AirportTest, FinishedLanding){
//    string name = "LAX";
//    //Runway* testRunway = new Runway(3, name, name, name);
//
//    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
//    Airplane* testAirplane = new Airplane("32", "callsign", "model", Approaching, 110, 5000, "militairy", "jet", "small", testFlightplan);
//    EXPECT_EQ(testAirplane->getHeight(), 10000);
////    testAirport->completeLandingSequence(testAirplane);
////    EXPECT_EQ(testAirplane->getHeight(), 0);
//    testAirplane->setHeight(0);
//
//}
//TEST_F(AirportTest, GateProtocol){
//    string name = "LAX";
//    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
//    Airplane* testAirplane = new Airplane("32", "callsign", "model", JustLanded, 110, 5000, "militairy", "jet", "small", testFlightplan);
//    EXPECT_EQ(testAirplane->getHeight(), 0);
//    testAirport->gateprotocol(testAirplane, 110);
//    string name1= "R11";
//    string name2= "FLAT";
//    string name3= "ANR";
//    EXPECT_EQ(testAirplane->getPassengers(), 110);
//
//}
