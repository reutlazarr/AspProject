// Menu.h

#ifndef MENU_H
#define MENU_H

#include<string>
#include <sstream>
#include <utility>

// header for Menu
class Menu {
    
public:
    std::stringstream nextCommand(); // return the next command fron the user

    // get std::stringstream
    // return int for the commannd, and string for the url
    std::pair<int, std::string> executeCommand(std::stringstream& input);

    // get messageEror to print
    void displayError(const std::string& message) const;
};

#endif // MENU_H


