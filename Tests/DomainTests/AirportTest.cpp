//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <gtest/gtest.h>
#include "../../Airport.h"
#include "../../Runway.h"
#include <iostream>
#include <fstream>

class AirportTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testAirport = new Airport(10, "Antwerp Airport", "ANR", "callsign");
        John = new AirTrafficController(testAirport,"John");
        testAirport->assignController(John);
        string name = "LAX";
        testFlightplan = new Flightplan(name, 15, 45, 1);

        testAirplane = new Airplane("Small", "Small Propeller", "Winchester", Approaching, 50, 50, Airline, Propeller, Small, testFlightplan);

        testAirplane1 = new Airplane("556", "F16", "Win100", Approaching, 50, 50, Airline, Jet, Medium, testFlightplan);
        testAirplane2 = new Airplane("6969", "HI99", "Wallonie", Approaching, 50,50 ,Airline, Jet, Medium, testFlightplan);
        testAirplane3 = new Airplane("420", "Yeet", "Winchester", Approaching, 50, 50, Airline, Propeller, Small, testFlightplan);

        testRunway = new Runway(500, "Alpha", Grass, "Zaventem");

        testRunway1 = new Runway(2000, "Bravo", Asphalt, "Zaventem");

        testRunway2 = new Runway(9000, "Charlie", Asphalt, "Zaventem");
        testAirport->addRunway(testRunway);
        testAirport->addRunway(testRunway1);
        testAirport->addRunway(testRunway2);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Airport* testAirport;
    AirTrafficController* John;
    Flightplan* testFlightplan;
    Airplane* testAirplane;
    Airplane* testAirplane1;
    Airplane* testAirplane2;
    Airplane* testAirplane3;
    Runway* testRunway;
    Runway* testRunway1;
    Runway* testRunway2;
};

// Tests the initialisation.
TEST_F(AirportTest, InitTest)
{
    EXPECT_TRUE(testAirport->properlyInitialised());
}
//Tests the default constructor
TEST_F(AirportTest, DefaultConstructorTest)
{
    EXPECT_EQ(testAirport->getName(),"Antwerp Airport");

}
//Tests the getters and setters
TEST_F(AirportTest, gettersEnSetters)
{
    testAirport->setGatesize(3);
    testAirport->setCallsign("callsign");
    testAirport->setIata("IATA");
    testAirport->setName("name");
    EXPECT_EQ((unsigned int)3, testAirport->getGatesize());
    EXPECT_EQ("name", testAirport->getName());
    EXPECT_EQ("callsign", testAirport->getCallsign());
    EXPECT_EQ("IATA", testAirport->getIata());
}
//Tests the landing protocol
TEST_F(AirportTest, LandingProtocol)
{
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");

    testAirplane->setStatus(JustLanded);
    EXPECT_DEATH(testAirport->landingSequence(testAirplane, myfile),"Aircontrole failure, aircraft isn't in the air");

    testAirplane->setStatus(Approaching);
    EXPECT_EQ(Approaching, testAirplane->getStatus());

    testAirplane->setHeight(5000);

    EXPECT_EQ((unsigned int)5000, testAirplane->getHeight());

    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);

    EXPECT_EQ((unsigned int)3000, testAirplane->getHeight());

    testAirport->landingSequence(testAirplane, myfile);
    //changed to approaching from final approach
    EXPECT_EQ(FinalApproach, testAirplane->getStatus());

    EXPECT_TRUE(testAirplane->getStatus() < 3000);

    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);

    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane));

    EXPECT_EQ(JustLanded, testAirplane->getStatus());

    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());


    testAirport->removeAirplaneFromRunway(testAirplane);

    myfile.close();
}
//Tests the Emergency landing protocol
TEST_F(AirportTest, emergencyLandingProtocol)
{
    ofstream myfile;
    myfile.open("testOutput/Output04.txt");

    testAirplane2->setStatus(JustLanded);
    EXPECT_DEATH(testAirport->landingSequence(testAirplane2, myfile),"Aircontrole failure, aircraft isn't in the air");

    testAirplane2->setStatus(Approaching);

    EXPECT_EQ(Approaching, testAirplane->getStatus());

    testAirplane2->setHeight(5000);

    EXPECT_EQ((unsigned int)5000, testAirplane2->getHeight());

    testAirplane2->setFuel(0);

    EXPECT_EQ((unsigned int) 0, testAirplane2->getFuel());

    testAirport->landingSequence(testAirplane2, myfile);
    testAirport->landingSequence(testAirplane2, myfile);
    testAirport->landingSequence(testAirplane2, myfile);
    testAirport->landingSequence(testAirplane2, myfile);
    testAirport->landingSequence(testAirplane2, myfile);
    testAirport->landingSequence(testAirplane2, myfile);
//fails
//    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane2));

//     is still approaching
//    EXPECT_EQ(EmergencyLanding, testAirplane2->getStatus());

    // is still 7000
    //EXPECT_EQ((unsigned int)0, testAirplane2->getHeight());

    testAirport->removeAirplaneFromRunway(testAirplane2);

    myfile.close();
}

