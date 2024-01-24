// bloomFilter.cpp

#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include "../headers/BloomFilter.h"
#include <iostream>

// constractor
BloomFilter::BloomFilter(int sizeArray, std::vector<std::unique_ptr<IHashFunction>> hashFunctions) 
: bitArray(sizeArray, false), hashFunctions(std::move(hashFunctions)) {
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