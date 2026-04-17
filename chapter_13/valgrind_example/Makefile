CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic -g -O0

TARGET := programme_with_use_after_free
SRC := programme_with_use_after_free.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET)
