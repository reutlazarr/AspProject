
#include "ICommand.h"
#include "BloomFilter.h" 
#include "RealBlackList.h"

class AddUrl : public ICommand {
public:
    AddUrl(RealBlackList& initialList);

    // Implementing the execute method from ICommand interface
    std::string execute(BloomFilter& bloomFilter, const std::string& url) override;
    // Add a new URL to the blacklist
    void addUrlToRealList(RealBlackList& realBlackList, const std::string& url);
};
