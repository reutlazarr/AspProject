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
    this->isInitialized = false;
    setCommands();
}

// set map of commands
void App::setCommands() {
    commands[1] = std::make_unique<AddUrl>();
    commands[2] = std::make_unique<IsBlackList>();
}

// running the app
void App::run() {
    const int server_port = 5555;
    startServer(server_port);
}

// start running the server
void App::startServer(int server_port) {
    int sock = setupServerSocket(server_port);
    if (sock < 0) {
        return;
    }
    struct sockaddr_in sin;
    socklen_t addr_len = sizeof(sin);
    memset(&sin, 0, sizeof(sin));

    // bool isInitialized = false;
    // // Main server loop
    // while (!isInitialized) {
    //     int client_sock = accept(sock, (struct sockaddr *)&sin, &addr_len);
    //     if (client_sock < 0) {
    //         perror("error accepting client");
    //         continue;
    //     }
    //     std::cout << "Connection accepted from client: " << client_sock << std::endl;
    //     isInitialized = initializeBloomFilter(client_sock);
    //     close(client_sock);  // Close initial connection, needed????
    // }
    // Now proceed to handle other clients
    // handleClientConnections(sock, sin, addr_len);

    int opt = 1;
    while (true) {
        int client_sock = accept(sock, (struct sockaddr *)&sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            continue;
        }
        std::thread clientThread(&App::handleClient, this, client_sock);
        clientThread.detach(); // Detach the thread to allow it to run independently
    }
    // close(sock); // Close the server socket when done
}

int App::setupServerSocket(int server_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return -1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    std::cout << "setting up socket." << std::endl;
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        close(sock);
        return -1;
    }
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        close(sock);
        return -1;
    }
    std::cout << "Server is running on port " << server_port << std::endl;
    return sock;
}

// initialize the bloomFilter
bool App::initializeBloomFilter(int client_sock) {
    std::stringstream input = menu.nextCommand(client_sock);
    std::cout << "input: " << input.str() << std::endl;
    if (input.str().empty()) {
        std::cerr << "Error reading from socket or connection closed\n";
        return false;
    }
    try {
        bloomFilter = std::make_shared<BloomFilter>(bloomFilterManager.createBloomFilter(input));
        std::string successMsg = "Bloom Filter initialized successfully\n";
        send(client_sock, successMsg.c_str(), successMsg.size(), 0);
        // send(client_sock, "true", 4, 0);
        std::cout << successMsg << std::endl;
        return true;
    } catch (const std::exception &e) {
        std::string errorMsg = "Initialization failed: " + std::string(e.what()) + "\n";
        send(client_sock, errorMsg.c_str(), errorMsg.length(), 0);
        std::cout << errorMsg << std::endl;
        return false;
    }
}

void App::handleClient(int clientSock) {
    // for initialize the bloomFilter
    while (!this->isInitialized) {
        std::cout << "Connection accepted from client: " << clientSock << std::endl;
        std::cout << "waiting to initialize bloom filter" << std::endl;
        this->isInitialized = initializeBloomFilter(clientSock);
    }
    // for handle the communication with bloomFilter
    while (true) {
        std::cout << "Connection accepted from client: " << clientSock << std::endl;
        std::cout << "Waiting for a command" << std::endl;

        std::stringstream input = menu.nextCommand(clientSock);
        if (input.str().empty()) {
            std::cout << clientSock << std::endl;
            std::cerr << "Error reading from socket or connection closed\n";
            break;  // Exit loop if the connection is closed or error occurs
        }
        std::cout << "input: " << input.str() << std::endl;
        

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
            std::cout << clientSock << std::endl;
            std::cout << isMalicious << std::endl;
            send(clientSock, isMalicious.c_str(), isMalicious.length(), 0);
        }
    }
    close(clientSock);
}

// // manager the clients connections
// void App::handleClientConnections(int sock, struct sockaddr_in& sin, socklen_t addr_len) {
//     while (true) {
//         int client_sock = accept(sock, (struct sockaddr *)&sin, &addr_len);
//         if (client_sock < 0) {
//             perror("error accepting client");
//             continue;
//         }
//         std::thread clientThread(&App::handleClient, this, client_sock);
//         clientThread.detach();
//     }
// }
