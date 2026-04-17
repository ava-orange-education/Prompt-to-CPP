/*
 * Copyright (C) 2026
 * Author: Vivek Bhadra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
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
