// addUrl.cpp

#include "AddUrl.h"
#include "RealBlackList.h"
#include "BloomFilter.h"
#include <iostream>
#include <algorithm>

// Implementation of execute method of ICommand
// Add Url to the BloomFilter and to the black list
std::string AddUrl::execute(BloomFilter &bloomFilter, const std::string &url)
{
    addUrlToRealList(url, bloomFilter.getRealBlackListRef());
    bloomFilter.add(url);
    std::cout << bloomFilter.toString() << std::endl;
    return "added";
}

// Add a new URL to the real black list - in order to show false positive
void AddUrl::addUrlToRealList(const std::string &url, RealBlackList &realBlackListRef)
{
    // Use std::find to check if the URL is already in the blacklist
    auto check = std::find(realBlackListRef.getRealList().begin(), realBlackListRef.getRealList().end(), url);

    // Check if the URL was not found
    if (check == realBlackListRef.getRealList().end())
    {
        // URL is not in the blacklist, so add it
        realBlackListRef.getRealList().push_back(url); // URL added to the blacklist
    }
    else
    {
        // URL is already in the blacklist
    }
}
