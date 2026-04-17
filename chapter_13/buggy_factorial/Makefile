# Makefile for buggy_factorial.cpp
# Purpose: Build and run the off-by-one factorial bug example.

CXX      := g++                  			# Compiler
CXXFLAGS := -g -O0 -Wall -Wextra 			# Debug info, no opt, warnings
TARGET   := buggy_factorial                 # Output binary
SOURCE   := buggy_factorial.cpp  			# Your file

# Default target
all: $(TARGET)

# Build: source → binary
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@

# Remove binary
clean:
	rm -f $(TARGET)

# Rebuild from scratch
rebuild: clean all