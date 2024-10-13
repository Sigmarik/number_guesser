#include "server.h"

#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#include <future>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "config.h"
#include "logger/debug.h"
#include "logger/logger.h"

int set_noblock(int sock) {
    return fcntl(sock, F_SETFL, fcntl(sock, F_GETFL, 0) | O_NONBLOCK);
}

template <class T>
const T& receive_command(const std::unordered_map<std::string, T>& options,
                         const std::string& prefix, const std::string& help) {
    while (1) {
        std::string input;
        std::cout << prefix;
        std::cin >> input;

        if (input == "help") {
            std::cout << help << std::endl;
            continue;
        }

        auto found = options.find(input);
        if (found == options.end()) {
            std::cout
                << "Invalid command, type \"help\" to see the list of options."
                << std::endl;
            continue;
        }

        return found->second;
    }
}

int as_server() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;

    unsigned port = 8080;

    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    bind(sock, (sockaddr*)&server_address, sizeof(server_address));

    int status = set_noblock(sock);

    listen(sock, 1024);

    std::cout << "Server started. Port: " << port << std::endl;

    receive_command((std::unordered_map<std::string, int>){{"start", 1}},
                    INPUT_PREFIX,
                    "help - see this list,\nstart - start the competition");

    std::unordered_map<std::string, int> clients;
    unsigned client_id = 1;
    for (;;) {
        int client_sock = accept(sock, nullptr, nullptr);
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            break;
        }
        clients[std::to_string(client_id)] = client_sock;
        client_id++;
    }

    std::cout << "Found " << clients.size() << " clients" << std::endl;

    close(sock);
    return EXIT_SUCCESS;
}