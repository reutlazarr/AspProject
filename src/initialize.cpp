// initialize.cpp

#include "../headers/Initialize.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include "../headers/AddUrl.h"
#include "../headers/IsBlackList.h"
#include "../headers/Menu.h"
#include "../headers/RealBlackList.h"
#include <map>

// constractor
Initialize::Initialize() {
    setHashFunctions();
    setCommands();
    setMenu();
}
// set map of hash functions
void Initialize::setHashFunctions() {
    hashFunctions[1] = std::make_unique<HashFunction1>();
    hashFunctions[2] = std::make_unique<HashFunction2>();
}

// set map of commands
void Initialize::setCommands() {
    RealBlackList realBlackList;
    commands[1] = std::make_unique<AddUrl>(realBlackList);
    commands[2] = std::make_unique<IsBlackList>(realBlackList);
}

// set the menu
void Initialize::setMenu() {
    menu = Menu();
}


// return map of commands
const std::map<int, std::unique_ptr<ICommand>>& Initialize::getCommands() const {
    return commands;
}

// return map of hash functions
const std::map<int, std::unique_ptr<IHashFunction>>& Initialize::getHashFunctions() const {
    return hashFunctions;
} 

// return the menu
const Menu& Initialize::getMenu() const {
    return menu;
}