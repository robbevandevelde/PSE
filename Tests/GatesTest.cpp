//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <gtest/gtest.h>
#include "../Gate.h"

class GatesTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testGate = new Gate(1);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Gate* testGate;
};

// Tests the default constructor.
TEST_F(GatesTest, InitTest) {
    EXPECT_TRUE(testGate->properlyInitialised());
}
TEST_F(GatesTest, DefaultConstructor) {
    EXPECT_EQ(testGate->getName(), 1);
    EXPECT_EQ(testGate->isOccupied(), false);
    EXPECT_EQ(testGate->getAirplane(), nullptr);
}

TEST_F(GatesTest, airplaneTest) {
    EXPECT_EQ(testGate->getName(), 1);
    EXPECT_EQ(testGate->isOccupied(), false);
    EXPECT_EQ(testGate->getAirplane(), nullptr);
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, "militairy", "jet", "small", testFlightplan);
    testGate->addAirplane(testAirplane);
    EXPECT_TRUE(testGate->isOccupied());
    testGate->removeAirplane();
    EXPECT_FALSE(testGate->isOccupied());
    Airplane* testAirplane2 = new Airplane("127", "Boeiing", "747", 0, 400, 15000, "Commercial", "airplane", "large", testFlightplan);
    testGate->addAirplane(testAirplane2);
    EXPECT_TRUE(testGate->isOccupied());
    EXPECT_EQ(testAirplane2->getStatus(), StandingAtGate);
    EXPECT_EQ(testGate->getAirplane()->properlyInitialised(), true);
    EXPECT_EQ(testGate->getAirplane()->getNumber(), "127");
}
