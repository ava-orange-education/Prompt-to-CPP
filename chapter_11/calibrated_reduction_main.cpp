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
// calibrated_reduction_main.cpp
// This code demonstrates a custom reduction operation using a functor to process
// high-frequency telemetry data in C++17.
#include <numeric>
#include <vector>
#include <iostream>

struct CalibratedAccumulator
{
    double factor;

    explicit CalibratedAccumulator(double f)
        : factor(f)
    {
    }

    double operator()(double acc, double raw) const
    {
        constexpr double kelvinToCelsius = 273.15;
        return acc + (raw * factor - kelvinToCelsius);
    }
};

int main()
{
    // High-frequency telemetry data (example values)
    const std::vector<double> rawReadings{ 546.3, 548.1, 547.2, 549.0 };

    if (rawReadings.empty())
    {
        std::cerr << "Error: No telemetry data available.\n";
        return 1;
    }

    CalibratedAccumulator calibrator{ 0.5 };

    const double total = std::accumulate(rawReadings.begin(),
                                         rawReadings.end(),
                                         0.0,
                                         calibrator);

    const double average = total / static_cast<double>(rawReadings.size());

    std::cout << "Processed " << rawReadings.size() << " readings.\n";
    std::cout << "Mean calibrated temperature: " << average << " °C\n";

    return 0;
}
