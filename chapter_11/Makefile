# ==============================================================
# Chapter 11 — Functors, Lambdas, and Move Semantics
# ==============================================================
#
# Requires C++20 for std::ranges used in several examples.
# Most examples will also compile under C++17 if ranges are
# not exercised. Override with:
#   make CXXFLAGS="-std=c++17 -Wall -Wextra -O2"
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic -O2
OUTDIR   := bin

SRCS := calibrated_reduction_main.cpp \
        functor_state_vs_stateless.cpp \
        lambda_example.cpp \
        lvalue_rvalue_references.cpp \
        packet_buffer_move_semantics.cpp \
        sample_expression_temporary.cpp \
        sample_function_return_temporary.cpp \
        sample_implicit_conversion_temporary.cpp \
        sample_program_ai_assisted_sensor_pipeline.cpp \
        sample_program_temporary_binding.cpp \
        sensor_aggregator.cpp \
        sensor_calibration_functor.cpp \
        sensor_calibrator_reuse.cpp \
        sensor_data_aggregator.cpp \
        sensor_data_aggregator_ai_first_version.cpp \
        sensor_data_aggregator_compilation_fixed.cpp \
        sensor_lambda_captures.cpp \
        sensor_lambda_stl.cpp \
        task_queue_move_forward.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

.PHONY: all clean

all: $(OUTDIR) $(TARGETS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)
