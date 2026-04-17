/**
 * @file    default_initialisation_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the difference between default initialisation of global
 * arrays and uninitialised local arrays in C++.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// default_initialisation_demo.cpp
// Demonstrates default initialisation of global vs local arrays

#include <iostream>

int globalArray[3]; // Default-initialised to zero (static storage)

int main()
{
    int localArray[3]; // Not initialised (automatic storage)

    std::cout << "Global array (default-initialised):\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  globalArray[" << i << "] = " << globalArray[i] << "\n";
    }

    std::cout << "\nLocal array (uninitialised, contains garbage):\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "  localArray[" << i << "] = " << localArray[i] << "\n";
    }

    return 0;
}
