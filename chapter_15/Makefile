# ==============================================================
# Chapter 15 — Prompt Engineering for C++ Developers
# ==============================================================
#
# This chapter contains several sub-projects and standalone files.
#
# Sub-projects:
#   legacy_audio_playlist_manager/   C++98 legacy code (Example 15.3)
#   SharedLogFile/refined_prompt/    Thread-safe log — refined version
#   SharedLogFile/weak_prompt/       Thread-safe log — AI first version
#
# Standalone files compiled with C++17 unless noted:
#   sample_buffer_generic.cpp        Hosted environment sort example
#   sample_buffer_freestanding.cpp   Bare-metal sort (-ffreestanding)
#   sensor_cleanup_manual.cpp        Manual iterator-based cleanup
#   sensor_cleanup_modern.cpp        std::erase_if version (C++20)
#   template_error_demo.cpp          Template type mismatch example
# ==============================================================
CXX          := g++
CXXFLAGS17   := -std=c++17 -Wall -Wextra -pedantic -g
CXXFLAGS20   := -std=c++20 -Wall -Wextra -pedantic -g
FREESTANDING := -std=c++17 -Wall -Wextra -pedantic -g -ffreestanding
LDFLAGS      := -lpthread
OUTDIR       := bin

.PHONY: all standalone legacy_playlist refined_log weak_log clean

all: $(OUTDIR) standalone legacy_playlist refined_log weak_log

$(OUTDIR):
	mkdir -p $(OUTDIR)

# Standalone C++17 examples
standalone: $(OUTDIR)
	$(CXX) $(CXXFLAGS17) sample_buffer_generic.cpp    -o $(OUTDIR)/sample_buffer_generic
	$(CXX) $(CXXFLAGS17) sensor_cleanup_manual.cpp    -o $(OUTDIR)/sensor_cleanup_manual
	$(CXX) $(CXXFLAGS17) template_error_demo.cpp      -o $(OUTDIR)/template_error_demo
	$(CXX) $(FREESTANDING) sample_buffer_freestanding.cpp \
	    -o $(OUTDIR)/sample_buffer_freestanding
	$(CXX) $(CXXFLAGS20) sensor_cleanup_modern.cpp    -o $(OUTDIR)/sensor_cleanup_modern

# Legacy audio playlist (C++98 style, compiled as C++17 for compatibility)
legacy_playlist: $(OUTDIR)
	$(MAKE) -C legacy_audio_playlist_manager --no-print-directory
	cp legacy_audio_playlist_manager/bin/* $(OUTDIR)/ 2>/dev/null || true

# SharedLogFile — refined prompt version
refined_log: $(OUTDIR)
	$(MAKE) -C SharedLogFile/refined_prompt --no-print-directory
	cp SharedLogFile/refined_prompt/bin/* $(OUTDIR)/ 2>/dev/null || true

# SharedLogFile — weak prompt version
weak_log: $(OUTDIR)
	$(MAKE) -C SharedLogFile/weak_prompt --no-print-directory
	cp SharedLogFile/weak_prompt/bin/* $(OUTDIR)/ 2>/dev/null || true

clean:
	rm -rf $(OUTDIR)
	$(MAKE) -C legacy_audio_playlist_manager clean --no-print-directory 2>/dev/null || true
	$(MAKE) -C SharedLogFile/refined_prompt  clean --no-print-directory 2>/dev/null || true
	$(MAKE) -C SharedLogFile/weak_prompt     clean --no-print-directory 2>/dev/null || true
