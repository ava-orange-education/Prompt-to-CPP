# ==============================================================
# Chapter 2 — Understanding C++ Basics
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

SRCS := block_scope_exploration.cpp \
        compilation_stage_demo.cpp \
        const_demo.cpp \
        extended_memory_explorer.cpp \
        file_static_scope.cpp \
        fixed_width_integers.cpp \
        global_variable_usage.cpp \
        hardware_monitor.cpp \
        initialization_styles.cpp \
        large_stack_allocation.cpp \
        type_conversions.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

# Multi-file extern example
EXTERN_OBJS := file1.o file2.o

.PHONY: all extern_example clean

all: $(OUTDIR) $(TARGETS) extern_example

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

extern_example: $(EXTERN_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(OUTDIR)/extern_example

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUTDIR) *.o
