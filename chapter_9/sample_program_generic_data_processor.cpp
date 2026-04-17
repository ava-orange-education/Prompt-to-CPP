// sample_program_generic_data_processor.cpp
// Demonstrate a template-based data processor with exception handling.

#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T> void processData(const std::vector<T> &data, std::function<void(const T &)> operation)
{
    if (data.empty())
    {
        throw std::invalid_argument("Data set cannot be empty");
    }

    for (const auto &item : data)
    {
        operation(item);
    }
}

int main()
{
    try
    {
        std::vector<int> values{1, 2, 3, 4, 5};

        processData<int>(values,
                         [](const int &x)
                         {
                             if (x < 0)
                             {
                                 throw std::runtime_error("Negative value encountered");
                             }
                             std::cout << "Processed value: " << x << '\n';
                         });

        // Try with an empty dataset to trigger an exception
        std::vector<int> empty;
        processData<int>(empty, [](const int &x) { std::cout << x << '\n'; });
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid input: " << e.what() << '\n';
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Runtime error: " << e.what() << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "Unexpected error: " << e.what() << '\n';
    }

    return 0;
}