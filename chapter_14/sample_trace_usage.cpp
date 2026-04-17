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
// sample_trace_usage.cpp
// Example usage of the debug tracing utility
#define ENABLE_DEBUG_TRACE // Define this before including debug.h
#include "debug.h"
#include <string>
#include <vector>

void process_transaction(int id)
{
    TRACE_SCOPE; // Automatically logs entry and exit

    if (id < 0)
    {
        TRACE("Invalid ID detected: " << id);
        return; // Destructor for TraceScope is still called here
    }

    TRACE("Processing transaction: " << id);
}

int main()
{
    TRACE_SCOPE;

    std::vector<int> transactions = { 101, -5, 102 };

    for (int tx_id : transactions)
    {
        process_transaction(tx_id);
    }

    return 0;
}