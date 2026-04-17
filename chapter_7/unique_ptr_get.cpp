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
    if(send(sockfd, p_buffer.get(), std::strlen(p_buffer.get()), 0) < 0)
    {
        std::cerr << "Failed to send data\n";
        close(sockfd);
        return 1;
    }

    // Cleanup
    close(sockfd); // close socket explicitly
    // p_buffer automatically freed here

    return 0;
}