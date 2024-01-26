// IsBlackList.h

#ifndef IS_BLACKLIST_H
#define IS_BLACKLIST_H
#include "ICommand.h"
#include "BloomFilter.h"  
#include "RealBlackList.h"

class IsBlackList : public ICommand {
public:
    // Implementing the execute method from ICommand interface
    // Check if the URL is found both in bloomFilter and in the realBlackList
    void execute(BloomFilter& bloomFilter, const std::string& url) override;

    std::string compareResults(const std::string& url, RealBlackList& realBlackListRef);
};
#endif // IS_BLACKLIST_H
