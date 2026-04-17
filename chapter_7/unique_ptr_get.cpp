// unique_ptr_get.cpp
// Demonstrates unique_ptr::get() with send() needing a raw buffer
// Note: This example assumes a POSIX-like environment for socket operations
// and may not compile on non-POSIX systems.
#include <cstring>
#include <iostream>
#include <memory>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    // Prepare server address
    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // 127.0.0.1

    // Connect to server
    if (connect(sockfd, reinterpret_cast<sockaddr *>(&server_addr), sizeof(server_addr)) < 0)
    {
        std::cerr << "Connection failed\n";
        close(sockfd);
        return 1;
    }

    // Allocate buffer on heap managed by unique_ptr
    std::unique_ptr<char[]> p_buffer{new char[1024]};
    // Fill buffer with data
    // For demonstration, we'll just copy a string into it
    std::strcpy(p_buffer.get(), "Hello from client");

    // Legacy C send() requires a raw pointer
    // Use unique_ptr::get() to obtain the raw pointer
    send(sockfd, p_buffer.get(), std::strlen(p_buffer.get()), 0);

    // Cleanup
    close(sockfd); // close socket explicitly
    // p_buffer automatically freed here

    return 0;
}