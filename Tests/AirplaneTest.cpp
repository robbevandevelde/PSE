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
    EXPECT_EQ(testAirplane.get_status(), "");
    EXPECT_EQ(testAirplane.get_passengers(), 0);
}
TEST_F(AirplaneTest, NonDefaultConstructor) {
    EXPECT_EQ(testAirplane.get_status(), "status");
    testAirplane.set_status("newstatus");
    EXPECT_EQ(testAirplane.get_status(), "newstatus");
}
TEST_F(AirplaneTest, TakeoffLanding) {
    testAirplane.set_status("Standing at gate");
    testAirplane.();
    EXPECT_EQ(testAirplane.get_status(), "Approaching");
    EXPECT_EQ(testAirplane.get_status(), "Standing at gate");
}
TEST_F(AirplaneTest, gettersEnSetters) {
    testAirplane.set_status("status");
    testAirplane.set_model("model");
    testAirplane.set_number("32");
    testAirplane.set_callsign("callsign");
    testAirplane.set_passengers(110);
    EXPECT_EQ(testAirplane.get_status(), "status");
    EXPECT_EQ(testAirplane.get_number(), "32");
    EXPECT_EQ(testAirplane.get_callsign(), "callsign");
    EXPECT_EQ(testAirplane.get_model(), "model");
    EXPECT_EQ(testAirplane.get_passengers(), 110);
}