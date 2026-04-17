// dynamic_class_allocation.cpp
// Demonstrates allocation and deallocation of a class object

#include <iostream>

class Box
{
  public:
    Box(int length, int width, int height) : m_length{length}, m_width{width}, m_height{height}
    {
        std::cout << "Box constructed: " << m_length << "x" << m_width << "x" << m_height << '\n';
    }

    ~Box()
    {
        std::cout << "Box destroyed\n";
    }

    int volume() const
    {
        return m_length * m_width * m_height;
    }

  private:
    int m_length;
    int m_width;
    int m_height;
};

int main()
{
    // Allocate a Box object dynamically
    Box *pBox = new Box(3, 4, 5); // dynamically allocated Box object,
                                  // parameters are length, width, height to the constructor
                                  // pBox points to the allocated Box object
    // Use the Box object
    // pBox is a pointer to the Box object
        std::cout << "Box volume: " << pBox->volume() << '\n';

    // Deallocate the object
    delete pBox;

    return 0;
}
