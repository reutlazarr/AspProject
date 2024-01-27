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

std::pair<int, std::string> Menu::executeCommand(std::stringstream& input) {
    CheckInput checkInput;
    std::stringstream inputCopy(input.str()); // copy std::stringstream
    int command;
    std::string url;

    // Check for invalid input
    if (checkInput.checkExecuteCommand(inputCopy)) {
        command = -1; // Indicator for invalid command
        url = ""; // Empty URL for invalid input
    } else {
        input >> command >> url;
    }

    return std::make_pair(command, url); // return pair of command int and url string
}

// get messageEror to print
void Menu::displayError(const std::string& message) const {
    std::cerr << message << std::endl;
}

