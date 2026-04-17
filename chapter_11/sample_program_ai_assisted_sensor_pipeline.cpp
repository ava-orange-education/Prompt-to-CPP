#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

// A simple move-only container for aggregated sensor data ready for transmission.
class DataPacket
{
  public:
    DataPacket() = default;

    DataPacket(std::vector<float> readings, std::uint64_t timestamp, std::string sensorId)
        : readings_(std::move(readings)), timestamp_(timestamp), sensorId_(std::move(sensorId))
    {
    }

    // Move operations - allow moving the packet cheaply.
    DataPacket(DataPacket &&) noexcept = default;
    DataPacket &operator=(DataPacket &&) noexcept = default;

    // Disable copying to emphasize move semantics and avoid accidental expensive copies.
    DataPacket(const DataPacket &) = delete;
    DataPacket &operator=(const DataPacket &) = delete;

    const std::vector<float> &readings() const noexcept
    {
        return readings_;
    }
    std::uint64_t timestamp() const noexcept
    {
        return timestamp_;
    }
    const std::string &sensorId() const noexcept
    {
        return sensorId_;
    }

    // Simple serialization to a string (for demonstration / transmission simulation).
    std::string serialize() const
    {
        std::ostringstream oss;
        oss << "SensorID=" << sensorId_ << ";Timestamp=" << timestamp_ << ";Count=" << readings_.size() << ";Values=";
        oss << std::fixed << std::setprecision(3);
        for (size_t i = 0; i < readings_.size(); ++i)
        {
            if (i)
                oss << ',';
            oss << readings_[i];
        }
        return oss.str();
    }

    void print_summary(std::ostream &os = std::cout) const
    {
        os << "DataPacket(sensorId=" << sensorId_ << ", timestamp=" << timestamp_ << ", count=" << readings_.size()
           << ")\n";
    }

  private:
    std::vector<float> readings_;
    std::uint64_t timestamp_ = 0;
    std::string sensorId_;
};

// Calibration parameters.
struct CalibrationParams
{
    float scale = 1.0f;
    float offset = 0.0f;
};

// Range for valid sensor values.
struct ValidRange
{
    float min = -std::numeric_limits<float>::infinity();
    float max = std::numeric_limits<float>::infinity();
};

// Apply calibration to raw sensor readings. Returns a new vector with calibrated values.
std::vector<float> calibrate_readings(const std::vector<float> &raw, const CalibrationParams &p)
{
    std::vector<float> out;
    out.reserve(raw.size());
    for (float v : raw)
    {
        // Keep NaN and infinities as-is for downstream filtering to detect.
        if (!std::isfinite(v))
        {
            out.push_back(v);
        }
        else
        {
            out.push_back(v * p.scale + p.offset);
        }
    }
    return out;
}

// Predicate that returns true if the value is valid (finite and within range).
bool is_valid_value(float v, const ValidRange &r)
{
    if (!std::isfinite(v))
        return false;
    if (v < r.min)
        return false;
    if (v > r.max)
        return false;
    return true;
}

// Filter invalid values out of the calibrated vector. Returns a vector with only valid values.
std::vector<float> filter_invalid(const std::vector<float> &calibrated, const ValidRange &r)
{
    std::vector<float> out;
    out.reserve(calibrated.size());
    for (float v : calibrated)
    {
        if (is_valid_value(v, r))
            out.push_back(v);
    }
    return out;
}

// Aggregate into a move-enabled DataPacket (moves vector into the packet to avoid copies).
DataPacket aggregate_to_packet(std::vector<float> validReadings, const std::string &sensorId)
{
    // Capture current time as milliseconds since epoch.
    auto now = std::chrono::system_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    return DataPacket(std::move(validReadings), static_cast<std::uint64_t>(ms), sensorId);
}

// High-level processing pipeline: calibrate -> filter -> aggregate
DataPacket process_pipeline(const std::vector<float> &rawReadings, const CalibrationParams &cal,
                            const ValidRange &range, const std::string &sensorId)
{
    auto calibrated = calibrate_readings(rawReadings, cal);
    auto valid = filter_invalid(calibrated, range);
    return aggregate_to_packet(std::move(valid), sensorId);
}

int main()
{
    // Example raw sensor readings (contains some invalid values)
    std::vector<float> raw = { 0.12f,    0.15f, std::numeric_limits<float>::quiet_NaN(), 0.20f,
                               -9999.0f, 0.18f, std::numeric_limits<float>::infinity(),  0.22f };

    CalibrationParams cal{ .scale = 2.0f, .offset = -0.05f };
    ValidRange range{ .min = 0.0f, .max = 1.0f };

    // Run the pipeline to produce a move-only DataPacket.
    DataPacket packet = process_pipeline(raw, cal, range, "sensor-42");

    // Print summary and serialized payload.
    packet.print_summary();
    std::cout << "Serialized payload:\n" << packet.serialize() << "\n";

    // Demonstrate move semantics: transfer ownership to a transmitter.
    DataPacket transmitterPacket = std::move(packet);
    std::cout << "After move, transmitter has: ";
    transmitterPacket.print_summary();

    // packet cannot be used to access readings (copy was deleted) but we can show that attempting
    // to use it for printing summary would still be valid for timestamp/sensorId if we had left them.
    // In this example, we moved internals so the original packet is in a valid but unspecified state.

    // Simulate sending the serialized payload.
    std::string payload = transmitterPacket.serialize();
    std::cout << "Transmitting (" << payload.size() << " bytes)\n";

    return 0;
}