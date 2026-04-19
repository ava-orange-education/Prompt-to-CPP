# ==============================================================
# Chapter 10 — Standard Template Library and Generic Programming
# ==============================================================
CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2
OUTDIR   := bin

SRCS := sample_bounds_count.cpp \
        sample_find_if_even.cpp \
        sample_find_names.cpp \
        sample_for_each_discount.cpp \
        sample_list_systemlog.cpp \
        sample_lru_cache.cpp \
        sample_map_config.cpp \
        sample_map_custom_comparator_insert.cpp \
        sample_multimap_student_courses.cpp \
        sample_sensor_reading_emplace_back.cpp \
        sample_sensor_reading_emplace_back_timed.cpp \
        sample_set_userids.cpp \
        sample_sort_scores.cpp \
        sample_transform_add.cpp \
        sample_transform_inplace.cpp \
        sample_transform_temperature.cpp \
        sample_unordered_map_dns.cpp \
        sample_vector_sensors.cpp \
        sample_vector_sensors_erase.cpp \
        set_emplace_usage.cpp \
        set_find_example.cpp \
        set_insertion_basics.cpp \
        set_traversal_example.cpp

TARGETS := $(patsubst %.cpp,$(OUTDIR)/%,$(SRCS))

.PHONY: all clean

all: $(OUTDIR) $(TARGETS)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(OUTDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)
