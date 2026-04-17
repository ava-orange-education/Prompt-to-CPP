CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g
LDFLAGS := -lgtest -lgtest_main -lgmock -pthread

SRC := mock_introduction_test.cpp
TARGET := mock_intro

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)