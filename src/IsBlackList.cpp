#include "../headers/IsBlacklist.h"
#include <iostream>

// IsBlacklist class implementing ICommand interface
bool IsBlacklist::execute(BloomFilter& bloomFilter, const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
        // Divide the value by the size of bitArray and get index number  
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Check the number index in bloomFilter
        if (!(bloomFilter.getBitArray()[index])) {
            // If any corresponding bit is not set, it's definitely not blacklisted
            return false;  
        }
    }
    // All corresponding bits are set, might be blacklisted
    return true;  
};