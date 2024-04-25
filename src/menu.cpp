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
        // Append the character to the line
        line += ch;

        // Check if the last character is a newline
        if (ch == '\n')
        {
            break;
        }
    }
    std::cout << "Read a new line: " << line << std::endl;
    return line;
}

// return the next command fron the user
std::stringstream Menu::nextCommand(int clientSock)
{
    return std::stringstream(readLineFromSocket(clientSock));
    // char buffer[1024];
    // int bytes_read = recv(clientSock, buffer, sizeof(buffer), 0);
    // if (bytes_read <= 0)
    // {
    //     // Handle errors or disconnections
    //     return std::stringstream(); // Return an empty stringstream on error
    // }
    // return std::stringstream(std::string(buffer, bytes_read));
}

// std::pair<int, std::string> Menu::executeCommand(std::string input)
// {
//     CheckInput checkInput;
//     std::string input_str = input.str();
//     std::stringstream inputCopy(input_str); // copy std::stringstream
//     // std::cout << input_str << std::endl;
//     int command;
//     std::string url;

//     // Check for invalid input
//     if (checkInput.checkExecuteCommand(inputCopy))
//     {
//         command = -1; // Indicator for invalid command
//         url = "";     // Empty URL for invalid input
//     }
//     else
//     {
//         input >> command >> url;
//     }

//     return std::make_pair(command, url); // return pair of command int and url string
// }

// get messageEror to print
void Menu::displayError(const std::string &message) const
{
    std::cerr << message << std::endl;
}
