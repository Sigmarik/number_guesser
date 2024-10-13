#include "client.h"

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "config.h"
#include "logger/debug.h"
#include "logger/logger.h"

static in_addr_t get_address() {
    in_addr_t address = 0;

    do {
        std::string server_addr_string;

        std::cout << "Server address: " << std::endl;
        std::cin >> server_addr_string;
        std::cout << "Address:" << server_addr_string.c_str() << "."
                  << std::endl;

        address = inet_addr(server_addr_string.c_str());
        if (address == (in_addr_t)(-1)) {
            address = 0;
            std::cout << "Server address could not be resolved." << std::endl;
        } else if (address == 0) {
            std::cout << "Server address cannot be null." << std::endl;
        }
    } while (address == 0);

    return address;
}

int as_client() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = get_address();

    connect(sock, (sockaddr*)&server_address, sizeof(server_address));

    while (1);

    close(sock);

    return 0;
}