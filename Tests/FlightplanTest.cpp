//
// Created by Robbe Van de Velde on 2/05/18.
//

#include <gtest/gtest.h>
#include "../Flightplan.h"

class FlightplanTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        string name1 = "LAX";
        testFlightplan = new Flightplan(name1, 45, 15, 1);


    }




    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Flightplan* testFlightplan;
};

// Tests the default constructor.
TEST_F(FlightplanTest, InitTest) {
    EXPECT_TRUE(testFlightplan->properlyInitialised());
}
TEST_F(FlightplanTest, getsettest) {
    EXPECT_EQ(testFlightplan->getDestination(), "LAX");
    EXPECT_EQ(testFlightplan->getDeparture(), 45);
    EXPECT_EQ(testFlightplan->getArrival(), 15);
    EXPECT_EQ(testFlightplan->getInterval(), 1);
    string name = "ANR";
    testFlightplan->setDestination(name);
    testFlightplan->setDeparture(30);
    testFlightplan->setArrival(30);
    testFlightplan->setInterval(2);
    EXPECT_EQ(testFlightplan->getDestination(), "ANR");
    EXPECT_EQ(testFlightplan->getDeparture(), 30);
    EXPECT_EQ(testFlightplan->getArrival(), 30);
    EXPECT_EQ(testFlightplan->getInterval(), 2);
}