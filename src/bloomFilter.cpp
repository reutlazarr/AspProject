// bloomFilter.cpp

#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include "../headers/RealBlackList.h"
#include "../headers/BloomFilter.h"


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