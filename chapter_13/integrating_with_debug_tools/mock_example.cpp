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
// mock_example.cpp
// This code demonstrates the use of Google Mock to create a mock class
// and set expectations for its methods. It is intended to be used for
// testing integration with debugging tools.
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stdexcept>

class SensorReader
{
  public:
    virtual ~SensorReader() = default;
    virtual int readValue() = 0;
};

class MockSensorReader : public SensorReader
{
  public:
    MOCK_METHOD(int, readValue, (), (override));
};

int processReading(SensorReader &reader)
{
    int value = reader.readValue();
    if (value < 0)
    {
        throw std::runtime_error("negative sensor reading");
    }
    return value * 2;
}

TEST(SensorTests, DoublesPositiveReading)
{
    MockSensorReader mock;

    EXPECT_CALL(mock, readValue()).WillOnce(::testing::Return(21));

    int result = processReading(mock);
    EXPECT_EQ(result, 42);
}

TEST(SensorTests, MemoryLeakDemo)
{
    new int[1000]; // deliberate memory leak for demonstration
    SUCCEED();
}
