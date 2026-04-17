# Makefile for sample_use_after_free.cpp

CXX = g++
CXXFLAGS = -g -O1 -fsanitize=address -Wall -Wextra -pedantic

TARGET = sample_use_after_free
SRC = sample_use_after_free.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
