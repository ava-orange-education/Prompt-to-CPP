// copy_ops.cpp
// Example X.X: Demonstrating copy constructor and copy assignment operator

#include <cstring>
#include <iostream>

class Book
{
  private:
    char *title;

  public:
    // Constructor
    Book(const char *t)
    {
        title = new char[std::strlen(t) + 1];
        std::strcpy(title, t);
        std::cout << "[ctor] Created book: " << title << "\n";
    }

    // Copy constructor
    Book(const Book &other)
    {
        title = new char[std::strlen(other.title) + 1];
        std::strcpy(title, other.title);
        std::cout << "[copy ctor] Copied book: " << title << "\n";
    }

    // Copy assignment operator
    Book &operator=(const Book &other)
    {
        if (this != &other)
        {
            delete[] title;
            title = new char[std::strlen(other.title) + 1];
            std::strcpy(title, other.title);
            std::cout << "[copy assign] Assigned book: " << title << "\n";
        }
        return *this;
    }

    // Destructor
    ~Book()
    {
        std::cout << "[dtor] Destroying book: " << title << "\n";
        delete[] title;
    }

    void show() const
    {
        std::cout << "Book title: " << title << "\n";
    }
};

int main()
{
    Book b1("C++ Fundamentals");
    Book b2 = b1; // Calls copy constructor
    Book b3("Temporary Title");

    b3 = b1; // Calls copy assignment operator

    return 0;
}
