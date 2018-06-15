//
// Created by uauser on 6/15/18.
//

#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include "../Parsers/LuchthavenParser.h"
#include "../AirportUtils.h"



using namespace std;

class OutputTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
//        testParser = new LuchthavenParser();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    LuchthavenParser testParser;
};
TEST_F(OutputTest, InitCheck) {
    EXPECT_TRUE(testParser.properlyInitialised());
}
