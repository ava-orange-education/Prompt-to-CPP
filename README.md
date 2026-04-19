# Prompt-to-CPP: Source Code Repository

This repository contains all source code examples, projects, and build
files for the book **Prompt-to-CPP**. Each chapter directory is
self-contained and includes a Makefile. The examples are intended to be
compiled and run alongside the reading.

---

## Repository Structure

```
.
├── helloworld/              Chapter 1:  Getting Started with C++ and AI Tools
├── chapter_2/               Chapter 2:  Understanding C++ Basics
├── chapter_3/               Chapter 3:  Control Flow and Logical Thinking
├── chapter_4/               Chapter 4:  Functions, Scope, and Modularisation
│   └── AreaProject/             Multi-file area calculation project
├── chapter_5/               Chapter 5:  Arrays, Strings, and STL Vectors
├── chapter_6/               Chapter 6:  Object-Oriented Programming in C++
│   ├── zoo/                     Zoo simulator multi-file project
│   └── customer_app/            Static library example
├── chapter_7/               Chapter 7:  Pointers and Memory Management
├── chapter_8/               Chapter 8:  Inheritance and Polymorphism
│   └── SmartHomeDeviceControl/  Multi-file smart home project
├── chapter_9/               Chapter 9:  Templates and Exceptions
│   └── generic_data_processor/  Template processor sub-project
├── chapter_10/              Chapter 10: STL and Generic Programming
├── chapter_11/              Chapter 11: Functors, Lambdas, and Move Semantics
├── chapter_12/              Chapter 12: Multithreading and Concurrency Basics
│   └── data_log.txt             Sample data file for async checksum examples
├── chapter_13/              Chapter 13: Debugging, Testing, and Refactoring
│   ├── buggy_factorial/
│   ├── clang_tidy/
│   ├── core_dump_example/
│   ├── cppcheck_example/
│   ├── data_processor/
│   ├── first_google_test/
│   ├── googlemock_intro/
│   ├── integrating_with_debug_tools/
│   ├── sample_null_dereference/
│   ├── strace_example/
│   └── valgrind_example/
├── chapter_14/              Chapter 14: Debugging Strategies for C++ Engineers
├── chapter_15/              Chapter 15: Prompt Engineering for C++ Developers
│   ├── legacy_audio_playlist_manager/
│   └── SharedLogFile/
│       ├── refined_prompt/
│       └── weak_prompt/
├── LICENSE
└── README.md
```

---

## Prerequisites

### Compiler

Chapters 1 to 10 and 13 to 14 require a C++17-capable compiler.
Chapters 11, 12, and parts of Chapter 15 use C++20 features.

| Compiler | Minimum Version | C++20 Support |
|----------|----------------|--------------|
| GCC (g++) | 10.0 | Full from GCC 11. GCC 12 recommended. |
| Clang | 12.0 | Full from Clang 14. |
| MSVC | 19.29 (VS 2019 16.9) | Full from VS 2022 17.0. |

**Ubuntu / Debian:**

```bash
sudo apt update
sudo apt install build-essential g++ cmake
```

**macOS:** The `g++` command on macOS invokes Apple Clang, not GCC.
Apple Clang 14 and later support all C++20 features used in this book.
To install GCC via Homebrew:

```bash
brew install gcc
```

Then invoke it explicitly as `g++-13` (or whichever version Homebrew
installed) rather than `g++`.

### Optional Tools

The following tools are used in specific chapters. Install only those
relevant to the chapters you are working through.

| Tool | Chapter | Ubuntu / Debian |
|------|---------|----------------|
| GDB | 13 | `sudo apt install gdb` |
| Valgrind | 13 | `sudo apt install valgrind` |
| cppcheck | 13 | `sudo apt install cppcheck` |
| clang-tidy | 13 | `sudo apt install clang-tidy` |
| strace | 13 | `sudo apt install strace` |
| GoogleTest | 13 | `sudo apt install libgtest-dev libgmock-dev` |
| cscope | 14 | `sudo apt install cscope` |
| universal-ctags | 14 | `sudo apt install universal-ctags` |

---

## Building the Examples

### Building a Single Chapter

Navigate to the chapter directory and run `make`:

```bash
cd chapter_5
make
```

Compiled binaries are placed in a `bin/` subdirectory. To remove all
build artefacts:

```bash
make clean
```

### Building All Chapters

From the repository root:

```bash
for dir in helloworld chapter_2 chapter_3 chapter_4 chapter_5 \
           chapter_6 chapter_7 chapter_8 chapter_9 chapter_10 \
           chapter_11 chapter_12 chapter_13 chapter_14 chapter_15; do
    echo "==> Building $dir"
    make -C "$dir" --no-print-directory
done
```

---

## Chapter-Specific Notes

### Chapter 1: helloworld/

The Chapter 1 examples are located in the `helloworld/` directory rather
than `chapter_1/`. The single file in `chapter_1/` (`heap_memory_example.cpp`)
is referenced in later chapters for cross-chapter search examples.

