// sensor_cleanup_modern.cpp
// Demonstrates cleaning up invalid sensor readings using std::erase_if
#include <algorithm>
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
    std::erase_if(readings, [](const SensorRead &r)
    {
        return !r.is_valid || r.value < 0.0 || r.value > 500.0;
    });
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
