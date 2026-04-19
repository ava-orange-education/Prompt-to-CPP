# ==============================================================
# Chapter 7 — Pointers and Memory Management
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

SRCS := array_pointer_size.cpp \
        class_template_example.cpp \
        dynamic_array_demo.cpp \
        dynamic_class_allocation.cpp \
        dynamic_memory_demo.cpp \
        image_processor_leaky.cpp \
        image_processor_raii.cpp \
        nullptr_demo.cpp \
        passing_array.cpp \
        pointer_arithmetic.cpp \
        pointer_arithmetic_array_demo.cpp \
        sample_promts_ai.cpp \
        shared_ptr_circular.cpp \
        shared_ptr_intro.cpp \
        unique_ptr_basic_ai.cpp \
        unique_ptr_get.cpp \
        unique_ptr_intro.cpp \
        unique_ptr_reset_switch.cpp \
        void_pointer_demo.cpp \
        weak_ptr_fix.cpp \
        weak_ptr_intro.cpp \
        weak_ptr_lock_pattern.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

.PHONY: all clean

all: $(OUTDIR) $(TARGETS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)
