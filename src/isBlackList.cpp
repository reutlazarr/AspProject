// isBlackList.cpp

#include "IsBlackList.h"
#include "AddUrl.h"
#include <iostream>

std::string IsBlackList::execute(BloomFilter& bloomFilter, const std::string& url) {

    bool isMalicious = bloomFilter.contains(url);
    std::string finalResult = "in: ";
    if (isMalicious) {
        // All corresponding bits are set, might be blacklisted
        finalResult = finalResult + "true ";
        bool compareResultsStr = compareResults(url, bloomFilter.getRealBlackListRef());
        if (compareResultsStr) {
            finalResult = finalResult + "true";
            std::cout << finalResult << std::endl;
            return "true";
        }
    }
    finalResult = finalResult + "false";
    std::cout << finalResult << std::endl;
    return "false";
}


// Function to compare results between the realBlackList and the bloomFilter
bool IsBlackList::compareResults(const std::string& url, RealBlackList& realBlackListRef) {
    // Check in RealBlackList
    bool isInRealBlackList = realBlackListRef.isUrlInBlackList(url);
    if (isInRealBlackList) {
        return true;
    }
    return false;
}
