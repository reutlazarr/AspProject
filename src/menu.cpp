// menu.cpp

#include "../headers/Menu.h"
#include "../headers/CheckInput.h"
#include <sstream>
#include <iostream>
#include <limits>

// return the next command fron the user
std::stringstream Menu::nextCommand() {
    // Get user input
    //std::cout << "Enter command (1 or 2) and URL: " << std::endl;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream input(line);
    return input;
}

// get std::stringstream
// return int for the commannd, and string for the url
std::pair<int, std::string> Menu::executeCommand(std::stringstream& input) {
    CheckInput checkInput;
    std::stringstream inputCopy(input.str()); // copy std::stringstream
    // invalid input throw std::invalid_argument
    if (checkInput.checkExecuteCommand(inputCopy)) {
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input.");   
    }
    int command;
    std::string url;
    input >> command >> url;
    return std::make_pair(command, url); // return pair of command int and url string
}

// get messageEror to print
void Menu::displayError(const std::string& message) const {
    //std::cerr << message << std::endl;
}

