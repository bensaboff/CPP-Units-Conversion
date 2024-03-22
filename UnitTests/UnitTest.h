#ifndef TEST_UNITTEST_H
#define TEST_UNITTEST_H

#include <gtest/gtest.h>

class UnitTest : public ::testing::Test {
protected:
    // You can put setup code here if needed
    void SetUp() override {}

    // You can put cleanup code here if needed
    void TearDown() override {}
};

#endif  // TEST_UNITTEST_H