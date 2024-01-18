#include "../headers/BloomFilter.h"

// constractor
BloomFilter::BloomFilter(int sizeArray, int numHashFunctions) : bitArray(sizeArray, false) {
    this->sizeArray = sizeArray;
    this->numHashFunctions = numHashFunctions;
}

void BloomFilter::addUrl(const std::string& url) {
    //implemmentation
}

bool BloomFilter::isBlacklisted(const std::string& url) {
    //implemmentation
}
//getters
int BloomFilter::getSizeArray() {
    return sizeArray;
}

int BloomFilter::getNumHashFunctions() {
    return numHashFunctions;
}

std::vector<bool> BloomFilter::getBitArray() {
    return bitArray;
}