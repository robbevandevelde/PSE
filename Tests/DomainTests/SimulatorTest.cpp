//
// Created by uauser on 8/27/18.
//

#include <gtest/gtest.h>
#include "../../Simulator.h"
#include "../../Parsers/LuchthavenParser.h"

class SimulatorTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testParser = new LuchthavenParser();
        if(testParser->loadFile("InputFiles/luchthaven.xml")) {
            testParser->parseItems("InputFiles/luchthaven.xml");

            vector<Runway *> runwaysVect = testParser->getRunways();
            vector<Airport *> airportsVect = testParser->getAirports();
            vector<Airplane *> airplanesVect = testParser->getAirplanes();
            testParser->writeToFile(runwaysVect, airportsVect, airplanesVect, "OutputFiles/simulatie.txt");
            AirTrafficController *Alain = new AirTrafficController(airportsVect[0], "Alain Clement");
            airportsVect[0]->assignController(Alain);

            testSimulator = new Simulator(runwaysVect, airplanesVect, airportsVect[0]);
        }
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }
    LuchthavenParser* testParser;
    Simulator* testSimulator;
    // Declares the variables your tests want to use.

};
TEST_F(SimulatorTest, initCheck) {
    ofstream myfile;
    myfile.open("testOutput/Output03.txt");
    testSimulator->doStep(myfile);

    EXPECT_TRUE(testSimulator->getAirplanes()[1]->getHeight() < 10000);
    testSimulator->doStep(myfile);

    EXPECT_TRUE(testSimulator->getAirplanes()[2]->getHeight() < 10000);

    myfile.close();

}
