#ifndef ICommand_h
#define ICommand_h
#include <string>
// Forward declaration of BloomFilter class
class BloomFilter;

// ICommand interface
class ICommand {
public:
    // Pure virtual function, making it an abstract class
    virtual bool execute(BloomFilter& bloomFilter, const std::string& url) = 0;
    //  // Virtual destructor in order to ensure a proper deletion
    // virtual ~ICommand() {} 
};

#endif 