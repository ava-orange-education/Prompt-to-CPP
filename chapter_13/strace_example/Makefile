# Makefile for missing_config.cpp
# Purpose: Build the example used to demonstrate strace diagnostics.

CXX      := g++
CXXFLAGS := -g -O0 -Wall -Wextra
TARGET   := missing_config
SOURCE   := missing_config.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean build artefacts
clean:
	rm -f $(TARGET)

# Rebuild from scratch
rebuild: clean all
