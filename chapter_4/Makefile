# ==============================================================
# Chapter 4 — Functions, Scope, and Modularisation
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

# Single-file examples
SRCS := addition_no_function.cpp \
        ambiguous_default.cpp \
        argument_order_overloading.cpp \
        default_argument.cpp \
        factorial.cpp \
        fibonacci_recursive.cpp \
        function_addition.cpp \
        function_definition.cpp \
        function_invocation.cpp \
        function_overloading.cpp \
        function_overloading_ai.cpp \
        function_overloading_ai_fixed.cpp \
        inline_square.cpp \
        modular_example.cpp \
        nodiscard_safesquare.cpp \
        non_modular.cpp \
        parameter_passing.cpp \
        pass_by_pointer.cpp \
        pass_by_reference.cpp \
        pass_by_value.cpp \
        stack_trace.cpp \
        unit_converter.cpp \
        unit_converter_with_recursive.cpp \
        use_return_value.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

# Multi-file area calculation project (AreaProject/)
AREA_OBJS := AreaProject/area.o AreaProject/main.o

.PHONY: all area_project clean

all: $(OUTDIR) $(TARGETS) area_project

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

area_project: $(AREA_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(OUTDIR)/area_calculation_program

AreaProject/area.o: AreaProject/area.cpp AreaProject/area.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

AreaProject/main.o: AreaProject/main.cpp AreaProject/area.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTDIR) AreaProject/*.o
