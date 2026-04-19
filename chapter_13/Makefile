# ==============================================================
# Chapter 13 — Debugging, Testing, and Refactoring with AI Tools
# ==============================================================
#
# Chapter 13 is organised into sub-projects, each with its own
# Makefile in a dedicated subdirectory. This top-level Makefile
# builds all sub-projects and provides a unified clean target.
#
# Sub-projects and their purposes:
#   buggy_factorial/           Intentional bug for GDB walkthrough
#   clang_tidy/                Static analysis with clang-tidy
#   core_dump_example/         Core dump generation and analysis
#   cppcheck_example/          Static analysis with cppcheck
#   data_processor/            Legacy code for refactoring demo
#   first_google_test/         GoogleTest unit test introduction
#   googlemock_intro/          GoogleMock introduction
#   integrating_with_debug_tools/  Mock example with GDB integration
#   sample_null_dereference/   Null dereference with AddressSanitizer
#   strace_example/            strace system call tracing
#   valgrind_example/          Valgrind memory error detection
#
# Requirements:
#   GoogleTest / GoogleMock  sudo apt install libgtest-dev libgmock-dev
#   Valgrind                 sudo apt install valgrind
#   GDB                      sudo apt install gdb
#   clang-tidy               sudo apt install clang-tidy
#   cppcheck                 sudo apt install cppcheck
# ==============================================================

SUBDIRS := buggy_factorial \
           clang_tidy \
           core_dump_example \
           cppcheck_example \
           data_processor \
           first_google_test \
           googlemock_intro \
           integrating_with_debug_tools \
           sample_null_dereference \
           strace_example \
           valgrind_example

.PHONY: all clean $(SUBDIRS)

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ --no-print-directory

clean:
	for dir in $(SUBDIRS); do \
	    $(MAKE) -C $$dir clean --no-print-directory; \
	done
