//
// Created by Robbe Van de Velde on 21/03/18.
//


#include <gtest/gtest.h>
#include "../Airplane.h"
#include "../Flightplan.h"

class AirplaneTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testFlightplan = Flightplan("LAX", 15, 45, 1);
        testAirplane = Airplane("32", "callsign", "model", "status", 110, 5000, "militairy", "jet", "small", testFlightplan);

    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Airplane testAirplane;
    Flightplan* testFlightplan;
};

TEST_F(AirplaneTest, DefaultConstructor) {
    EXPECT_EQ(testAirplane.getStatus(), "");
    EXPECT_EQ(testAirplane.getPassengers(), 0);
}
TEST_F(AirplaneTest, NonDefaultConstructor) {
    EXPECT_EQ(testAirplane.getStatus(), "status");
    testAirplane.setStatus("newstatus");
    EXPECT_EQ(testAirplane.getStatus(), "newstatus");
}
TEST_F(AirplaneTest, TakeoffLanding) {
    testAirplane.setStatus("Standing at gate");
    testAirplane.();
    EXPECT_EQ(testAirplane.getStatus(), "Approaching");
    EXPECT_EQ(testAirplane.getStatus(), "Standing at gate");
}
TEST_F(AirplaneTest, gettersEnSetters) {
    testAirplane.setStatus("status");
    testAirplane.setModel("model");
    testAirplane.setNumber("32");
    testAirplane.setCallsign("callsign");
    testAirplane.setPassengers(110);
    EXPECT_EQ(testAirplane.getStatus(), "status");
    EXPECT_EQ(testAirplane.getNumber(), "32");
    EXPECT_EQ(testAirplane.getCallsign(), "callsign");
    EXPECT_EQ(testAirplane.getModel(), "model");
    EXPECT_EQ(testAirplane.getPassengers(), 110);
}