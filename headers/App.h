// App.h

#ifndef APP_H
#define APP_H


#include <map>
#include <memory>
#include "BloomFilter.h"
#include "BloomFilterManager.h"
#include "ICommand.h"

// header for app
class App {
    
private:
    Menu menu;
    BloomFilterManager bloomFilterManager;
    BloomFilter bloomFilter;
    std::map<int, std::unique_ptr<ICommand>> commands;
    void setCommands(); // set map of commands
    
public:
    // constractor
    App();
    void run(); // run the app
};

#endif // APP_H