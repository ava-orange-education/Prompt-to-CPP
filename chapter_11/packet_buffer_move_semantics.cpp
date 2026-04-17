// packet_buffer_move_modern.cpp
// -----------------------------------------------------------------------------
// Demonstrates move constructor and move assignment operator
// using std::unique_ptr for automatic, exception-safe memory management.
//
// This version is safe, modern, and minimal — ideal for illustrating
// ownership transfer (move semantics) in real-world C++17/20 code.
// -----------------------------------------------------------------------------

#include <cstring> // for std::memcpy
#include <iostream>
#include <memory>  // for std::unique_ptr
#include <utility> // for std::move

class PacketBuffer
{
  public:
    // -------------------------------------------------------------------------
    // Constructor
    // -------------------------------------------------------------------------
    // Allocates a heap buffer of 'n' bytes using std::make_unique.
    // Ownership of this memory is managed automatically by std::unique_ptr.
    explicit PacketBuffer(std::size_t n) : m_size(n), m_data(std::make_unique<char[]>(n))
    {
        std::cout << "Allocated buffer of size " << m_size << "\n";
    }

    // -------------------------------------------------------------------------
    // Copy constructor (deep copy)
    // -------------------------------------------------------------------------
    // Creates a completely new buffer and copies data from 'other'.
    PacketBuffer(const PacketBuffer &other) : m_size(other.m_size), m_data(std::make_unique<char[]>(other.m_size))
    {
        std::memcpy(m_data.get(), other.m_data.get(), m_size);
        std::cout << "Copied buffer of size " << m_size << "\n";
    }

    // -------------------------------------------------------------------------
    // Copy assignment operator (deep copy)
    // -------------------------------------------------------------------------
    // Releases any existing buffer, allocates new memory, and copies data.
    PacketBuffer &operator=(const PacketBuffer &other)
    {
        if (this != &other)
        {
            m_size = other.m_size;
            m_data = std::make_unique<char[]>(m_size);
            std::memcpy(m_data.get(), other.m_data.get(), m_size);
            std::cout << "Copy-assigned buffer of size " << m_size << "\n";
        }
        return *this;
    }

    // -------------------------------------------------------------------------
    // Move constructor
    // -------------------------------------------------------------------------
    // Transfers ownership of the heap buffer from 'other' to 'this'.
    // No allocation or data copy occurs. The source object is left empty
    // but in a valid, destructible state (m_data == nullptr, m_size == 0).
    PacketBuffer(PacketBuffer &&other) noexcept : m_size(other.m_size), m_data(std::move(other.m_data))
    {
        other.m_size = 0;
        std::cout << "Moved buffer (constructor)\n";
    }

    // -------------------------------------------------------------------------
    // Move assignment operator
    // -------------------------------------------------------------------------
    // Frees any existing resource owned by 'this', then transfers ownership
    // of 'other.m_data' to 'this'. No new memory is allocated or copied.
    PacketBuffer &operator=(PacketBuffer &&other) noexcept
    {
        if (this != &other)
        {
            m_data = std::move(other.m_data);
            m_size = other.m_size;
            other.m_size = 0;
            std::cout << "Move-assigned buffer\n";
        }
        return *this;
    }

    // -------------------------------------------------------------------------
    // Accessor
    // -------------------------------------------------------------------------
    // Returns the number of bytes currently held by the buffer.
    std::size_t size() const noexcept
    {
        return m_size;
    }

  private:
    std::size_t m_size{};           // Size of allocated buffer in bytes
    std::unique_ptr<char[]> m_data; // Smart pointer managing heap memory
};

// -----------------------------------------------------------------------------
// Demonstration of move semantics
// -----------------------------------------------------------------------------
int main()
{
    std::cout << "=== Construct buffer1 ===\n";
    PacketBuffer buffer1(1024); // Constructor (allocates 1024 bytes)

    std::cout << "\n=== Copy construct buffer2 from buffer1 ===\n";
    PacketBuffer buffer2 = buffer1; // Copy constructor (deep copy)

    std::cout << "\n=== Move construct buffer3 from buffer1 ===\n";
    PacketBuffer buffer3 = std::move(buffer1); // Move constructor (ownership transfer)

    std::cout << "\n=== Copy assign buffer4 from buffer2 ===\n";
    PacketBuffer buffer4(512); // Temporary buffer (512 bytes)
    buffer4 = buffer2;         // Copy assignment (deep copy, new allocation)

    std::cout << "\n=== Move assign buffer4 from buffer3 ===\n";
    buffer4 = std::move(buffer3); // Move assignment (no allocation)

    std::cout << "\n=== Buffer states ===\n";
    std::cout << "buffer1 size: " << buffer1.size() << " (moved-from)\n";
    std::cout << "buffer2 size: " << buffer2.size() << "\n";
    std::cout << "buffer3 size: " << buffer3.size() << " (moved-from)\n";
    std::cout << "buffer4 size: " << buffer4.size() << "\n";
}
