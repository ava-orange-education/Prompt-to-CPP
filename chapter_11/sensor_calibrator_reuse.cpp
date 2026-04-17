// sensor_calibrator_reuse.cpp
// Demonstrates reusability and encapsulation of functors in sensor calibration.
#include <algorithm>
#include <iostream>
#include <vector>

// Functor definition
struct SensorCalibrator
{
    double calibrationFactor;

    // Constructor to set the calibration factor
    SensorCalibrator(double factor) : calibrationFactor(factor)
    {
    }

    // Overloaded function call operator
    double operator()(double rawValue) const
    {
        // Apply calibration and convert to Celsius
        return rawValue * calibrationFactor - 273.15;
    }
};

// Utility function to print readings
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
    // Raw sensor readings (simulated)
    std::vector<double> rawSensor1 = { 546.3, 548.1, 547.2, 549.0 };
    std::vector<double> rawSensor2 = { 620.5, 618.0, 619.8, 621.3 };

    // Create separate functor objects for different sensors
    SensorCalibrator sensor1(0.5); // Sensor 1 uses calibration factor 0.5
    SensorCalibrator sensor2(0.8); // Sensor 2 uses calibration factor 0.8

    // Prepare output vectors
    std::vector<double> calibrated1(rawSensor1.size());
    std::vector<double> calibrated2(rawSensor2.size());

    // Calibrate readings using std::transform and respective functors
    std::transform(rawSensor1.begin(), rawSensor1.end(), calibrated1.begin(), sensor1);
    std::transform(rawSensor2.begin(), rawSensor2.end(), calibrated2.begin(), sensor2);

    // Display results
    printReadings(rawSensor1, "Raw Sensor 1 readings");
    printReadings(calibrated1, "Calibrated Sensor 1 readings (Celsius)");

    printReadings(rawSensor2, "Raw Sensor 2 readings");
    printReadings(calibrated2, "Calibrated Sensor 2 readings (Celsius)");

    return 0;
}
