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
TEST_F(FlightplanTest, InitTest)
{
    EXPECT_TRUE(testFlightplan->properlyInitialised());
}
//Tests the getters and setters
TEST_F(FlightplanTest, getsettest)
{
    EXPECT_EQ("LAX", testFlightplan->getDestination());
    EXPECT_EQ((unsigned int)45, testFlightplan->getDeparture());
    EXPECT_EQ((unsigned int)15, testFlightplan->getArrival());
    EXPECT_EQ((unsigned int) 1, testFlightplan->getInterval());
    string name = "ANR";
    testFlightplan->setDestination(name);
    testFlightplan->setDeparture(30);
    testFlightplan->setArrival(30);
    testFlightplan->setInterval(2);
    EXPECT_EQ("ANR", testFlightplan->getDestination());
    EXPECT_EQ((unsigned int)30, testFlightplan->getDeparture());
    EXPECT_EQ((unsigned int)30, testFlightplan->getArrival());
    EXPECT_EQ((unsigned int)2, testFlightplan->getInterval());
}