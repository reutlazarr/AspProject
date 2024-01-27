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
