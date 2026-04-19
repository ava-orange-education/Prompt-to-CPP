# ==============================================================
# Chapter 9 — Templates and Exceptions
# ==============================================================
#
# Note: All template definitions must remain in header files.
# Moving a template definition to a .cpp file will produce
# linker errors because the compiler cannot instantiate the
# template for types it has not seen.
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
OUTDIR   := bin

SRCS := correct_catch_order.cpp \
        exception_sample_program_new_bad_alloc.cpp \
        exception_sample_program_vector_at.cpp \
        exception_try_catch.cpp \
        sample_bounds_count.cpp \
        sample_find_if_even.cpp \
        sample_for_each_discount.cpp \
        sample_program_exception_catch_all.cpp \
        sample_program_exception_multiple.cpp \
        sample_program_exception_rethrow.cpp \
        sample_program_full_specialization.cpp \
        sample_program_generic_data_processor.cpp \
        sample_program_partial_specialization.cpp \
        sample_program_template_argument_deduction.cpp \
        sample_program_template_instantiation.cpp \
        sample_program_template_type_error.cpp \
        sample_program_template_type_error_2.cpp \
        sample_program_terminate_destructor.cpp \
        sample_program_terminate_noexcept.cpp \
        sample_program_ub_not_fixable_by_error_codes.cpp \
        sample_program_with_class_template.cpp \
        sample_program_with_function_template.cpp \
        sample_program_without_specialization.cpp \
        sample_program_without_templates.cpp \
        set_emplace_usage.cpp \
        set_insertion_basics.cpp \
        wrong_catch_order.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

# generic_data_processor sub-project
GDP_SRC := generic_data_processor/main.cpp

.PHONY: all generic_data_processor clean

all: $(OUTDIR) $(TARGETS) generic_data_processor

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

generic_data_processor: $(GDP_SRC)
	$(CXX) $(CXXFLAGS) $< -o $(OUTDIR)/generic_data_processor

clean:
	rm -rf $(OUTDIR)
