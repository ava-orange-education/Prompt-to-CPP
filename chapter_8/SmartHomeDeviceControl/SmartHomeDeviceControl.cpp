// Create SmartHomeDeviceControl.cpp with a top-of-file comment and the caption “Example 8.9: Smart Home Device Control
// System”. Include "Light.hpp", "Thermostat.hpp", and "SecurityCamera.hpp", plus <iostream>, <memory>, <vector>.
//  Define exactly one free utility function:
// static void audit(const Device &d);
// It should print <name> [critical] -> <status> when isCritical() is true, otherwise <name> -> <status>.
//  In main(), create std::vector<std::unique_ptr<Device>> devices; and emplace one Light, one Thermostat, and one
//  SecurityCamera. Sequence:
// Switch all devices on via the base interface.
// Safely downcast with dynamic_cast to configure device-specific behaviour:
// For Light, call setBrightness(75).
// For Thermostat, call setTargetCelsius(22.0).
// For SecurityCamera, call startRecording().
// Iterate and call audit(*device) for each device (demonstrates polymorphism).
// Switch all devices off, then audit again.
// Use Allman braces, no using namespace std, and mark all overrides in the device classes with override. The base class
// must have a virtual destructor. Example 8.9: Smart Home Device Control System
#include "Light.hpp"
#include "SecurityCamera.hpp"
#include "Thermostat.hpp"
#include <iostream>
#include <memory>
#include <vector>
static void audit(const Device &d)
{
    std::cout << d.name() << (d.isCritical() ? " [critical]" : "") << " -> " << d.getStatus() << '\n';
}
int main()
{
    std::vector<std::unique_ptr<Device>> devices;
    devices.emplace_back(std::make_unique<Light>());
    devices.emplace_back(std::make_unique<Thermostat>());
    devices.emplace_back(std::make_unique<SecurityCamera>());
    for (const auto &device : devices)
    {
        device->switchOn();
        if (auto light = dynamic_cast<Light *>(device.get()))
        {
            light->setBrightness(75);
        }
        else if (auto thermostat = dynamic_cast<Thermostat *>(device.get()))
        {
            thermostat->setTargetCelsius(22.0);
        }
        else if (auto camera = dynamic_cast<SecurityCamera *>(device.get()))
        {
            camera->startRecording();
        }
    }
    for (const auto &device : devices)
    {
        audit(*device);
    }
    for (const auto &device : devices)
    {
        device->switchOff();
    }
    for (const auto &device : devices)
    {
        audit(*device);
    }
    return 0;
}