/**
 * @file    loop_tracer.cpp
 * @author  Vivek Bhadra
 *
 * @brief
 * Demonstrates a simple while loop that traces and prints loop iterations.
 *
 * @license
 * This file is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

// loop_tracer.cpp
// This program prints numbers from 0 to 2 using a while loop
#include <iostream>

int main()
{
    int x = 0;
    while (x < 3)
    {
        std::cout << x;
        ++x;
    }
    return 0;
}