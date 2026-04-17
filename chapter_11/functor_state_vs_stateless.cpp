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
// functor_state_vs_stateless.cpp
// This code demonstrates the difference between stateful and stateless functors in C++.
// A stateless functor does not maintain any internal state, while a stateful functor does.
#include <algorithm>
#include <iostream>
#include <vector>

// Stateless functor: squares its input without storing any state
struct Square
{
    double operator()(double x) const
    {
        return x * x;
    }
};

// Stateful functor: counts how many times it is called
struct CallCounter
{
    int count; // Internal state

    CallCounter() : count(0)
    {
    }

    double operator()(double x)
    {
        ++count; // Increment state on each call
        return x;
    }
};

int main()
{
    std::vector<double> values = { 1.5, 2.0, 3.1, 4.7 };

    std::cout << "Original values: ";
    for (double v : values)
        std::cout << v << " ";
    std::cout << '\n';

    // Using stateless functor with std::transform
    std::vector<double> squares(values.size());
    std::transform(values.begin(), values.end(), squares.begin(), Square());

    std::cout << "Squared values: ";
    for (double v : squares)
        std::cout << v << " ";
    std::cout << '\n';

    // Using stateful functor to count calls (simulates tracking a process)
    CallCounter counter;
    std::for_each(values.begin(), values.end(),
                  [&counter](double val)
                  {
                      counter(val); // state updated
                  });
    std::cout << "CallCounter was invoked " << counter.count << " times.\n";

    return 0;
}
