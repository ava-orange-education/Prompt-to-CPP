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
