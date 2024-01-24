// Menu.h

#include<string>
#include <utility>

// header for Menu
class Menu {
    
public:
    std::pair<int, std::string> nextCommand(); // return int for the commannd, and string for the url

    void displayError(const std::string& message) const; // print messageEror to print
};


