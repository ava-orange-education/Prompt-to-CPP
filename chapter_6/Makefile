# ==============================================================
# Chapter 6 — Object-Oriented Programming in C++
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -g
ARFLAGS  := rcs
OUTDIR   := bin

# Single-file examples
SRCS := bank_account_ai.cpp \
        class_syntax.cpp \
        const_function.cpp \
        copy_assignment_operator.cpp \
        copy_constructor_demo1.cpp \
        copy_constructor_pass_by_value.cpp \
        copy_constructor_return_by_value.cpp \
        copy_ops.cpp \
        encapsulation_example.cpp \
        encapsulation_public.cpp \
        explicit_conversion.cpp \
        first_class_design.cpp \
        implicit_conversion.cpp \
        inheritance.cpp \
        inline_initialiser.cpp \
        instantiate_class.cpp \
        member_initialiser_list.cpp \
        mutable_count.cpp \
        object_lifecycle_scope.cpp \
        operator_overload_plus.cpp \
        rectangle_member_functions.cpp \
        static_data_member_example.cpp \
        static_vs_nonstatic.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

# Zoo simulator — multi-file example (zoo/)
ZOO_OBJS := zoo/animal.o zoo/main.o

# Static library example (customer_app/)
LIB      := customer_app/librectangle.a
LIB_OBJ  := customer_app/rectangle.o

.PHONY: all zoo_simulator static_lib clean

all: $(OUTDIR) $(TARGETS) zoo_simulator static_lib

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Zoo simulator
zoo_simulator: $(ZOO_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(OUTDIR)/ZooSimulator_Inheritance

zoo/animal.o: zoo/animal.cpp zoo/animal.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

zoo/main.o: zoo/main.cpp zoo/animal.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Static library
$(LIB_OBJ): customer_app/rectangle.cpp customer_app/rectangle.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(LIB): $(LIB_OBJ)
	ar $(ARFLAGS) $@ $^

static_lib: $(LIB)
	$(CXX) $(CXXFLAGS) customer_app/customer_app.cpp \
	    -Icustomer_app -Lcustomer_app -lrectangle \
	    -o $(OUTDIR)/customer_app

clean:
	rm -rf $(OUTDIR) zoo/*.o customer_app/rectangle.o customer_app/librectangle.a
