// addition_google_test.cpp
// This code demonstrates a simple Google Test for an addition function.
#include <gtest/gtest.h>

int add(int a, int b)
{
    return a + b;
}

TEST(AdditionTests, AddsTwoNumbers)
{
    EXPECT_EQ(add(2, 3), 5);
}
