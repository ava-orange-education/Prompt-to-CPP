# ==============================================================
# Chapter 3 — Control Flow and Logical Thinking
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

SRCS := access_control_evaluator.cpp \
        access_control_fallthrough.cpp \
        auto_generated_menu.cpp \
        copilot_prompt.cpp \
        do_while_basic_example.cpp \
        event_access_validator.cpp \
        factorial.cpp \
        fallthrough_demo.cpp \
        first_negative_break.cpp \
        fixed_loop_counter.cpp \
        fixed_number_printer.cpp \
        infinite_loop_bug.cpp \
        loop_tracer.cpp \
        menu_retry_system.cpp \
        menu_switch_example.cpp \
        number_classification.cpp \
        number_guess_ai.cpp \
        number_guess_human.cpp \
        number_sequence_printer.cpp \
        off_by_one_bug.cpp \
        short_circuit_simple.cpp \
        skip_even_continue.cpp \
        temperature_check.cpp \
        temperature_check_simple.cpp \
        temperature_range_classifier.cpp \
        unit_converter.cpp \
        valid_input_checker.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

.PHONY: all clean

all: $(OUTDIR) $(TARGETS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)
