CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g
LDFLAGS := -lgtest -lgtest_main -pthread

TARGET := my_tests
SRC := addition_google_test.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
