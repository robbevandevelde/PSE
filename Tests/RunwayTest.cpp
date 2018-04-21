//
// Created by Robbe Van de Velde on 21/03/18.
//


#include <gtest/gtest.h>
#include "../Runway.h"

class RunwayTest: public ::testing::Test {
protected:
	// You should make the members protected s.t. they can be
	// accessed from sub-classes.

	// virtual void SetUp() will be called before each test is run.  You
	// should define it if you need to initialize the variables.
	// Otherwise, this can be skipped.
	virtual void SetUp() {
        testRunway = Runway();
        testRunway2 = Runway("R11", "ANR");

    }

	// virtual void TearDown() will be called after each test is run.
	// You should define it if there is cleanup work to do.  Otherwise,
	// you don't have to provide it.
	virtual void TearDown() {
	}

	// Declares the variables your tests want to use.
    Runway testRunway;
    Runway testRunway2;
};

// Tests the default constructor.
TEST_F(RunwayTest, DefaultConstructor) {
    EXPECT_EQ(testRunway.getName(), "");
}

// Tests the "happy day" scenario
TEST_F(RunwayTest, Status) {
    EXPECT_EQ(testRunway.getStatus(), false);
    testRunway.setStatus(true);
    EXPECT_EQ(testRunway.getStatus(), true);
    testRunway.setStatus(false);
    EXPECT_EQ(testRunway.getStatus(), false);

}

TEST_F(RunwayTest, aiport) {
    EXPECT_EQ(testRunway.getAirport(), "");
    testRunway.setAirport("newairport");
    EXPECT_EQ(testRunway.getAirport(), "newairport");
}

//
TEST_F(RunwayTest, airplane){
    Airplane airplane("32", "callsign", "model", "landed", 122);
    testRunway.setAirplane(airplane);
    EXPECT_EQ(testRunway.getAirplane().getNumber(), "32");
    testRunway.removeAirplane();
    EXPECT_EQ(testRunway.getAirplane().getNumber(), "");


}
TEST_F(RunwayTest, nondefaultconst){
    EXPECT_EQ(testRunway2.getAirport(), "ANR");
    testRunway2.setAirport("BRS");
    EXPECT_EQ(testRunway2.getAirport(), "BRS");
    EXPECT_EQ(testRunway2.getName(), "R11");

}