### Chapter 4: AreaProject

The area calculation multi-file project is in `chapter_4/AreaProject/`.
The top-level Makefile builds it automatically alongside the single-file
examples.

### Chapter 6: Zoo Simulator and Static Library

Running `make` builds three things: the single-file OOP examples, the
zoo simulator (`zoo/` subdirectory), and the static library demo
(`customer_app/`). The prebuilt `librectangle.a` in `customer_app/` is
rebuilt from source by the Makefile.

### Chapter 8: SmartHomeDeviceControl

The smart home project in `SmartHomeDeviceControl/` is a multi-file
example with a device hierarchy spanning four source files and four
headers. The Makefile handles all dependencies automatically.

### Chapter 9: Template Definitions

All template definitions are in header files. Moving any template
definition to a `.cpp` file will cause linker errors at build time,
because the compiler cannot instantiate the template for types it has
not seen when compiling the definition.

### Chapter 12: Threading and data_log.txt

All multithreading examples require C++20 and link against pthreads
(`-lpthread`). The `data_log.txt` file in `chapter_12/` is required by
the async checksum examples (`async_file_checksum.cpp` and
`async_file_checksum_wait_for.cpp`). The examples must be run from the
`chapter_12/` directory so that the file is found at the expected path.

### Chapter 13: Sub-Projects

Chapter 13 is structured as a collection of independent sub-projects,
each in its own subdirectory with its own Makefile. The top-level
`chapter_13/Makefile` builds all sub-projects in sequence. Individual
sub-projects can be built in isolation:

```bash
cd chapter_13/first_google_test
make
```

GoogleTest and GoogleMock must be installed before building the test
sub-projects (`first_google_test/` and `googlemock_intro/`).

### Chapter 14: Trace Instrumentation

The trace example is compiled with `-O0`. Compiling with any
optimisation level may cause the compiler to inline or reorder traced
functions, producing trace output that does not reflect source-level
execution order. The `ENABLE_DEBUG_TRACE` preprocessor define is passed
by the Makefile to activate the `TRACE` and `TRACE_SCOPE` macros in
`debug.h`.

### Chapter 15: Freestanding and C++20 Examples

`sample_buffer_freestanding.cpp` is compiled with `-ffreestanding` and
has no dependency on the standard library heap. `sensor_cleanup_modern.cpp`
uses `std::erase_if` and requires C++20. The Makefile selects the
correct standard flag for each target automatically.

---

## C++ Standard Reference

| Chapter | Standard | Key Features Used |
|---------|----------|------------------|
| 1 to 8 | C++17 | Core language, OOP, smart pointers |
| 9 | C++17 | Templates, exceptions, `noexcept` |
| 10 | C++17 | STL containers, algorithms |
| 11 | C++20 | Lambdas, move semantics, `std::ranges` |
| 12 | C++20 | `std::jthread`, atomics, `std::stop_token` |
| 13 | C++17 | Sanitisers, GoogleTest, GoogleMock |
| 14 | C++17 | Trace instrumentation, debugging tools |
| 15 | C++17/C++20 | Prompt engineering, `std::erase_if` |

---

## AI-Generated Code

Certain source files in this repository were produced by GitHub Copilot
or ChatGPT in response to prompts shown in the book. These files are
identified by their filename (for example, `*_ai.cpp`,
`*_ai_first_version.cpp`, `weak_prompt/`) and by a comment header in
the source:

```cpp
// AI-GENERATED: produced by GitHub Copilot / ChatGPT in response
// to the prompt shown in the book. Reviewed and discussed in the
// accompanying text. Not intended as a reference implementation.
```

These examples are included for educational comparison. They illustrate
both what AI tools produce by default and how targeted prompting can
improve the output.

---

## Known Intentional Bugs

The following files contain deliberate bugs used to demonstrate
debugging tools and techniques. They are not defects in the repository.

| File | Chapter | Bug |
|------|---------|-----|
| `chapter_13/buggy_factorial/buggy_factorial.cpp` | 13 | Off-by-one in loop bound |
| `chapter_13/sample_null_dereference/sample_null_dereference.cpp` | 13 | Null pointer dereference |
| `chapter_13/valgrind_example/program_with_use_after_free.cpp` | 13 | Heap use after free |
| `chapter_13/cppcheck_example/sample_use_after_free.cpp` | 13 | Use after free |
| `chapter_8/MissingVirtualDestructor.cpp` | 8 | Missing virtual destructor |
| `chapter_12/data_race_demo.cpp` | 12 | Intentional data race |

---

## Reporting Issues

If you find a discrepancy between the source code in this repository and
what is shown in the book, please open an issue with the following
information:

- Chapter number and example number
- Filename
- Observed behaviour (compiler error, wrong output, crash)
- Expected behaviour
- Compiler version and operating system

---

## Licence

The source code in this repository is provided for educational use in
conjunction with the book **Prompt-to-CPP**. All rights reserved.
Redistribution or commercial use without written permission from the
publisher is not permitted.
