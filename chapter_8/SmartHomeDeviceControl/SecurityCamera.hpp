// Create SecurityCamera.hpp with caption. Declare class SecurityCamera final : public Device. Public overrides: name(),
// switchOn(), switchOff(), getStatus(), bool isCritical() const (returns true). Add bool startRecording(); bool
// stopRecording();. Private: bool m_on { false }; bool m_recording { false };. Include "Device.hpp". Allman braces.
//  SecurityCamera.hpp
#ifndef SECURITYCAMERA_HPP
#define SECURITYCAMERA_HPP
#include "Device.hpp"
#include <string>
class SecurityCamera final : public Device
{
  public:
    std::string name() const override
    {
        return "SecurityCamera";
    }
    void switchOn() override
    {
        m_on = true;
    }
    void switchOff() override
    {
        m_on = false;
        m_recording = false; // Stop recording when switched off
    }
    std::string getStatus() const override
    {
        return m_on ? (m_recording ? "On, Recording" : "On, Not Recording") : "Off";
    }
    bool isCritical() const override
    {
        return true;
    }
    bool startRecording()
    {
        if (!m_on)
        {
            return false; // Cannot record if the camera is off
        }
        m_recording = true;
        return true;
    }
    bool stopRecording()
    {
        if (!m_on)
        {
            return false; // Cannot stop recording if the camera is off
        }
        m_recording = false;
        return true;
    }

  private:
    bool m_on{false};
    bool m_recording{false};
};
#endif // SECURITYCAMERA_HPP