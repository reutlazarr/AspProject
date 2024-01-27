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

void App::run() {
    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter();
    while (true) {
        std::stringstream input = menu.nextCommand();
        auto task = menu.executeCommand(input); // should get pair of command and url

        // Check for invalid command
        if (task.first == -1) {
            // Silently handle invalid input and continue the loop
            continue;
        }

        // Execute valid command
        if (commands.find(task.first) != commands.end()) {
            commands[task.first]->execute(bloomFilter, task.second);
        } else {
            // Handle the case where the command is not found in the map
            // This can be silent or you can log it as needed
        }
    }    
}
