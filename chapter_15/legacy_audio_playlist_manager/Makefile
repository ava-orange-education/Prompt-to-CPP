# Compiler and Flags
CXX      = g++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -pedantic

# Target executable name
TARGET   = playlist_manager

# Source files
SRC      = legacy_audio_playlist_manager.cpp
OBJ      = $(SRC:.cpp=.o)

# Default rule: Compile the project
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile the source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule: Remove compiled files
clean:
	rm -f $(TARGET) $(OBJ)

# Run rule: Compile and then execute
run: all
	./$(TARGET)

.PHONY: all clean run