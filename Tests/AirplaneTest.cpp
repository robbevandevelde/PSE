//
// Created by Robbe Van de Velde on 21/03/18.
//


#include <gtest/gtest.h>
#include "../Airplane.h"

class AirplaneTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        string name = "LAX";
        testFlightplan = new Flightplan(name, 15, 45, 1);
        testAirplane = new Airplane("32", "callsign", "model", 5, 110, 5000, 1, 2, 1, testFlightplan);

    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Airplane* testAirplane;
    Flightplan* testFlightplan;
};

TEST_F(AirplaneTest, InitTest) {
    EXPECT_TRUE(testAirplane->properlyInitialised());
    //EXPECT_TRUE(testFlightplan->properlyInitialised());

}
TEST_F(AirplaneTest, DefaultconstructorTests) {
    EXPECT_EQ((unsigned int)5, testAirplane->getStatus());
    EXPECT_EQ((unsigned int)110, testAirplane->getPassengers());
    testAirplane->setStatus(1);
    EXPECT_EQ(StandingAtGate, testAirplane->getStatus());
}

TEST_F(AirplaneTest, gettersEnSetters) {
    testAirplane->setStatus(0);
    testAirplane->setModel("model");
    testAirplane->setNumber("32");
    testAirplane->setCallsign("callsign");
    testAirplane->setPassengers(110);
    EXPECT_EQ((unsigned int)0, testAirplane->getStatus());
    EXPECT_EQ("32", testAirplane->getNumber());
    EXPECT_EQ("callsign", testAirplane->getCallsign());
    EXPECT_EQ("model", testAirplane->getModel());
    EXPECT_EQ((unsigned int)110, testAirplane->getPassengers());
}