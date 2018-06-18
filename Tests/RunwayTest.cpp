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

        testRunway = new Runway(3, "R11", Grass, "ANR");

    }

	// virtual void TearDown() will be called after each test is run.
	// You should define it if there is cleanup work to do.  Otherwise,
	// you don't have to provide it.
	virtual void TearDown() {
	}

	// Declares the variables your tests want to use.
    Runway* testRunway;
};

//initcheck
TEST_F(RunwayTest, Initcheck){
    EXPECT_TRUE(testRunway->properlyInitialised());
    EXPECT_EQ((unsigned int)3, testRunway->getLength());
    EXPECT_EQ("R11", testRunway->getName());
    //EXPECT_EQ(Grass, testRunway->getType());
    EXPECT_EQ("ANR", testRunway->getAirport());
}

TEST_F(RunwayTest, aiport) {
    EXPECT_EQ("ANR", testRunway->getAirport());
    testRunway->setAirport("newairport");
    EXPECT_EQ("newairport", testRunway->getAirport());
}
TEST_F(RunwayTest, airplanetest) {
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, 1, 1, 1, testFlightplan);
    testRunway->setAirplane(testAirplane);
    EXPECT_EQ((unsigned int)45,testRunway->getAirplane()->getFlightplan()->getArrival());
    EXPECT_EQ("LAX", testRunway->getAirplane()->getFlightplan()->getDestination());
    EXPECT_EQ((unsigned int)0, testRunway->getAirplane()->getHeight());
    testRunway->getAirplane()->setStatus(4);
}
//death test for adding second aircraft
TEST_F(RunwayTest, airplaneAddDeadtest) {
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, 1, 1, 1, testFlightplan);
    testRunway->setAirplane(testAirplane);
    Airplane* testAirplane2 = new Airplane("2", "calls", "model", 0, 110, 5000, 1, 1, 1, testFlightplan);
    EXPECT_DEATH(testRunway->addAirplane(testAirplane2), "Airplane must point to a nullptr");
}
//deathtest for having wrong status
TEST_F(RunwayTest, airplaneAddDeadtest2) {
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, 1, 1, 1, testFlightplan);
    testRunway->setStatus(true);
    EXPECT_DEATH(testRunway->addAirplane(testAirplane), "Status must be false");
}
//remove nonexistant airplane
TEST_F(RunwayTest, airplaneremoveDeadtest) {
    EXPECT_DEATH(testRunway->removeAirplane(), "Airplane must point to an airplane and not a nullptr");
}
//status is false
TEST_F(RunwayTest, airplaneremoveDeadtest2) {
    string name = "LAX";
    Flightplan* testFlightplan = new Flightplan(name, 15, 45, 1);
    Airplane* testAirplane = new Airplane("32", "callsign", "model", 0, 110, 5000, 1, 1, 1, testFlightplan);
    testRunway->addAirplane(testAirplane);
    testRunway->setStatus(false);
    EXPECT_DEATH(testRunway->removeAirplane(), "Status must be true because the space is occupied");
}
//Tests the type enum
TEST_F(RunwayTest, runwayTypeDeath) {
    EXPECT_DEATH(testRunway->setType(2), "type enum must be smaller than 2");
}
//Tests the constructor
TEST_F(RunwayTest, constructorDeath) {
    EXPECT_DEATH(Runway rw(11,"R11", 4, "ANR"), "type enum must be smaller than 2");
}

