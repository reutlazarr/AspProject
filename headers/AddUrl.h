// AddUrl.h

#ifndef ADDURL_H
#define ADDURL_H

#include "ICommand.h"
#include "BloomFilter.h" 
#include "RealBlackList.h"

class AddUrl : public ICommand {
public:
    AddUrl(RealBlackList& realBlackList);

    // Implementing the execute method from ICommand interface
    void execute(BloomFilter& bloomFilter, const std::string& url) override;
    // Add a new URL to the blacklist
    void addUrlToRealList(const std::string& url);
};

#endif // ADDURL_H