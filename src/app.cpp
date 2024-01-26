// app.cpp

#include "../headers/App.h"
#include "../headers/Menu.h"
#include "../headers/BloomFilterManager.h"
#include "../headers/BloomFilter.h"
#include "../headers/AddUrl.h"
#include "../headers/IsBlackList.h"
#include "../headers/ICommand.h"
#include <stdexcept>
#include <iostream>
#include <sstream>

// constructor
App::App() : menu(Menu()) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions[1] = std::make_unique<HashFunction1>();
    hashFunctions[2] = std::make_unique<HashFunction2>();
    bloomFilterManager = BloomFilterManager(menu, std::move(hashFunctions));
    setCommands();
}

// set map of commands
void App::setCommands() {
    commands[1] = std::make_unique<AddUrl>();
    commands[2] = std::make_unique<IsBlackList>();
}

// run the app
void App::run() {
    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter();
    while (true) {
        // loop of command from the user and execute
        try {
            std::stringstream input = menu.nextCommand();
            auto task = menu.executeCommand(input); // should get pair of command and url
            // Check if the task is legal- 1 or 2
            commands[task.first]->execute(bloomFilter, task.second);
        } catch(const std::exception& ex) {
            menu.displayError("Error: " + std::string(ex.what()));
        }
    }    
}