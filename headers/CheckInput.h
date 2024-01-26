// CheckInput.h

#include "IHashFunction.h"
#include <map>
#include <vector>
#include <set>
#include <memory>
#include <sstream>
#include<string>


class CheckInput {
public:
    //std::stringstream nextCommand(); // return the next command fron the user
    bool checkExecuteCommand(std::stringstream& input); // check the user command
    bool checkArraySize(std::istream& input); // check the user input of arraySize
    bool checkHashFunctions(std::istream& input, std::map<int, std::unique_ptr<IHashFunction>>& hashFunctionsMap); // check the user input of hashFunctions
};

