# ==============================================================
# Chapter 5 — Arrays, Strings, and STL Vectors
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

SRCS := array_indexing_char.cpp \
        array_reversal_ai.cpp \
        array_size_function.cpp \
        array_traversal.cpp \
        bubble_sort_ai.cpp \
        c_style_string.cpp \
        c_style_string_strlen.cpp \
        default_initialization_demo.cpp \
        function_overloading_ai.cpp \
        memory_layout_ai.cpp \
        multi_container_stats_visualiser.cpp \
        null_terminator.cpp \
        out_of_bound_array_ai.cpp \
        out_of_bounds_access.cpp \
        out_of_bounds_demo.cpp \
        safe_access_with_at.cpp \
        segfault_example.cpp \
        std_array_example.cpp \
        std_array_traversal.cpp \
        string_literal_storage.cpp \
        string_methods_demo.cpp \
        usage_of_at_method.cpp \
        vector_capacity_methods_demo.cpp \
        vector_dynamic_array.cpp \
        vector_size_vs_capacity.cpp \
        vector_traversal.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

.PHONY: all clean

all: $(OUTDIR) $(TARGETS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)
