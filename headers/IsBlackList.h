#include "ICommand.h"
#include "BloomFilter.h"  

class IsBlacklist : public ICommand {
public:
    // Implementing the execute method from ICommand interface
    bool execute(BloomFilter& bloomFilter, const std::string& url) override;
};
