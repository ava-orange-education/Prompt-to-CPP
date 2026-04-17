# Compiler and flags
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Target executable
TARGET := sample_program_with_tracing

# Source files
SRCS := sample_trace_usage.cpp
OBJS := $(SRCS:.cpp=.o)

# Enable tracing by setting TRACE=1
ifeq ($(TRACE),1)
    CXXFLAGS += -DENABLE_DEBUG_TRACE
endif

# Default target
all: $(TARGET)

# Build executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
