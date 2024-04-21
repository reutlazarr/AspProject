// app.cpp

#include "App.h"
#include "Menu.h"
#include "BloomFilterManager.h"
#include "BloomFilter.h"
#include "AddUrl.h"
#include "IsBlackList.h"
#include "ICommand.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstring> 

// constructor
App::App() : menu(Menu()) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions[1] = std::make_unique<HashFunction1>();
    hashFunctions[2] = std::make_unique<HashFunction2>();
    bloomFilterManager = BloomFilterManager(menu, std::move(hashFunctions));
    setCommands();
    //bloomFilter = bloomFilterManager.createBloomFilter();
    bloomFilter = std::make_shared<BloomFilter>(bloomFilterManager.createBloomFilter());
}

// set map of commands
void App::setCommands() {
    commands[1] = std::make_unique<AddUrl>();
    commands[2] = std::make_unique<IsBlackList>();
}

void App::run() {
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return;  // Corrected: no value returned
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        //close(sock);
        return;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        //close(sock);
        return;
    }

    std::cout << "Server is running on port " << server_port << std::endl;

    while (true) {
        struct sockaddr_in client_sin;
        socklen_t addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }

        std::thread clientThread(&App::handleClient, this, client_sock);
        clientThread.detach(); // Detach the thread to handle the client independently
    }
    // Close the server socket when done
    //close(sock);   
}

void App::handleClient(int clientSock) {
    //char buffer[1024];
    while (true) {
        // memset(buffer, 0, sizeof(buffer));
        // ssize_t bytesRead = read(clientSock, buffer, sizeof(buffer) - 1);
        // if (bytesRead <= 0) {
        //     std::cerr << "Error reading from socket or connection closed\n";
        //     break;
        // }

        // std::string input(buffer);
        // std::stringstream received(input);

        std::stringstream input = menu.nextCommand(clientSock);
        auto task = menu.executeCommand(input); // should get pair of command and url

        // Check for invalid command
        if (task.first == -1) {
            // Silently handle invalid input and continue the loop
            std::string error_msg = "Invalid or empty input\n";
            std::cout << clientSock << std::endl;
            std::cout << error_msg << std::endl;
            send(clientSock, error_msg.c_str(), error_msg.length(), 0);
            //continue;
        } else if (task.first != -1 && commands.find(task.first) != commands.end()) {
            std::lock_guard<std::mutex> lock(mtx);
            std::string isMalicious = commands[task.first]->execute(*bloomFilter, task.second);
            std::cout << isMalicious << std::endl;
            std::cout << clientSock << std::endl;
            send(clientSock, isMalicious.c_str(), isMalicious.length(), 0);
        }
    }
    close(clientSock);
}
