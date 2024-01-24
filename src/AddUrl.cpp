#include "../headers/AddUrl.h"
#include <iostream>

// Implementation of execute method
bool AddUrl::execute(BloomFilter& bloomFilter, const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url);
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Add url to bloomFilter by making the index number to true
        bloomFilter.getBitArray()[index] = true;
        std::cout << "the index that become 1 is: " << index << std::endl;
        std::cout << bloomFilter.getBitArray()[index]<< std::endl;
        return bloomFilter.getBitArray()[index];
    }

    return false;
}

