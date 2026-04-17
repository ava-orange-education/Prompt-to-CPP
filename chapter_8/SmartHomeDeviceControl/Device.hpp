// Create Device.hpp. Add a top comment with the filename and caption “Example 8.9.1: Abstract base Device”. Declare an
// abstract class Device with a virtual destructor, virtual std::string name() const (default “Device”), pure virtuals
// virtual void switchOn() = 0; virtual void switchOff() = 0; virtual std::string getStatus() const = 0;. Also add
// virtual bool isCritical() const returning false. Use Allman braces and no using namespace std. Device.hpp
// Example 8.9.1: Abstract base Device
#ifndef DEVICE_HPP
#define DEVICE_HPP
#include <string>
class Device
{
  public:
    virtual ~Device() = default;
    virtual std::string name() const
    {
        return "Device";
    }
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
    virtual std::string getStatus() const = 0;
    virtual bool isCritical() const
    {
        return false;
    }
};
#endif // DEVICE_HPP
