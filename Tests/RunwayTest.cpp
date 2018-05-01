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
        testRunway = new Runway(3, "R11", "ANR", "ANR");

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

TEST_F(RunwayTest, aiport) {
    EXPECT_EQ(testRunway->get_airport(), "ANR");
    testRunway->set_airport("newairport");
    EXPECT_EQ(testRunway->get_airport(), "newairport");
}

////
//TEST_F(RunwayTest, airplane){
//    Flightplan* testFlightplan = new Flightplan("LAX", 15, 45, 1);
//    Airplane* testAirplane = Airplane("32", "callsign", "model", "status", 110, 5000, "militairy", "jet", "small", testFlightplan);    testRunway.setAirplane(airplane);
//
//
//
//
//}
//TEST_F(RunwayTest, nondefaultconst){
//    EXPECT_EQ(testRunway.get_airport(), "ANR");
//    testRunway.set_airport("BRS");
//    EXPECT_EQ(testRunway.get_airport(), "BRS");
//    EXPECT_EQ(testRunway.get_name(), "R11");
//
//}
