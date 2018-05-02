//
// Created by Robbe Van de Velde on 21/03/18.
//


#include <gtest/gtest.h>
#include "../Runway.h"
#include "../Flightplan.h"
#include "../Airplane.h"

class RunwayTest: public ::testing::Test {
protected:
	// You should make the members protected s.t. they can be
	// accessed from sub-classes.

	// virtual void SetUp() will be called before each test is run.  You
	// should define it if you need to initialize the variables.
	// Otherwise, this can be skipped.
	virtual void SetUp() {
        testRunway = new Runway(3, "R11", "FLAT", "ANR");

    }

	// virtual void TearDown() will be called after each test is run.
	// You should define it if there is cleanup work to do.  Otherwise,
	// you don't have to provide it.
	virtual void TearDown() {
	}

	// Declares the variables your tests want to use.
    Runway* testRunway;
};



// Tests the "happy day" scenario


////
TEST_F(RunwayTest, Initcheck){
    EXPECT_TRUE(testRunway->properlyInitialised());
    EXPECT_EQ(3, testRunway->getLength());
    EXPECT_EQ("R11", testRunway->getName());
    EXPECT_EQ("FLAT", testRunway->getType());
    EXPECT_EQ("ANR", testRunway->getAirport());
}

TEST_F(RunwayTest, aiport) {
    EXPECT_EQ(testRunway->getAirport(), "ANR");
    testRunway->setAirport("newairport");
    EXPECT_EQ(testRunway->getAirport(), "newairport");
}
TEST_F(RunwayTest, airplanetest) {
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, "militairy", "jet", "small", testFlightplan);
    testRunway->setAirplane(testAirplane);
    EXPECT_EQ(testRunway->getAirplane()->getFlightplan()->getArrival(), 45);
    EXPECT_EQ(testRunway->getAirplane()->getFlightplan()->getDestination(), "LAX");
    EXPECT_EQ(testRunway->getAirplane()->getHeight(), 0);
    testRunway->getAirplane()->setStatus(4);
//    EXPECT_EQ(testRunway->getAirplane()->getStatus(), InTheAir);
}


//
//
//
//}
//TEST_F(RunwayTest, nondefaultconst){
//    EXPECT_EQ(testRunway.getAirport(), "ANR");
//    testRunway.setAirport("BRS");
//    EXPECT_EQ(testRunway.getAirport(), "BRS");
//    EXPECT_EQ(testRunway.getName(), "R11");
//
//}
