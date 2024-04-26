//checkInput.cpp

#include "CheckInput.h"
#include "IHashFunction.h"

#include <sstream>
#include <stdexcept>
#include <vector>
#include <limits>
#include <iostream>
#include <sstream>


// get the user input
// return true if the input not as format: {int, string}, e.g not 1 "exempal.com"
// return false otherwise
bool CheckInput::checkExecuteCommand(std::stringstream& input) {
    
    std::cout << "ch: " << input.str() << std::endl;
    int command;
    std::string url;
    input >> command >> url;
    // Eat up any trailing whitespace including newlines
    input >> std::ws;
    // invalid input throw std::invalid_argument
    if (input.fail() || input.peek() != EOF) {
        std::cout << "h: " << input.str() << std::endl;
        return true;
    }
    return false;
}

// get the user input of arraySize
// return true if the input is not positive int
// return false otherwise
bool CheckInput::checkArraySize(std::istream& input) {
    int arraySize;
    input >> arraySize;
    if (input.fail() || arraySize <= 0) {
        return true;
    }
    return false;
}
 
// get the user input of hashFunctions
// return true if the input is not int and not in the hashFunctionMap 
// return false otherwise
bool CheckInput::checkHashFunctions(std::istream& input, std::map<int, std::unique_ptr<IHashFunction>>& hashFunctionsMap) {
    int hashFunctionId;
     //bool invalidInput = false;
    while (input >> hashFunctionId) { // read hash function IDs
        auto it = hashFunctionsMap.find(hashFunctionId);
        // existing hash function ID found in the map
        if (it == hashFunctionsMap.end()) { // Hash function ID not found in the map
           return true;
        }
    }
    if (input.fail() && !input.eof()) {
        return true; // when the extraction of hashFunctionId fails (not EOF)
    }
    return false;
}
