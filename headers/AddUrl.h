
#include "ICommand.h"
#include "BloomFilter.h" 
#include "RealBlackList.h"

class AddUrl : public ICommand {
public:
    // Implementing the execute method from ICommand interface
    bool execute(BloomFilter& bloomFilter, const std::string& url) override;
    // Add a new URL to the blacklist
    void addUrlToRealList(RealBlackList& realBlackList, const std::string& url);
};
