// bloomFilter.cpp

#include "IHashFunction.h"
#include "HashFunction1.h"
#include "HashFunction2.h"
#include "RealBlackList.h"
#include "BloomFilter.h"


// constractor
BloomFilter::BloomFilter(int sizeArray, std::vector<std::unique_ptr<IHashFunction>> hashFunctions)
    : bitArray(sizeArray, false), hashFunctions(std::move(hashFunctions)), realBlackListRef() {
    this->sizeArray = sizeArray;
}

//getters
int BloomFilter::getSizeArray() {
    return sizeArray;
}

const std::vector<std::unique_ptr<IHashFunction>>& BloomFilter::getHashFunctions() const {
    return hashFunctions;
}

std::vector<bool>& BloomFilter::getBitArray() {
    return bitArray;
}

RealBlackList& BloomFilter::getRealBlackListRef() {
    return realBlackListRef;
}

void BloomFilter::add(const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : hashFunctions) {
        size_t hashValue = (*hashFunction)(url);
        // Add url to bloomFilter by making the index number to true
        bitArray[hashValue % bitArray.size()] = true;
    }
}

bool BloomFilter::contains(const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : hashFunctions) {
            size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
            // Check if the number index in bloomFilter is not set
            if (!bitArray[hashValue % bitArray.size()]) {
                return false; // not blacklisted
            }
    }
    return true;
}
