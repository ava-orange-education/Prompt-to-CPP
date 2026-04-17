#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>

bool writeHeader(char *dst, std::size_t capacity)
{
    // Intentionally long header (includes terminating null)
    const char header[] = "MSGv1.0\n";
    const std::size_t needed = sizeof(header); // 9 bytes

    // BUG: copies before confirming capacity is sufficient.
    // If 'capacity < needed', this write already overflows -> undefined behaviour.
    std::memcpy(dst, header, needed);

    // Attempt to "report" the problem after the fact.
    if (capacity < needed)
    {
        return false; // Too late: UB may already have corrupted state.
    }
    return true;
}

int main()
{
    // Small buffer next to a "guard" to reveal possible memory corruption.
    std::array<char, 8> smallBuffer{}; // Only 8 bytes available
    std::uint64_t guard = 0x1122334455667788ULL;

    bool ok = writeHeader(smallBuffer.data(), smallBuffer.size());

    std::cout << "Status (expected false): " << ok << "\n";
    std::cout << "Buffer (may be truncated/garbled): " << smallBuffer.data() << "\n";
    std::cout << "Guard value (may be corrupted): " << std::hex << guard << "\n";
}
