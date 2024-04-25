// menu.cpp

#include "Menu.h"
#include "CheckInput.h"
#include <sstream>
#include <iostream>
#include <limits>

#include <iostream>
#include <cstring>  // For memset
#include <unistd.h> // For read
#include <sys/socket.h>

std::string readLineFromSocket(int sockfd)
{
    std::string line;
    char ch;
    int bytesRead;
    while (true)
    {
        // std::cout << "I get here" << std::endl;
        bytesRead = recv(sockfd, &ch, 1, 0); // Read one byte at a time
        // std::cout << "and here too" << std::endl;
        if (bytesRead <= 0)
        { // Check for end of stream or error
            if (bytesRead == 0)
            {
                std::cout << "Connection closed by the peer." << std::endl;
            }
            else
            {
                std::cout << "recv failed" << std::endl;
                perror("recv failed");
            }
            return line; // Return what has been read so far (could be empty)
        }

        // Check if the last character is a newline
        if (ch == '\n')
        {
            break;
        }
        // Append the character to the line
        line += ch;
    }
    std::cout << "Read a new line: " << line << std::endl;
    return line;
}

// return the next command fron the user
std::stringstream Menu::nextCommand(int clientSock)
{
    return std::stringstream(readLineFromSocket(clientSock));
}

// get messageEror to print
void Menu::displayError(const std::string &message) const
{
    std::cerr << message << std::endl;
}
