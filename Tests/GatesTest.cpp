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
        testGate = new Gate((unsigned int)1);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Gate* testGate;
};

// Tests the init.
TEST_F(GatesTest, InitTest)
{
    EXPECT_TRUE(testGate->properlyInitialised());
}
//Tests the default constructor
TEST_F(GatesTest, DefaultConstructor)
{
    EXPECT_EQ((unsigned int)1, testGate->getName());
    EXPECT_FALSE(testGate->isOccupied());
    EXPECT_EQ((Airplane*)NULL, testGate->getAirplane());
}
//Tests the death for addAirplane
TEST_F(GatesTest, deathaddAirplane)
{
    EXPECT_DEATH(testGate->addAirplane(NULL), "Airplane cannot be nothing");
}
//Tests the death for removeAirplane
TEST_F(GatesTest, deathremoveAirplane)
{
    EXPECT_DEATH(testGate->removeAirplane(), "Airplane cannot be NULL");
}
//Tests the standard gate functions
TEST_F(GatesTest, airplaneTest)
{
    EXPECT_EQ((unsigned int)1, testGate->getName());
    EXPECT_FALSE(testGate->isOccupied());
    EXPECT_EQ(NULL, testGate->getAirplane());
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, 1, 1, 1, testFlightplan);
    testGate->addAirplane(testAirplane);
    EXPECT_TRUE(testGate->isOccupied());
    testGate->removeAirplane();
    EXPECT_FALSE(testGate->isOccupied());
    Airplane* testAirplane2 = new Airplane("127", "Boeiing", "747", 0, 400, 15000, 3, 1, 2, testFlightplan);
    testGate->addAirplane(testAirplane2);
    EXPECT_TRUE(testGate->isOccupied());
//    EXPECT_EQ(testAirplane2->getStatus(), StandingAtGate);
    EXPECT_EQ(true, testGate->getAirplane()->properlyInitialised());
    EXPECT_EQ("127", testGate->getAirplane()->getNumber());
}
