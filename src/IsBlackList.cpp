#include "../headers/IsBlacklist.h"
#include <iostream>

// IsBlacklist class implementing ICommand interface
// Check if the url is found in the bloomFilter
bool IsBlackList::execute(BloomFilter& bloomFilter, const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
        // Divide the value by the size of bitArray and get index number  
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Check the number index in bloomFilter
        if (!(bloomFilter.getBitArray()[index])) {
            // If any corresponding bit is not set, it's definitely not blacklisted
            return false;  
            //execute over
        }
    }
    // All corresponding bits are set, might be blacklisted
    return true;  
    //and then we call compareResults
}

// Function to compare results between the realBlackList and the bloomFilter
bool IsBlackList::compareResults(const std::string& url, RealBlackList& realBlackList, BloomFilter& bloomFilter) {
    // Check in RealBlackList
    bool isInRealBlackList = realBlackList.isUrlInBlackList(url);

    // Check in BloomFilter using IsBlackList
    IsBlackList isBlackList;
    bool isInBloomFilter = isBlackList.execute(bloomFilter, url);

    // Compare results
    bool result = (isInRealBlackList == isInBloomFilter);
    // If the result is False it means we had False Possitive in the bloom
    return result;
}