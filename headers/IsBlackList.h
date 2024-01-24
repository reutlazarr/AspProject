#ifndef IS_BLACKLIST_H
#define IS_BLACKLIST_H
#include "ICommand.h"
#include "BloomFilter.h"  
#include "RealBlackList.h"

class IsBlackList : public ICommand {
public:
    // Implementing the execute method from ICommand interface
    bool execute(BloomFilter& bloomFilter, const std::string& url) override;

    bool compareResults(const std::string& url, RealBlackList& realBlackList, BloomFilter& bloomFilter);
};
#endif // IS_BLACKLIST_H
