#include "../headers/AddUrl.h"
#include <iostream>

// Implementation of execute method
bool AddUrl::execute(BloomFilter& bloomFilter, const std::string& url) {
    // loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url);
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // add url to bloomFilter by making the index number to true
        bloomFilter.getBitArray()[index] = true;
        // // Obtain a reference to the bit at index 
        // const bool& referenceToBit = bloomFilter.getBitArray()[index];
        // // Modify the bit through the reference
        // referenceToBit = true;
        std::cout << "the index that become 1 is: " << index << std::endl;
        return true;
    }

    return false;
}

