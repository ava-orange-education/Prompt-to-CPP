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