/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
// mock_introduction_test.cpp
// This code demonstrates the use of Google Mock to create a mock class
// and set expectations for its methods.
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// An interface representing some external service.
class CalculatorService
{
  public:
    virtual ~CalculatorService() = default;
    virtual int add(int a, int b) = 0;
};

// A mock implementation of the interface.
class MockCalculatorService : public CalculatorService
{
  public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

// Code under test. It relies on a CalculatorService.
int computeSum(CalculatorService &service, int x, int y)
{
    return service.add(x, y);
}

TEST(MockTests, UsesMockToVerifyBehaviour)
{
    MockCalculatorService mock;

    // Define how the mock should behave.
    EXPECT_CALL(mock, add(2, 3)).WillOnce(testing::Return(5));

    int result = computeSum(mock, 2, 3);
    EXPECT_EQ(result, 5);
}
