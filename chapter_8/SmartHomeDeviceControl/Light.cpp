// Implement Light.cpp. name() returns “Light”. switchOn() sets m_on = true; switchOff() sets m_on = false.
// setBrightness() clamps to [0,100] and returns true. getStatus() returns Light[on, 75%] style text. Include <string>
// as needed. No using namespace std.
//  Light.cpp
#include "Light.hpp"
#include <sstream>
#include <string>
std::string Light::getStatus() const
{
    std::ostringstream status;
    status << "Light[" << (m_on ? "on" : "off") << ", " << m_brightness << "%]";
    return status.str();
}