/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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