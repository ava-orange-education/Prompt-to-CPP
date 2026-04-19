# ==============================================================
# Chapter 8 — Inheritance and Polymorphism
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

# Single-file examples
SRCS := abstract_shape.cpp \
        bank_account_demo.cpp \
        base_pointer_derived_object.cpp \
        diamond_problem.cpp \
        FinalSpecifierExample.cpp \
        function_overriding.cpp \
        function_overriding_example2.cpp \
        function_overriding_example3.cpp \
        MissingVirtualDestructor.cpp \
        music_player_override_example.cpp \
        MusicPlayerOverrideImportance.cpp \
        name_hiding.cpp \
        name_hiding_scope_resolution_operator.cpp \
        ObjectSlicingExample.cpp \
        polymorphism_demo.cpp \
        polymorphism_simple.cpp \
        virtual_dispatch.cpp \
        virtual_inheritance_demo.cpp \
        writing_interface_function.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

# Smart Home device control — multi-file example (SmartHomeDeviceControl/)
SHD_DIR  := SmartHomeDeviceControl
SHD_SRCS := $(SHD_DIR)/SmartHomeDeviceControl.cpp \
             $(SHD_DIR)/Light.cpp \
             $(SHD_DIR)/Thermostat.cpp \
             $(SHD_DIR)/SecurityCamera.cpp
SHD_OBJS := $(SHD_SRCS:.cpp=.o)
SHD_HDRS := $(SHD_DIR)/Device.hpp \
             $(SHD_DIR)/Light.hpp \
             $(SHD_DIR)/Thermostat.hpp \
             $(SHD_DIR)/SecurityCamera.hpp

.PHONY: all smarthome clean

all: $(OUTDIR) $(TARGETS) smarthome

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

smarthome: $(SHD_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(OUTDIR)/SmartHomeDeviceControl

$(SHD_DIR)/%.o: $(SHD_DIR)/%.cpp $(SHD_HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTDIR) $(SHD_DIR)/*.o
