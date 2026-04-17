// sample_reallife_crash.cpp
// Typical real-world crash: out-of-bounds write in a parsing routine
// This code is intended to be used for testing static analysis tools.

#include <cstdio>
#include <cstring>

const int MAX_TOKENS = 8;

struct Packet
{
    char tokens[MAX_TOKENS][32];
    int count;
};

bool parse_line(const char *line, Packet &out)
{
    out.count = 0;
    char temp[32];

    while (sscanf(line, "%31s", temp) == 1) // Read a token 31 chars max
    {
        // BUG: no bounds check against MAX_TOKENS
        strcpy(out.tokens[out.count], temp); // temp is 32 bytes, tokens[][32] is 32 bytes
        ++out.count;                         // Potential out-of-bounds write here

        printf("%s\n", temp);
        // advance past the token we just read
        line += strlen(temp);
        printf(" -- remaining line: '%s'\n", line); // Debug print to trace execution
        while (*line == ' ' || *line == '\t')
            ++line;
    }
    return true;
}

void process_packet(const Packet &p)
{
    printf("Received %d fields\n", p.count);
    for (int i = 0; i < p.count; ++i)
        printf("  [%d] %s\n", i, p.tokens[i]);
}

void handle_input(const char *input)
{
    Packet pkt{};
    if (parse_line(input, pkt))
        process_packet(pkt);
}

int main()
{
    printf("Starting data processor...\n");

    const char *bad_line = "id=57 src=10.0.0.4 dst=10.0.0.19 proto=TCP sport=44321 "
                           "dport=80 len=1380 flags=SYN extra=garbage";

    handle_input(bad_line);
    printf("Processing complete\n");
    return 0;
}
