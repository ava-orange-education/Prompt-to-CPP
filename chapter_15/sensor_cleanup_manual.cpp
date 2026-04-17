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
// sensor_cleanup_manual.cpp
// Demonstrates cleaning up invalid sensor readings using manual iteration
#include <iostream>
#include <vector>

struct SensorRead
{
    int id;
    double value;
    bool is_valid;
};

void cleanup_sensors(std::vector<SensorRead> &readings)
{
    for (auto it = readings.begin(); it != readings.end(); )
    {
        if (!it->is_valid || it->value < 0.0 || it->value > 500.0)
        {
            it = readings.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

int main()
{
    std::vector<SensorRead> readings{
        {1, 250.5, true},
        {2, -10.0, true},
        {3, 100.0, false},
        {4, 600.0, true},
        {5, 45.0, true}
    };

    cleanup_sensors(readings);

    for (const auto &r : readings)
    {
        std::cout << "Sensor ID: " << r.id
                  << " Value: " << r.value << "\n";
    }

    return 0;
}
