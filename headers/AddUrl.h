// AddUrl.h

#ifndef ADDURL_H
#define ADDURL_H

#include "ICommand.h"
#include "BloomFilter.h" 
#include "RealBlackList.h"
#include<string>

class AddUrl : public ICommand {
public:
    // Implementing the execute method from ICommand interface
    void execute(BloomFilter& bloomFilter, const std::string& url) override;
    // Add a new URL to the blacklist
    void addUrlToRealList(const std::string& url, RealBlackList& realBlackListRef);
};

#endif // ADDURL_H