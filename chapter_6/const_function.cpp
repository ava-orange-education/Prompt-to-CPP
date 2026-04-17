// customer_app/const_function.cpp
// This file demonstrates the use of const member functions in C++.
// It shows how to define a class with const member functions and how they can be used.
#include <iostream>
#include <string>

class Book
{
  private:
    std::string title;
    int pages;

  public:
    Book(const std::string &bookTitle, int totalPages) : title(bookTitle), pages(totalPages)
    {
    }

    // const member function – safe read-only access
    std::string getTitle() const
    {
        // title = "New Title"; // error: cannot modify member variable in a const function
        return title; // allowed: reading is fine
    }

    // non-const member function – allows modification
    void setPages(int newPageCount)
    {
        pages = newPageCount; // allowed: writing is fine
    }
};

int main()
{
    Book myBook("C++ Basics", 200);

    std::cout << myBook.getTitle() << "\n"; // OK: const function
    
    return 0;
}
