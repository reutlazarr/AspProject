// bloomFilter.cpp

#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include "../headers/BloomFilter.h"
#include<iostream>

// constractor
BloomFilter::BloomFilter(int sizeArray, int numHashFunctions, std::vector<std::unique_ptr<IHashFunction>> hashFunctions) 
: bitArray(sizeArray, false), hashFunctions(std::move(hashFunctions)) {
    this->sizeArray = sizeArray;
    this->numHashFunctions = numHashFunctions;
}

// add url to the bloomFilter
void BloomFilter::addUrl(const std::string& url) {
   
    // loop over all the hashFunctions
    for (auto& hashFunction : hashFunctions) {
            size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
            size_t index = hashValue % bitArray.size(); // Divide the value by the size of bitArray and get index number
            
            // add url to bloomFilter by making the index number to true
            bitArray[index] = true;
            std::cout << "the index that become true in addURL is: " << index << std::endl;
    }
}

// check if url is in the bloomFilter
bool BloomFilter::isBlacklisted(const std::string& url) {
    
    // loop over all the hashFunctions
    for (auto& hashFunction : hashFunctions) {
        size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
        size_t index = hashValue % bitArray.size(); // Divide the value by the size of bitArray and get index number
        std::cout << "the index in isBlackliste is: " << index << std::endl;
        
        // check the number index in bloomFilter
        if (!bitArray[index]) {
            return false;  // If any corresponding bit is not set, it's definitely not blacklisted
        }
    }
    return true;  // All corresponding bits are set, might be blacklisted
}


//getters
int BloomFilter::getSizeArray() {
    return sizeArray;
}

int BloomFilter::getNumHashFunctions() {
    return numHashFunctions;
}

std::vector<IHashFunction*> BloomFilter::getHashFunctions() {
    std::vector<IHashFunction*> rawPointers;
    for (const auto& uniquePtr : hashFunctions) {
        rawPointers.push_back(uniquePtr.get());
    }
    return rawPointers;
}

std::vector<bool> BloomFilter::getBitArray() {
    return bitArray;
}