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
