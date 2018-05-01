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
    EXPECT_EQ(3, testRunway->get_length());
    EXPECT_EQ("R11", testRunway->get_name());
    EXPECT_EQ("FLAT", testRunway->get_type());
    EXPECT_EQ("ANR", testRunway->get_airport());
}

TEST_F(RunwayTest, aiport) {
    EXPECT_EQ(testRunway->get_airport(), "ANR");
    testRunway->set_airport("newairport");
    EXPECT_EQ(testRunway->get_airport(), "newairport");
}
TEST_F(RunwayTest, airplanetest) {
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, "militairy", "jet", "small", testFlightplan);
    testRunway->set_airplane(testAirplane);
    EXPECT_EQ(testRunway->get_airplane()->getFlightplan()->getArrival(), 45);
    EXPECT_EQ(testRunway->get_airplane()->getFlightplan()->getDestination(), "LAX");
    EXPECT_EQ(testRunway->get_airplane()->getHeight(), 0);
    testRunway->get_airplane()->setStatus(4);
    EXPECT_EQ(testRunway->get_airplane()->getStatus(), InTheAir);
}


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
