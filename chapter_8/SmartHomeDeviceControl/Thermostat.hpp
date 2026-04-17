// Create Thermostat.hpp with the caption. Declare class Thermostat : public Device. Public overrides: name(),
// switchOn(), switchOff(), getStatus(). Add setters/getters: bool setTargetCelsius(double t); double targetCelsius()
// const;. Private: bool m_on { false }; double m_target { 21.0 };. Include "Device.hpp". Allman braces. Thermostat.hpp
#ifndef THERMOSTAT_HPP
#define THERMOSTAT_HPP
#include "Device.hpp"
#include <string>
class Thermostat : public Device
{
  public:
    std::string name() const override
    {
        return "Thermostat";
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
    bool setTargetCelsius(double t)
    {
        if (t < 5.0 || t > 30.0)
        {
            return false;
        }
        m_target = t;
        return true;
    }
    double targetCelsius() const
    {
        return m_target;
    }

  private:
    bool m_on{false};
    double m_target{21.0};
};
#endif // THERMOSTAT_HPP