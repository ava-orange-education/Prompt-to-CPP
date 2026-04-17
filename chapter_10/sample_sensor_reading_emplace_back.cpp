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
// sample_sensor_reading_emplace_back.cpp
// Demonstrates the difference between push_back and emplace_back with a class
#include <iostream>
#include <string>
#include <vector>

class SensorReading
{
  public:
    SensorReading(const SensorReading &)
    {
        std::cout << "SensorReading copied\n";
    }
    SensorReading(SensorReading &&) noexcept
    {
        std::cout << "SensorReading moved\n";
    }
    SensorReading(double value, const std::string &unit) : m_value(value), m_unit(unit)
    {
        std::cout << "SensorReading constructed\n";
    }

  private:
    double m_value;
    std::string m_unit;
};

int main()
{
    std::vector<SensorReading> readings;
    readings.reserve(2);

    std::cout << "Using push_back with pre-built object:\n";
    SensorReading s(24.4, "Celsius");
    readings.push_back(s);

    std::cout << "\nUsing emplace_back:\n";
    // Using emplace_back constructs the object directly in place
    readings.emplace_back(24.4, "Celsius");

    return 0;
}
