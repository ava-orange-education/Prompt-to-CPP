// Create Light.hpp with a top comment and the caption. Declare class Light : public Device. Public overrides: name(),
// switchOn(), switchOff(), getStatus(). Add bool setBrightness(int level) (0–100). Private state: bool m_on { false };
// int m_brightness { 50 };. Include "Device.hpp". Use Allman braces, no using namespace std.
//  Light.hpp
#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "Device.hpp"
#include <string>
class Light : public Device
{
  public:
    std::string name() const override
    {
        return "Light";
    }
    void switchOn() override
    {
        m_on = true;
    }
    void switchOff() override
    {
        m_on = false;
    }
    std::string getStatus() const override
    {
        return m_on ? "On" : "Off";
    }
    bool setBrightness(int level)
    {
        if (level < 0 || level > 100)
        {
            return false;
        }
        m_brightness = level;
        return true;
    }

  private:
    bool m_on{false};
    int m_brightness{50};
};
#endif // LIGHT_HPP