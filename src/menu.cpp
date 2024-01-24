// menu.cpp

#include "../headers/Menu.h"
#include <sstream>
#include <iostream>
#include <limits>


// return int for the commannd, and string for the url
std::pair<int, std::string> Menu::nextCommand() {
    // Get user input
    std::cout << "Enter command (1 or 2) and URL: ";
    std::string line;
    std::getline(std::cin, line);
    std::stringstream input(line);

    int command;
    std::string url;
    input >> command >> url;
    // invalid input throw std::invalid_argument
    if (input.fail() || input.peek() != EOF) {
        input.clear();
        input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Invalid input. Please enter a valid command (1 or 2) and URL.");
    }
    return std::make_pair(command, url); // return pair of command int and url string
}

// print messageEror to print
void Menu::displayError(const std::string& message) const {
    std::cerr << "Error: " << message << std::endl;
}

