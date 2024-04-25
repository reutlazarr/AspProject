// isBlackList.cpp

#include "IsBlackList.h"
#include "AddUrl.h"
#include <iostream>

// IsBlacklist class implementing ICommand interface
// Check if the url is found in the bloomFilter
std::string IsBlackList::execute(BloomFilter &bloomFilter, const std::string &url)
{
    // std::cout << bloomFilter.toString() << std::endl;
    if (!bloomFilter.contains(url))
    {
        std::cout << "bloomfilter says it is false" << std::endl;
        return "false";
    }
    return bloomFilter.getRealBlackListRef().isUrlInBlackList(url) ? "true" : "false";
}
