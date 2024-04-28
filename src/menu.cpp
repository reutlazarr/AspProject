// menu.cpp

#include "Menu.h"
#include "CheckInput.h"
#include <sstream>
#include <iostream>
#include <limits>
#include <cstring>  // For memset
#include <unistd.h> // For read
#include <sys/socket.h>

// return the next command fron the user
std::stringstream Menu::nextCommand(int clientSock) {
    char buffer[1024];
    int bytes_read = recv(clientSock, buffer, sizeof(buffer), 0);
    if (bytes_read <= 0) {
        // Handle errors or disconnections
        return std::stringstream();  // Return an empty stringstream on error
    }
    return std::stringstream(std::string(buffer, bytes_read));
}

std::pair<int, std::string> Menu::executeCommand(std::stringstream& input) {
    CheckInput checkInput;
    std::stringstream inputCopy(input.str()); // copy std::stringstream
    int command;
    std::string url;
    // Check for invalid input
    if (checkInput.checkExecuteCommand(inputCopy)) {
        // std::cout << "her: " << inputCopy.str() << std::endl;
        command = -1; // Indicator for invalid command
        url = ""; // Empty URL for invalid input
    } else {
        input >> command >> url;
    }
    return std::make_pair(command, url); // return pair of command int and url string
}

// get messageEror to print
void Menu::displayError(const std::string &message) const {
    std::cerr << message << std::endl;
}
