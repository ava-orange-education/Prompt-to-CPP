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
// wrong_catch_order.cpp
// Purpose: Demonstrate that placing a base-class catch
//          before a derived-class catch hides the specific handler.

#include <iostream>
#include <stdexcept>

int main()
{
    try
    {
        // Throw a derived exception (std::out_of_range)
        throw std::out_of_range("Index out of range");
    }
    catch (const std::exception &e)
    {
        // Base class handler placed first
        std::cout << "General exception: " << e.what() << '\n';
    }
    catch (const std::out_of_range &e)
    {
        // This block is never reached
        std::cout << "Out of range error: " << e.what() << '\n';
    }

    return 0;
}