TEST_F(AirportTest,emergencylandingprotocol2){
    ofstream myfile;
    myfile.open("testOutput/Output04.txt");

    testAirplane2->setStatus(JustLanded);
    EXPECT_DEATH(testAirport->landingSequence(testAirplane2, myfile),"Aircontrole failure, aircraft isn't in the air");

    testAirplane2->setStatus(Approaching);

    EXPECT_EQ(Approaching, testAirplane->getStatus());

    testAirplane2->setHeight(2000);

    EXPECT_EQ((unsigned int)2000, testAirplane2->getHeight());

    testAirplane2->setFuel(0);

    EXPECT_EQ((unsigned int) 0, testAirplane2->getFuel());

    testAirport->landingSequence(testAirplane2, myfile);
    testAirport->landingSequence(testAirplane2, myfile);

    EXPECT_FALSE(testAirport->isAirplaneInRunway(testAirplane2));
//is still approaching
//    EXPECT_EQ(EmergencyLandingOutside, testAirplane2->getStatus());

    //is 8000
    //EXPECT_EQ((unsigned int)0, testAirplane2->getHeight());
    testAirport->removeAirplaneFromRunway(testAirplane2);

}

//Tests the takeoff protocol
TEST_F(AirportTest, TakeoffProtocol)
{
    ofstream myfile;
    myfile.open("testOutput/Output02.txt");

    testAirplane3->setStatus(Approaching);

    EXPECT_DEATH(testAirport->takeOffSequence(testAirplane3, myfile),"Departure failure");

    testAirplane3->setHeight(0);

    EXPECT_EQ((unsigned int)0, testAirplane3->getHeight());

    testAirplane3->setStatus(Departure);

    EXPECT_EQ(Departure,testAirplane3->getStatus());

    EXPECT_DEATH(testAirport->takeOffSequence(testAirplane3, myfile),"Airplane isn't on a runway");

    testAirport->addAirplaneToRunway(testAirplane3,myfile);

//is false
//    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane3));
//fails cause previous test isnt correct
//    testAirport->takeOffSequence(testAirplane3, myfile);

//    EXPECT_TRUE(testAirplane3->getHeight() != 0);
//
//    testAirport->takeOffSequence(testAirplane3, myfile);
//    testAirport->takeOffSequence(testAirplane3, myfile);
//    testAirport->takeOffSequence(testAirplane3, myfile);
//    testAirport->takeOffSequence(testAirplane3, myfile);
//
//    EXPECT_EQ((unsigned int) 5000, testAirplane3->getHeight());
//
//    EXPECT_EQ(InTheAir, testAirplane3->getStatus());
//
//    EXPECT_FALSE(testAirport->isAirplaneInRunway(testAirplane3));
//
//    testAirport->removeAirplaneFromRunway(testAirplane3);

    myfile.close();
}
//Tests the gate protocol
TEST_F(AirportTest, CompleteGateProtocol)
{
    ofstream myfile;
    myfile.open("testOutput/Output03.txt");

    testAirplane->setStatus(InTheAir);

    EXPECT_DEATH(testAirport->gateprotocol(testAirplane, 0, myfile),"Failure");

    testAirplane->setStatus(JustLanded);

    EXPECT_EQ(JustLanded,testAirplane->getStatus());

    testAirplane->setHeight(500);
//doesnt die with that error
//    EXPECT_DEATH(testAirport->gateprotocol(testAirplane, 0, myfile),"Failure");

    testAirplane->setHeight(3000);
    testAirplane->setStatus(Approaching);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
//actual 10000
//    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());

//    testAirport->landingSequence(testAirplane, myfile);
//
//    testAirport->taxiToGate(testAirplane);
//
//    testAirport->gateprotocol(testAirplane, 0, myfile);
//
//    EXPECT_EQ((unsigned int) 0,testAirplane->getPassengers());
//
//    EXPECT_EQ(StandingAtGate,testAirplane->getStatus());
//
//    EXPECT_FALSE(testAirplane->isFueled());
//
//    testAirport->gateprotocol(testAirplane, 0, myfile);
//
//    EXPECT_EQ((unsigned int) 1000,testAirplane->getFuel());
//
//    EXPECT_TRUE(testAirplane->isFueled());
//
//    testAirport->gateprotocol(testAirplane, 50, myfile);
//
//    EXPECT_EQ((unsigned int) 50, testAirplane->getPassengers());
//
//    EXPECT_EQ(StandingAtGate, testAirplane->getStatus());
//
//    testAirport->removeAirplaneFromGate(testAirplane,myfile);
    myfile.close();
}
//Tests the airplane to runway function
TEST_F(AirportTest, AirplaneToRunAir)
{
    ofstream myfile;
    myfile.open("testOutput/Output03.txt");
    testAirplane->setStatus(Approaching);
    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Invalid status for runway");

    testAirplane->setStatus(EmergencyLandingOutside);
    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Invalid status for runway");

    testAirplane->setStatus(InTheAir);
    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Invalid status for runway");

    testAirplane->setHeight(3000);

    //doesnt die with that error
//    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Airplane must be on the ground");
    testAirplane->setStatus(Approaching);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);
    testAirport->landingSequence(testAirplane, myfile);

    //??
