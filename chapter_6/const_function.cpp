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
