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
TEST_F(AirportTest, DefaultConstructor){
    EXPECT_EQ(testAirport->getName(),"Antwerp Airport");
}
TEST_F(AirportTest, NonDefaultConstructor){
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
//TEST_F(AirportTest, Protocols){
//    Runway testRunway("11R", "ANR");
//    testAirport->addRunway(testRunway);
//    Airplane testAirplane("32", "testplane", "model", "Approaching", 110);
//    Airplane testAirplane2("32", "testplane", "model", "Standing at gate", 110);
//    testAirport->setAmountOfGates(3);
//    EXPECT_EQ(testAirport->isGateEmpty(),true);
//    testAirport->Landingprotocol(testAirplane);
//    EXPECT_EQ(testAirport->getRunways()[0].getName(), "11R");
//    testAirport->TakeOffprotocol(testAirplane2);
//    EXPECT_EQ(testAirplane->getStatus(),"Approaching");
//}
