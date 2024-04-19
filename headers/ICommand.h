//ICommands.h

#ifndef ICommand_h
#define ICommand_h
#include <string>
#include "BloomFilter.h"
#include "RealBlackList.h"

// ICommand interface
class ICommand {
public:
    // Pure virtual function, making it an abstract class
    virtual std::string execute(BloomFilter& bloomFilter, const std::string& url) = 0;
};

#endif //ICommands.h
