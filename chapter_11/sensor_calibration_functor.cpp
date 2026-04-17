// sensor_calibration_functor.cpp
// This code demonstrates the use of a functor to calibrate sensor readings.
// The functor applies a calibration factor to raw sensor data.
#include <algorithm>
#include <iostream>
#include <vector>

struct SensorCalibrator
{
    double calibrationFactor;

    SensorCalibrator(double factor) : calibrationFactor(factor)
    {
    }

    double operator()(double rawValue) const
    {
        return rawValue * calibrationFactor - 273.15;
    }
};

void printReadings(const std::vector<double> &readings)
{
    for (double value : readings)
    {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<double> rawReadings = { 546.3, 548.1, 547.2, 549.0 }; // Raw sensor values
    std::vector<double> calibratedReadings(rawReadings.size());

    // Create a functor for a sensor with calibration factor 0.5
    SensorCalibrator calibrator(0.5);

    // Use std::transform with the functor to calibrate readings
    std::transform(rawReadings.begin(), rawReadings.end(), calibratedReadings.begin(), calibrator);

    std::cout << "Raw readings: ";
    printReadings(rawReadings);
    std::cout << "Calibrated readings (Celsius): ";
    printReadings(calibratedReadings);

    return 0;
}