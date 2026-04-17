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
// sample_sensor_reading_emplace_back_timed.cpp
// Demonstrates timing and percentage difference between push_back and emplace_back

#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class SensorReading
{
  public:
    SensorReading(double value, const std::string &unit) : m_value(value), m_unit(unit)
    {
    }
    SensorReading(const SensorReading &) = default;
    SensorReading(SensorReading &&) noexcept = default;

  private:
    double m_value;
    std::string m_unit;
};

int main()
{
    constexpr size_t N = 1'000'000; // Number of insertions

    std::vector<SensorReading> readings_push;
    readings_push.reserve(N);

    std::vector<SensorReading> readings_emplace;
    readings_emplace.reserve(N);

    // Measure push_back()
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i)
    {
        SensorReading s(24.4 + i, "Celsius");
        readings_push.push_back(s);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto push_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Measure emplace_back()
    start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < N; ++i)
    {
        readings_emplace.emplace_back(24.4 + i, "Celsius");
    }
    end = std::chrono::high_resolution_clock::now();
    auto emplace_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Calculate percentage improvement
    double improvement = 0.0;
    if (push_time > 0)
        improvement = ((static_cast<double>(push_time) - emplace_time) / push_time) * 100.0;

    std::cout << "push_back() time:    " << push_time << " microseconds\n";
    std::cout << "emplace_back() time: " << emplace_time << " microseconds\n";
    std::cout << "Improvement:         " << improvement << "% faster\n";

    return 0;
}
