#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <optional>
#include <ranges>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

// Move-only DataPacket that stores sensor readings, a timestamp, and a sensor ID.
class DataPacket
{
  public:
    using time_point = std::chrono::system_clock::time_point;

    DataPacket() = default;

    DataPacket(std::vector<float> readings, time_point timestamp, std::string sensorId)
        : readings_(std::move(readings)), timestamp_(timestamp), sensorId_(std::move(sensorId))
    {
    }

    // Move operations (noexcept)
    DataPacket(DataPacket &&) noexcept = default;
    DataPacket &operator=(DataPacket &&) noexcept = default;

    // Delete copy operations to enforce move-only semantics
    DataPacket(const DataPacket &) = delete;
    DataPacket &operator=(const DataPacket &) = delete;

    // Check whether the packet contains any readings
    [[nodiscard]] bool empty() const noexcept
    {
        return readings_.empty();
    }

    // Accessors
    [[nodiscard]] const std::vector<float> &readings() const noexcept
    {
        return readings_;
    }
    [[nodiscard]] time_point timestamp() const noexcept
    {
        return timestamp_;
    }
    [[nodiscard]] const std::string &sensorId() const noexcept
    {
        return sensorId_;
    }

    // Serialize to a single-line string: "<sensorId> | <ISO8601 UTC> | <v1> <v2> ..."
    // Works when the packet is empty or has been moved-from.
    [[nodiscard]] std::string serialize() const
    {
        std::ostringstream oss;

        // Sensor ID (empty allowed)
        oss << sensorId_ << " | ";

        // Timestamp: print ISO8601 UTC or "-" if timestamp is not set (time_point{})
        if (timestamp_ == time_point{})
        {
            oss << "-";
        }
        else
        {
            std::time_t t = std::chrono::system_clock::to_time_t(timestamp_);
            std::tm *gmt = std::gmtime(&t);
            if (gmt)
            {
                oss << std::put_time(gmt, "%Y-%m-%dT%H:%M:%SZ");
            }
            else
            {
                oss << "-";
            }
        }

        oss << " | ";

        // Readings: space-separated, or "-" when empty
        if (readings_.empty())
        {
            oss << "-";
        }
        else
        {
            oss << std::fixed << std::setprecision(1);
            for (size_t i = 0; i < readings_.size(); ++i)
            {
                if (i)
                    oss << ' ';
                oss << readings_[i];
            }
        }

        return oss.str();
    }

    // Print the same summary line to std::cout
    void print_summary() const
    {
        std::cout << serialize() << '\n';
    }

  private:
    std::vector<float> readings_;
    time_point timestamp_{};
    std::string sensorId_;
};

// Calibration parameters for simple linear calibration: scale * value + offset
struct CalibrationParams
{
    float scale = 1.0f;
    float offset = 0.0f;
};

// Functor that applies calibration to a reading. Preserves NaN/infinite values.
struct Calibrator
{
    CalibrationParams params;
    explicit Calibrator(CalibrationParams p) noexcept : params(p)
    {
    }

    float operator()(float value) const noexcept
    {
        if (!std::isfinite(value))
            return value; // preserve NaN/inf
        return value * params.scale + params.offset;
    }
};

// Range specifying inclusive valid bounds for readings
struct ValidRange
{
    float min;
    float max;
};

// Filter readings: return only finite values within [min, max].
// Implemented by copying the input and using std::remove_if with a lambda.
[[nodiscard]] std::vector<float> filter_readings(const std::vector<float> &in, ValidRange r)
{
    std::vector<float> out = in;
    auto newEnd = std::ranges::remove_if(out, [r](float v) { return !std::isfinite(v) || v < r.min || v > r.max; });
    out.erase(newEnd.begin(), out.end()); // Works with GCC 11.4.0
    return out;
}

[[nodiscard]] std::optional<DataPacket> process_pipeline(const std::vector<float> &raw, CalibrationParams cp,
                                                         ValidRange vr, std::string sensorId)
{
    // 1) Calibrate
    std::vector<float> calibrated;
    calibrated.reserve(raw.size());
    Calibrator calibrator{ cp };
    std::transform(raw.begin(), raw.end(), std::back_inserter(calibrated), calibrator);

    // 2) Filter
    auto filtered = filter_readings(calibrated, vr);

    // 3) If empty, return nullopt
    if (filtered.empty())
        return std::nullopt;

    // 4) Move into DataPacket and return
    auto now = std::chrono::system_clock::now();
    return std::make_optional<DataPacket>(std::move(filtered), now, std::move(sensorId));
}

void transmit(DataPacket &&packet)
{
    std::cout << "Transmitting packet: ";
    packet.print_summary();
    // simulate payload send
    std::string payload = packet.serialize();
    std::cout << "Payload size: " << payload.size() << " bytes\n";
}

int main()
{
    using std::chrono::system_clock;

    // Simulated raw data for two sensors
    std::vector<float> raw1 = { 23.1f, 24.0f, std::numeric_limits<float>::quiet_NaN(), 22.9f };
    std::vector<float> raw2 = { -1000.0f, 19.5f, 20.0f, std::numeric_limits<float>::infinity() };

    CalibrationParams cp{ 1.0f, 0.0f };
    ValidRange vr{ 20.0f, 25.0f };

    if (auto opt = process_pipeline(raw1, cp, vr, std::string("S1")))
    {
        DataPacket &packet = *opt; // reference to avoid extra copies
        std::cout << "Before move (S1): ";
        packet.print_summary();
        transmit(std::move(packet));
        std::cout << "After move (S1): ";
        packet.print_summary();
    }
    else
    {
        std::cout << "S1 produced no valid readings\n";
    }

    if (auto opt = process_pipeline(raw2, cp, vr, std::string("S2")))
    {
        DataPacket &packet = *opt;
        std::cout << "Before move (S2): ";
        packet.print_summary();
        transmit(std::move(packet));
        std::cout << "After move (S2): ";
        packet.print_summary();
    }
    else
    {
        std::cout << "S2 produced no valid readings\n";
    }

    return 0;
}
