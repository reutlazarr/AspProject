#ifndef ICommand_h
#define ICommand_h
#include <string>
#include "BloomFilter.h"
#include "RealBlackList.h"

// ICommand interface
class ICommand {
protected:
//RealBlackList is member of ICommand
RealBlackList& realBlackListRef;

public:
    // constractor
    ICommand(RealBlackList& realBlackList) : realBlackListRef(realBlackList) {}
    // Pure virtual function, making it an abstract class
    virtual void execute(BloomFilter& bloomFilter, const std::string& url) = 0;
    //  // Virtual destructor in order to ensure a proper deletion
    // virtual ~ICommand() {} 
};

#endif 