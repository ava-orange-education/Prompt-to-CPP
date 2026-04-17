// Implement Thermostat.cpp. name() returns “Thermostat”. switchOn/Off toggle m_on. setTargetCelsius() clamps to
// [5.0, 30.0] and stores in m_target. getStatus() returns Thermostat[on, 21.0C] style text. No using namespace std.
//  Thermostat.cpp
#include "Thermostat.hpp"
#include <sstream>
#include <string>
std::string Thermostat::getStatus() const
{
    std::ostringstream status;
    status << "Thermostat[" << (m_on ? "on" : "off") << ", " << m_target << "C]";
    return status.str();
}