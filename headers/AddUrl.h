// AddUrl.h

#ifndef ADDURL_H
#define ADDURL_H

#include "ICommand.h"
#include "BloomFilter.h"

class AddUrl : public ICommand {
public:
    bool execute(BloomFilter& bloomFilter, const std::string& url) override;
};

#endif // ADDURL_H
