CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -O0 -g
LDFLAGS  := -lgtest -lgtest_main -pthread

SRC      := legacy_dataprocessor.cpp
TARGET   := legacy_tests

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET) --gtest_color=yes

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all \
	         --track-origins=yes --error-exitcode=1 ./$(TARGET)

clean:
	rm -f $(TARGET)

