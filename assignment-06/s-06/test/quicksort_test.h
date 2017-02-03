#ifndef MIDTERM_ASSIGNMENT_CHUNKS_TEST_H
#define MIDTERM_ASSIGNMENT_CHUNKS_TEST_H

#include <gtest/gtest.h>
#include "TestBase.h"

class QuicksortTest : public ::testing::Test {

public:

    QuicksortTest() {
        LOG_MESSAGE("Opening test suite: QuicksortTest");
    }

    virtual ~QuicksortTest() {
        LOG_MESSAGE("Closing test suite: QuicksortTest");
    }

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }

};

#endif //MIDTERM_ASSIGNMENT_CHUNKS_TEST_H
