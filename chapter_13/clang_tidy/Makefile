# Makefile
# Builds the example program and runs clang-tidy for static analysis

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -g -O0

TARGET := clang_tidy_example
SRC := clang_tidy_example.cpp

.PHONY: all clean tidy

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

tidy:
	clang-tidy $(SRC) --config-file=.clang-tidy -- -std=c++17 -xc++ \
	-I/usr/include/c++/11 \
	-I/usr/include/x86_64-linux-gnu/c++/11

clean:
	rm -f $(TARGET)

