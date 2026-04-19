# ==============================================================
# Chapter 2 — Understanding C++ Basics
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

# Single-translation-unit examples
SRCS := block_scope_exploration.cpp \
        compilation_stage_demo.cpp \
        const_demo.cpp \
        extended_memory_explorer.cpp \
        file_static_scope.cpp \
        global_variable_usage.cpp \
        initialization_styles.cpp \
        large_stack_allocation.cpp \
        linking_error_demo.cpp \
        local_variable_scope.cpp \
        memory_explorer.cpp \
        narrowing_check.cpp \
        narrowing_conversion_warning.cpp \
        preprocessing_demo.cpp \
        print_type_sizes.cpp \
        stack_frame_visual.cpp \
        stack_overflow_example.cpp \
        stack_vs_heap_allocation.cpp \
        static_counter_demo.cpp \
        static_variable_lifetime.cpp \
        syntax_error_missing_semicolon.cpp \
        type_conversions.cpp \
        volatile_demo.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

# Multi-file extern linkage example (file1.cpp + file2.cpp)
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
