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

// running the app
void App::run() {
    const int server_port = 5555;
    startServer(server_port);
}

// start running the server
void App::startServer(int server_port) {
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

// initialize the bloomFilter
bool App::initializeBloomFilter(int client_sock) {
    std::stringstream input = menu.nextCommand(client_sock);
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
        send(clientSock, "true", 4, 0);
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
            break; // Exit loop if the connection is closed or error occurs
        }
        int command = 0;
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
        std::lock_guard<std::mutex> lock(mtx);
        std::string isMalicious = commands[command]->execute(*bloomFilter, url);
        std::cout << isMalicious << std::endl;
        int bytes_sent = send(clientSock, isMalicious.c_str(), isMalicious.length(), 0);
    }
    close(clientSock);
}
