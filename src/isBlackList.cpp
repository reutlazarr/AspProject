// isBlackList.cpp

#include "headers/IsBlacklist.h"
#include "headers/AddUrl.h"
#include <iostream>

// IsBlacklist class implementing ICommand interface
// Check if the url is found in the bloomFilter
void IsBlackList::execute(BloomFilter& bloomFilter, const std::string& url) {
    // Loop over all the hashFunctions
    std::string finalResult = "true";
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
        // Divide the value by the size of bitArray and get index number  
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Check the number index in bloomFilter
        if (!(bloomFilter.getBitArray()[index])) {
            // If any corresponding bit is not set, it's definitely not blacklisted
            finalResult = "false";
            break;
        }
    }
    if (finalResult == "true") {
        // All corresponding bits are set, might be blacklisted
        std::string compareResultsStr = compareResults(url, bloomFilter.getRealBlackListRef());

        // The final result: "true" + result from compareResults (true/ false)
        finalResult = finalResult + " " + compareResultsStr;
    }
    std::cout << finalResult << std::endl;
}


// Function to compare results between the realBlackList and the bloomFilter
std::string IsBlackList::compareResults(const std::string& url, RealBlackList& realBlackListRef) {
    // Check in RealBlackList
    bool isInRealBlackList = realBlackListRef.isUrlInBlackList(url);
    std::string resultString = isInRealBlackList ? "true" : "false";
    return resultString;
}
