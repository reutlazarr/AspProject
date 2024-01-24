
#include "ICommand.h"
#include "BloomFilter.h" 

class AddUrl : public ICommand {
public:
    // Implementing the execute method from ICommand interface
    bool execute(BloomFilter& bloomFilter, const std::string& url) override;
    // Add a new URL to the blacklist
    void addUrlToRealList(std::vector<std::string>& realBlackList, const std::string& url);
};
