//
// Created by Robbe Van de Velde on 21/03/18.
//

#include <gtest/gtest.h>
#include "../Gate.h"

class GatesTest: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        testGate = new Gate(1);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {
    }

    // Declares the variables your tests want to use.
    Gate* testGate;
};

// Tests the default constructor.
//TEST_F(GatesTest, DefaultConstructor) {
//    EXPECT_EQ(testGate.getName(), 5);
//}
