// Menu.h

#ifndef MENU_H
#define MENU_H

#include "CheckInput.h"
#include <sstream>
#include <iostream>
#include <limits>
#include <sys/socket.h>

// header for Menu
class Menu {
    
public:
    std::stringstream nextCommand(int clientSock); // return the next command fron the user

    // get std::stringstream
    // return int for the commannd, and string for the url
    std::pair<int, std::string> executeCommand(std::stringstream& input);

    // get messageEror to print
    void displayError(const std::string& message) const;
};

#endif // MENU_H