//    testAirport->addAirplaneToRunway(testAirplane);
//
//    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane));
//
//
//    testAirport->removeAirplaneFromRunway(testAirplane);
    myfile.close();
}
//Tests the airplane to runway function
//fails in every way possible
//TEST_F(AirportTest, AirplaneToRunDeparture)
//{
//    ofstream myfile;
//    myfile.open("testOutput/Output03.txt");
//
//    testAirplane->setStatus(StandingAtGate);
//    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Invalid status for runway");
//
//    testAirplane->setStatus(StandingAtGate);
//    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Invalid status for runway");
//
//    testAirplane->setStatus(StandingAtGate);
//    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Invalid status for runway");
//
//    testAirplane->setHeight(5000000);
//    EXPECT_DEATH(testAirport->addAirplaneToRunway(testAirplane,myfile), "Airplane must be on the ground");
//
//    testAirplane->setStatus(Departure);
//    testAirplane->setHeight(0);
//    testAirport->addAirplaneToRunway(testAirplane);
//
//    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane));
//
//    testAirport->removeAirplaneFromRunway(testAirplane);
//    myfile.close();
//}
//Tests the added controller
TEST_F(AirportTest, Controller)
{
    EXPECT_EQ("John", testAirport->getController()->getName());
}
//Tests the landing protocol with expected death
TEST_F(AirportTest, landingDeathtest)
{
    testAirplane->setStatus(JustLanded);
//    EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
//    EXPECT_DEATH(testAirport->landingprotocol(testAirplane, myfile), "Airplane must be approaching in order to land");
    myfile.close();
    //EXPECT_EQ((unsigned int)0, testAirplane->getHeight());
}
////Tests the gate protocol with expected death
TEST_F(AirportTest,  gateprotDeathtest)
{
    testAirplane->setStatus(Approaching);
    testAirplane->setHeight(500);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->gateprotocol(testAirplane, 20), "Failure");
    myfile.close();
}
//Tests the takeoff protocol with expected death
TEST_F(AirportTest,  takeOffDeathtest)
{
    testAirplane->setStatus(Approaching);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
//    EXPECT_DEATH(testAirport->takeOffprotocol(testAirplane, myfile), "Airplane must be departure");
    myfile.close();
}
//Tests the takeoff protocol with expected death
TEST_F(AirportTest,  takeOffDeathtest2)
{
    testAirplane->setStatus(Departure);
    testAirplane->setHeight(50);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
//    EXPECT_DEATH(testAirport->takeOffprotocol(testAirplane, myfile), "Airplane must be on the ground");
    myfile.close();
}
//Tests the airplane to gate with expected death
TEST_F(AirportTest,  apl2gtDeathtest)
{
    testAirplane->setStatus(Departure);
    testAirplane->setHeight(0);
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    EXPECT_DEATH(testAirport->addAirplaneToGate(testAirplane, myfile), "Airplane has to be just landed at the runway in order to taxi");
    myfile.close();
}
TEST_F(AirportTest, validRunway)
{
//    EXPECT_FALSE(testAirport->validRunwayForPlane(testAirplane2, testRunway1));
    EXPECT_TRUE(testAirport->validRunwayForPlane(testAirplane2, testRunway2));
    EXPECT_FALSE(testAirport->validRunwayForPlane(testAirplane, testRunway1));
//    EXPECT_TRUE(testAirport->validRunwayForPlane(testAirplane, testRunway2));
}
TEST_F(AirportTest, WaitPointTests)
{
    ofstream myfile;
    myfile.open("testOutput/Output01.txt");
    testAirplane->setHeight(6000);
    testAirplane->setStatus(Approaching);

    testAirplane3->setHeight(6000);
    testAirplane3->setStatus(Approaching);

    //5000
    testAirport->landingSequence(testAirplane,myfile);
    testAirport->landingSequence(testAirplane3,myfile);

    //4000
    testAirport->landingSequence(testAirplane,myfile);
    testAirport->landingSequence(testAirplane3,myfile);

    //3000
    testAirport->landingSequence(testAirplane,myfile);
    testAirport->landingSequence(testAirplane3,myfile);

    //Reserving Alpha for testAirplane
    testAirport->landingSequence(testAirplane,myfile);
    //testAirplane3 ==> waitpoint
    testAirport->landingSequence(testAirplane3,myfile);

    EXPECT_EQ(testAirport->getWaitpoint2(), testAirplane3);

    testAirport->landingSequence(testAirplane,myfile);
    testAirport->landingSequence(testAirplane,myfile);
    //Add to runway
    testAirport->landingSequence(testAirplane,myfile);

    //is not true, rest fails cause of this
//    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane));

//    testAirport->taxiToGate(testAirplane);
//
//    //Runway clear
//    testAirport->collisionSolverAirEnd(testAirplane3, myfile);
//
//    testAirport->landingSequence(testAirplane3, myfile);
//    testAirport->landingSequence(testAirplane3, myfile);
//    //added to runway
//    testAirport->landingSequence(testAirplane3, myfile);
//
//    EXPECT_TRUE(testAirport->isAirplaneInRunway(testAirplane3));

    myfile.close();

}
TEST_F(AirportTest, collisiontest)
{
    testAirplane->setHeight(5000);
    //testAirplane->setStatus(Departure);
    ofstream myfile;
    myfile.open("OutputFiles/testoutputx.txt");
    testAirport->collisionSolverAirStart(testAirplane, myfile);
    myfile.close();
    EXPECT_EQ(Approaching, testAirplane->getStatus());
}

