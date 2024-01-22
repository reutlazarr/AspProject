
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

void BloomFilter::addUrl(const std::string& url) {
    for (auto& hashFunction : hashFunctions) {
            size_t hashValue = hashFunction(url);
            size_t index = hashValue % bitArray.size();
            bitArray[index] = true;
            std::cout << "the index that become true in addURL is: " << index << std::endl;
    }
}

bool BloomFilter::isBlacklisted(const std::string& url) {
    for (auto& hashFunction : hashFunctions) {
        size_t hashValue = hashFunction(url);
        size_t index = hashValue % bitArray.size();
        std::cout << "the index in isBlackliste is: " << index << std::endl;
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

std::vector<IHashFunction> BloomFilter::getHashFunctions() {
    return hashFunctions;
}
std::vector<bool> BloomFilter::getBitArray() {
    return bitArray;
}