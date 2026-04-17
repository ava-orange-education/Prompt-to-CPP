# Makefile (excerpt)

CXX      = g++
CXXFLAGS = -g -O0 -fsanitize=address,undefined
LDFLAGS  = -fsanitize=address,undefined

debug_demo: sample_null_dereference.o
	$(CXX) $(CXXFLAGS) -o debug_demo sample_null_dereference.o $(LDFLAGS)

sample_null_dereference.o: sample_null_dereference.cpp
	$(CXX) $(CXXFLAGS) -c sample_null_dereference.cpp
