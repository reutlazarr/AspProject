// BloomFilter.h

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include<string>
#include<vector>
#include <memory>
#include "IHashFunction.h"
#include "HashFunction1.h"
#include "HashFunction2.h"

// header for bloomFilter
class BloomFilter {

private:
    int sizeArray;
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    std::vector<bool> bitArray;

public:
    // constractor
    // get std::vector<std::unique_ptr<IHashFunction>>, and the size of the array
    BloomFilter(int sizeArray, std::vector<std::unique_ptr<IHashFunction>> hashFunctions);

    // getters
    int getSizeArray();
    std::vector<IHashFunction*> getHashFunctions();
    std::vector<bool> getBitArray();
};

#endif // BLOOM_FILTER_H