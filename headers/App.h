// App.h

#ifndef APP_H
#define APP_H

#include <iostream>
#include <map>
#include <memory>
#include "BloomFilter.h"
#include "BloomFilterManager.h"
#include "IHashFunction.h"
#include "ICommand.h"
#include "Menu.h"

// header for app
class App {
    
private:
    Menu& menu;
    std::map<int, std::unique_ptr<ICommand>> commands;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionMap;
    BloomFilterManager bloomFilterManager;
    BloomFilter bloomFilter;
    
public:
    // constractor
    // get map of commands and the bloomFilter
    App(Menu& menu, std::map<int, std::unique_ptr<ICommand>> commands, std::map<int, std::unique_ptr<IHashFunction>> hashFunctionMap);
    
    void run(); // run the app

    //getters
    const std::map<int, std::unique_ptr<ICommand>>& getCommands() const; // return map of commands
    
    const std::map<int, std::unique_ptr<IHashFunction>>& getHashFunctions() const; // return map of hash functions
    
    const Menu& getMenu() const; // get the menu
};


#endif // APP_H