// Write a complete, fully compilable C++ program in a single file named sample_program_generic_data_processor.cpp.
// The program should demonstrate generic data processing using templates and exception handling.
// Requirements:
// - Only use standard library headers needed for the demo: <vector>, <functional>, <stdexcept>, <iostream>.
// - Do not create any additional header files or split code into multiple files.
// - In main.cpp, define a template function processData:
//   - Accepts a const reference to std::vector<T> and std::function<void(const T&)> as arguments.
//   - Throws std::invalid_argument if the vector is empty.
//   - Otherwise, applies the operation to each item.
// - In main():
//   1. Process a vector of integers with processData, using a lambda that throws std::runtime_error if the value is
//   negative, else prints the value.
//   2. Demonstrate exception handling for an empty vector.
// - Use try-catch blocks for std::invalid_argument, std::runtime_error, and std::exception.
// - No "using namespace std;" or std::endl.
// - All definitions and the main function must be in main.cpp only, with no extra header files or includes.
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> void processData(const std::vector<T> &data, const std::function<void(const T &)> &operation)
{
    if (data.empty())
    {
        throw std::invalid_argument("Input vector is empty");
    }
    for (const auto &item : data)
    {
        operation(item);
    }
}

int main()
{
    // 1. Process a vector of integers
    std::vector<int> numbers = {1, 2, -3, 4};
    try
    {
        processData<int>(numbers,
                         [](const int &value)
                         {
                             if (value < 0)
                             {
                                 throw std::runtime_error("Negative value encountered: " + std::to_string(value));
                             }
                             std::cout << "Value: " << value << '\n';
                         });
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid argument: " << e.what() << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Runtime error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }

    // 2. Demonstrate exception handling for an empty vector
    std::vector<int> emptyVec;
    try
    {
        processData<int>(emptyVec, [](const int &value) { std::cout << "Should not be called" << '\n'; });
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught invalid_argument for empty vector: " << e.what() << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Runtime error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
    return 0;
}