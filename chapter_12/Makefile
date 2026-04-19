# ==============================================================
# Chapter 12 — Multithreading and Concurrency Basics
# ==============================================================
#
# Requires C++20 for std::jthread and cooperative interruption.
# Links against pthreads on Linux.
#
# data_log.txt is required by async_file_checksum.cpp and
# async_file_checksum_wait_for.cpp. It is included in this
# directory and must be present when running those examples.
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic -g
LDFLAGS  := -lpthread
OUTDIR   := bin

SRCS := ai_assisted_thread_safe_queue.cpp \
        ai_assisted_thread_safe_queue_final.cpp \
        async_file_checksum.cpp \
        async_file_checksum_wait_for.cpp \
        atomic_operations_example.cpp \
        condition_variable_example.cpp \
        condition_variable_example_modified.cpp \
        condition_variable_notify_all.cpp \
        condition_variable_notify_all_modified.cpp \
        data_race_demo.cpp \
        mutex_lock_guard_demo.cpp \
        sample_jthread_cooperative_stop.cpp \
        sample_jthread_raii.cpp \
        scoped_thread.cpp \
        shared_mutex_cache.cpp \
        thread_creation.cpp \
        thread_detach.cpp \
        thread_detach_example.cpp \
        thread_detach_example_remove_detach.cpp \
        thread_return_result.cpp \
        unique_lock_flexible.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

.PHONY: all clean

all: $(OUTDIR) $(TARGETS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -rf $(OUTDIR)
