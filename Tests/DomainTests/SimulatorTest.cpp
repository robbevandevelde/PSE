//
// Created by uauser on 8/27/18.
//

#include <gtest/gtest.h>
#include "../../Simulator.h"

class SimulatorTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        string naam = "route";
        testFlightplan = new Flightplan(naam, 5, 6, 7);
        testRunway1 = new Runway(3000, "Alpha", Asphalt, "Zaventem");
        testRunway2 = new Runway(500,"Bravo", Grass, "Zaventem");
        vector<Runway*> runways;
        runways.push_back(testRunway1);
        runways.push_back(testRunway2);
        testAirplane1 = new Airplane("Klein", "Propeller", "EF11",Approaching,50,50,Airline, Propeller, Small,testFlightplan);
        testAirplane1->setHeight(10000);
        testAirplane2 = new Airplane("Medium", "Jet","EFEF", Approaching, 50,50, Airline,Jet, Medium,testFlightplan);
        vector<Airplane*> airplanes;
        airplanes.push_back(testAirplane1);
        airplanes.push_back(testAirplane2);
        testAirport = new Airport(2, "Zaventem", "f444", "Echo");
        john = new AirTrafficController(testAirport, "John");
        testAirport->assignController(john);
        testSimulator  = new Simulator(runways, airplanes, testAirport);
        testSimulator->addRunways();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Simulator* testSimulator;
    Flightplan* testFlightplan;
    Airplane* testAirplane1;
    Airplane* testAirplane2;
    Runway* testRunway1;
    Runway* testRunway2;
    Airport* testAirport;
    AirTrafficController* john;
};
TEST_F(SimulatorTest, initCheck) {
    EXPECT_EQ(testAirplane1->getStatus(), Approaching);
}
