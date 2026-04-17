/**
 * @file    volatile_demo.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates the use of the volatile qualifier to prevent certain compiler
 * optimisations on a shared variable.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// volatile_demo.cpp
#include <chrono>
#include <iostream>
#include <thread>
volatile bool running = true; // Assume another thread sets running = false
int main()
{
    std::cout << "System running: " << running << "\n";
    while (running)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 1 second
    }
    std::cout << "System stopped: " << running << std::endl;
    return 0;
}
