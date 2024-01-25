// Initialize.h

#include "IHashFunction.h"
#include "ICommand.h"
#include "Menu.h"
#include "RealBlackList.h"
#include <map>


// header for initialize
class Initialize {

private:
    Menu menu;
    std::map<int, std::unique_ptr<ICommand>> commands;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    // setters
    void setHashFunctions(); // set map of hash functions

    void setCommands(); // set map of commands
    
    void setMenu(); // set the menu


public:
    // constractor
    Initialize();

    // getters
    const std::map<int, std::unique_ptr<ICommand>>& getCommands() const; // return map of commands
    
    const std::map<int, std::unique_ptr<IHashFunction>>& getHashFunctions() const; // return map of hash functions
    
    const Menu& getMenu() const; // get the menu
};