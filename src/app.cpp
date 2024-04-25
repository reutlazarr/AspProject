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
App::App() : menu(Menu())
{
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions[1] = std::make_unique<HashFunction1>();
    hashFunctions[2] = std::make_unique<HashFunction2>();
    bloomFilterManager = BloomFilterManager(menu, std::move(hashFunctions));
    this->isInitialized = false;
    setCommands();
}

// set map of commands
void App::setCommands()
{
    commands[1] = std::make_unique<AddUrl>();
    commands[2] = std::make_unique<IsBlackList>();
}

void App::run()
{
    const int server_port = 5555;
    startServer(server_port); // Example port number
}

void App::startServer(int server_port)
{
    int sock = setupServerSocket(server_port);
    if (sock < 0)
        return;

    struct sockaddr_in sin;
    socklen_t addr_len = sizeof(sin);
    memset(&sin, 0, sizeof(sin));
    int clientSocket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    while (true)
    {
        if ((clientSocket = accept(sock, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            continue;
        }

        // std::thread clientThread(handle_client, clientSocket);
        std::thread clientThread(&App::handleClient, this, clientSocket);
        clientThread.detach(); // Detach the thread to allow it to run independently
    }
}

// void App::startServer2(int server_port)
// {
//     int sock = setupServerSocket(server_port);
//     if (sock < 0)
//         return;

//     struct sockaddr_in sin;
//     socklen_t addr_len = sizeof(sin);
//     memset(&sin, 0, sizeof(sin));
//     bool isInitialized = false;
//     // Main server loop
//     int clientSock = 0;
//     while (!isInitialized)
//     {
//         clientSock = accept(sock, (struct sockaddr *)&sin, &addr_len);
//         if (clientSock < 0)
//         {
//             perror("error accepting client");
//             continue;
//         }
//         std::cout << "Connection accepted from client: " << clientSock << std::endl;
//         isInitialized = initializeBloomFilter(clientSock);
//         std::thread clientThread(&App::handleClient, this, clientSock);
//         // close(clientSock); // Close initial connection, needed????
//     }

//     // Now proceed to handle other clients
//     handleClientConnections(sock, sin, addr_len);
//     close(sock); // Close the server socket when done
// }

int App::setupServerSocket(int server_port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
        return -1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    std::cout << "setting up socket." << std::endl;
    if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0)
    {
        perror("error binding socket");
        close(sock);
        return -1;
    }
    if (listen(sock, 5) < 0)
    {
        perror("error listening to a socket");
        close(sock);
        return -1;
    }
    std::cout << "Server is running on port " << server_port << std::endl;
    return sock;
}

bool App::initializeBloomFilter(int clientSock)
{
    std::stringstream input = menu.nextCommand(clientSock);
    std::cout << "input: " << input.str() << std::endl;
    if (input.str().empty())
    {
        std::cerr << "Error reading from socket or connection closed\n";
        return false;
    }
    try
    {
        bloomFilter = std::make_shared<BloomFilter>(bloomFilterManager.createBloomFilter(input));
        std::string successMsg = "Bloom Filter initialized successfully\n";
        send(clientSock, successMsg.c_str(), successMsg.length(), 0);
        std::cout << successMsg << std::endl;
        return true;
    }
    catch (const std::exception &e)
    {
        std::string errorMsg = "Initialization failed: " + std::string(e.what()) + "\n";
        send(clientSock, errorMsg.c_str(), errorMsg.length(), 0);
        std::cout << errorMsg << std::endl;
        return false;
    }
}

// void App::handleClientConnections(int sock, struct sockaddr_in &sin, socklen_t addr_len)
// {
//     // while (true)
//     // {
//     int clientSock = accept(sock, (struct sockaddr *)&sin, &addr_len);
//     std::cout << "connected with a new client" << std::endl;
//     if (clientSock < 0)
//     {
//         perror("error accepting client");
//     }
//     std::thread clientThread(&App::handleClient, this, clientSock);
//     // clientThread.detach();
//     // }
// }

// Function to split a string into two parts based on the first space character
std::pair<std::string, std::string> split_string(const std::string &str)
{
    size_t pos = str.find(' '); // Find the position of the first space
    if (pos == std::string::npos)
    {
        return {str, ""}; // Return the whole string and an empty string if no space found
    }
    return {str.substr(0, pos), str.substr(pos + 1)};
}

void App::handleClient(int clientSock)
{
    while (!this->isInitialized)
    {
        std::cout << "waiting to initialize bloom filter" << std::endl;
        this->isInitialized = initializeBloomFilter(clientSock);
    }
    while (true)
    {
        std::cout << "Waiting for a command" << std::endl;
        std::stringstream input = menu.nextCommand(clientSock);
        std::string input_str = input.str();
        std::cout << "received a new message: " << input_str << std::endl;
        if (input_str.empty())
        {
            std::cout << clientSock << std::endl;
            std::cerr << "Error reading from socket or connection closed\n";
            // result = "{\"error\":\"Invalid command or empty input\"}";
            break; // Exit loop if the connection is closed or error occurs
        }
        int command = 0;
        // auto task = menu.executeCommand(input); // should get pair of command and url
        try
        {
            command = std::stoi(input_str.substr(0, 1));
            if (command != 1 & command != 2)
            {
                throw std::out_of_range("");
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid number entered for command. " << e.what() << std::endl;
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: The number entered for command is out of range. " << e.what() << std::endl;
            continue;
        }
        std::string url = input_str.substr(2);

        // // Check for invalid command
        // if (task.first == -1)
        // {
        //     // Silently handle invalid input and continue the loop
        //     std::cout << clientSock << std::endl;
        //     std::string error_msg = "Invalid or empty input\n";
        //     std::cout << error_msg << std::endl;
        //     send(clientSock, error_msg.c_str(), error_msg.length(), 0);
        //     // continue;
        // }
        // else if (task.first != -1 && commands.find(task.first) != commands.end())

        // {
        std::lock_guard<std::mutex> lock(mtx);
        std::string isMalicious = commands[command]->execute(*bloomFilter, url);
        // std::cout << clientSock << std::endl;
        std::cout << isMalicious << std::endl;
        send(clientSock, isMalicious.c_str(), isMalicious.length(), 0);
        // }
    }
    close(clientSock);
}
