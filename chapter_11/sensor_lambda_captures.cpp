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
// sensor_lambda_captures.cpp
// Demonstrates the use of lambdas with different capture methods to process sensor readings.
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void printReadings(const std::vector<double> &readings, const std::string &label)
{
    std::cout << label << ": ";
    for (double value : readings)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<double> readings = { 23.5, 26.2, 24.8, 27.1, 22.9 };

    // Configuration for monitoring
    double highThreshold = 25.0;
    double normalMin = 20.0;
    double normalMax = 25.0;
    std::vector<double> alertLog; // Stores high readings
    int normalCount = 0;          // Counts readings in normal range
    double sum = 0.0;             // For computing average

    // Lambda 1: Filter high readings (capture highThreshold by value)
    auto filterHigh = [highThreshold](double value) { return value > highThreshold; };

    // Lambda 2: Log high readings (capture alertLog by reference)
    auto logHigh = [&alertLog, highThreshold](double value)
    {
        if (value > highThreshold)
        {
            alertLog.push_back(value);
        }
    };

    // Lambda 3: Count normal readings (capture normalMin, normalMax, normalCount by reference)
    auto countNormal = [&normalCount, normalMin, normalMax](double value)
    {
        if (value >= normalMin && value <= normalMax)
        {
            ++normalCount;
        }
    };

    // Lambda 4: Accumulate sum for average (capture sum by reference, catch-all)
    auto accumulateSum = [&](double value) { sum += value; };

    // Process readings
    std::vector<double> highReadings;
    std::copy_if(readings.begin(), readings.end(), std::back_inserter(highReadings), filterHigh);

    std::for_each(readings.begin(), readings.end(), logHigh);
    std::for_each(readings.begin(), readings.end(), countNormal);
    std::for_each(readings.begin(), readings.end(), accumulateSum);

    // Print results
    printReadings(readings, "All readings");
    printReadings(highReadings, "High readings (> 25°C)");
    printReadings(alertLog, "Logged alerts");
    std::cout << "Normal range readings (20-25°C): " << normalCount << '\n';
    std::cout << "Average reading: " << (sum / readings.size()) << '\n';

    return 0;
}