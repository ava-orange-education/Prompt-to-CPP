# Makefile for sample_reallife_crash.cpp
# Purpose: Build the reallife crash example used for core-dump analysis.

CXX      := g++
CXXFLAGS := -g -O0 -Wall -Wextra
TARGET   := sample_reallife_crash
SOURCE   := sample_reallife_crash.cpp

# Default target
all: $(TARGET)

# Build rule
$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean generated files
clean:
	rm -f $(TARGET)

# Full rebuild
rebuild: clean all
