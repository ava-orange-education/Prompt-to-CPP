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
