# C++ with AI Tools — Source Code Repository

This repository contains all source code examples, projects, and build
files for the book **C++ with AI Tools**. The code is organised by
chapter and is intended to be compiled and run alongside the reading.
Each chapter directory is self-contained and includes its own Makefile.

---

## Repository Structure

```
.
├── chapter_01/          Getting Started with C++ and AI Tools
├── chapter_02/          Understanding C++ Basics
├── chapter_03/          Control Flow and Logical Thinking
├── chapter_04/          Functions, Scope, and Modularisation
├── chapter_05/          Arrays, Strings, and STL Vectors
├── chapter_06/          Object-Oriented Programming in C++
├── chapter_07/          Pointers and Memory Management
├── chapter_08/          Inheritance and Polymorphism
├── chapter_09/          Templates and Exceptions
├── chapter_10/          Standard Template Library and Generic Programming
├── chapter_11/          Functors, Lambdas, and Move Semantics
├── chapter_12/          Multithreading and Concurrency Basics
├── chapter_13/          Debugging, Testing, and Refactoring with AI Tools
├── chapter_14/          Debugging Strategies for C++ Engineers
├── chapter_15/          Prompt Engineering for C++ Developers
└── README.md
```

Each chapter directory contains:

- All `.cpp` source files referenced in that chapter
- Any associated `.h` or `.hpp` header files
- A `Makefile` for building all examples in that chapter
- A `data_log.txt` sample data file where required (Chapter 12)

---

## Prerequisites

### Compiler

A C++17-capable compiler is required for Chapters 1–10 and 13–14.
Chapters 11, 12, and 15 use C++20 features and require a compiler with
full C++20 support.

| Compiler | Minimum Version | Notes |
|----------|----------------|-------|
| GCC (g++) | 10.0 | Recommended. All examples verified with GCC 12. |
| Clang | 12.0 | Fully supported. |
| MSVC | 19.29 (VS 2019 16.9) | C++20 support requires VS 2022. |

On Ubuntu or Debian:

```bash
sudo apt update
sudo apt install build-essential g++ cmake
```

On macOS, `g++` invokes the system Clang compiler. The examples are
compatible with Apple Clang 14 and later. For the latest GCC, install
via Homebrew:

```bash
brew install gcc
```

### Optional Tools

The following tools are used in specific chapters and are optional
unless you are working through those chapters:

| Tool | Chapter | Install (Ubuntu/Debian) |
|------|---------|------------------------|
| Valgrind | 13 | `sudo apt install valgrind` |
| GDB | 13 | `sudo apt install gdb` |
| GoogleTest | 13 | `sudo apt install libgtest-dev` |
| cscope | 14 | `sudo apt install cscope` |
| universal-ctags | 14 | `sudo apt install universal-ctags` |
| clang-tidy | 13 | `sudo apt install clang-tidy` |

---

## Building the Examples

### Building a Single Chapter

Navigate to the relevant chapter directory and run `make`:

```bash
cd chapter_05
make
```

Compiled binaries are placed in a `bin/` subdirectory within each
chapter directory. To remove all build artefacts:

```bash
make clean
```

### Building All Chapters

From the repository root:

```bash
for dir in chapter_*/; do
    echo "Building $dir ..."
    make -C "$dir" --no-print-directory
done
```

### Chapter-Specific Build Notes

**Chapter 6 — Static Library Example**

The static library example (Example 6.17) is built automatically by
`make`. It compiles `rectangle.cpp` into `librectangle.a` and then
links `customer_app.cpp` against it. The library and its header are
located in the `customer_app/` subdirectory.

**Chapter 9 — Template Definitions**

All template definitions are in header files as required by the C++
standard. Do not move template definitions to `.cpp` files — this will
produce linker errors.

**Chapter 12 — Threading**

All multithreading examples require C++20 (`-std=c++20`) and link
against pthreads (`-lpthread`). The Makefile handles both automatically.
The `data_log.txt` sample file used by the async checksum example is
included in the chapter directory.

**Chapter 13 — Sanitisers and GoogleTest**

Running `make debug` builds selected examples with AddressSanitizer and
UndefinedBehaviourSanitizer enabled. Running `make test` builds and
executes the GoogleTest suite. GoogleTest must be installed separately.

**Chapter 14 — Trace Instrumentation**

The trace example is deliberately compiled with `-O0`. Compiling with
optimisation enabled may cause the compiler to inline or reorder traced
functions, producing misleading output.

**Chapter 15 — Freestanding Example**

The freestanding buffer sort example (`sample_buffer_freestanding.cpp`)
is compiled with `-ffreestanding`. It does not link the standard
library and has no heap dependency by design.

---

## C++ Standard Reference

| Chapter | Standard Used | Key Features |
|---------|--------------|-------------|
| 1–8     | C++17        | Core language, OOP, smart pointers |
| 9       | C++17        | Templates, exceptions, `noexcept` |
| 10      | C++17        | STL containers and algorithms |
| 11      | C++20        | Lambdas, move semantics, `std::ranges` |
| 12      | C++20        | `std::jthread`, atomics, condition variables |
| 13      | C++17        | Sanitisers, GoogleTest, Valgrind |
| 14      | C++17        | Debugging tools, `cscope`, `ctags` |
| 15      | C++17/C++20  | Prompt engineering, `std::erase_if` |

---

## AI-Generated Code

Several examples throughout the book are produced by GitHub Copilot or
ChatGPT in response to prompts shown in the text. These examples are
clearly labelled in both the book and in the source file comments with
a header such as:

```cpp
// AI-GENERATED — produced by GitHub Copilot in response to the
// prompt shown in the book. Reviewed and discussed in the text.
// Do not use in production without further analysis.
```

These files are included for educational comparison purposes. They are
not presented as reference implementations.

---

## Known Intentional Bugs

Certain source files contain deliberate bugs used to demonstrate
debugging tools and techniques. These are clearly identified by their
filename and by comments in the code.

| File | Chapter | Bug Type |
|------|---------|----------|
| `buggy_factorial.cpp` | 13 | Off-by-one in loop termination |
| `sample_null_dereference.cpp` | 13 | Null pointer dereference |
| `sample_use_after_free.cpp` | 13 | Use after free |
| `program_with_use_after_free.cpp` | 13 | Heap use after free |
| `MissingVirtualDestructor.cpp` | 8 | Missing virtual destructor |
| `data_race_demo.cpp` | 12 | Intentional data race |

Do not use these files as templates for production code.

---

## Reporting Issues

If you find a discrepancy between the code in this repository and what
is shown in the book, please open an issue on the repository's issue
tracker with the following information:

- Chapter number and example number
- The observed behaviour
- The expected behaviour
- Your compiler version and operating system

---

## Licence

The source code in this repository is provided for educational use in
conjunction with the book **C++ with AI Tools**. All rights reserved.
Redistribution or commercial use without written permission from the
publisher is not permitted.
