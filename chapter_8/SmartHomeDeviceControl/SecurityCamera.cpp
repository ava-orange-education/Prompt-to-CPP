// Implement SecurityCamera.cpp. name() returns “SecurityCamera”. switchOn() sets m_on = true. switchOff() sets
// m_recording = false; m_on = false. startRecording() only if m_on; sets m_recording = true. stopRecording() sets
// m_recording = false. isCritical() returns true. getStatus() returns SecurityCamera[on, rec] or SecurityCamera[off].
// No using namespace std.
//  SecurityCamera.cpp
#include "SecurityCamera.hpp"
#include <sstream>
#include <string>
std::string SecurityCamera::getStatus() const
{
    std::ostringstream status;
    status << "SecurityCamera[" << (m_on ? (m_recording ? "on, rec" : "on, not rec") : "off") << "]";
    return status.str();
}