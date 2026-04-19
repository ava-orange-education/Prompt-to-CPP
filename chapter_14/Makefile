# ==============================================================
# Chapter 14 — Debugging Strategies for C++ Engineers
# ==============================================================
#
# The trace instrumentation example is built with -O0 to ensure
# that the compiler does not inline or reorder the traced
# functions. Compiling with optimisation enabled would make the
# trace output misleading.
#
# ENABLE_DEBUG_TRACE is passed as a preprocessor define to
# activate the TRACE and TRACE_SCOPE macros in debug.h.
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g -O0

OUTDIR   := bin
TRACE_OBJ := sample_trace_usage.o
TRACE_BIN := sample_program_with_tracing

.PHONY: all clean

all: $(OUTDIR) $(OUTDIR)/$(TRACE_BIN)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(TRACE_OBJ): sample_trace_usage.cpp debug.h
	$(CXX) $(CXXFLAGS) -DENABLE_DEBUG_TRACE -c $< -o $@

$(OUTDIR)/$(TRACE_BIN): $(TRACE_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(OUTDIR) *.o
