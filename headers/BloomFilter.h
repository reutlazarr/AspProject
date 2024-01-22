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
    int numHashFunctions;
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    std::vector<bool> bitArray;

public:
    // constractor
    // get std::vector<std::unique_ptr<IHashFunction>>,
    // the number of hashFunctions in the vector, and the size of the array
    BloomFilter(int sizeArray, int numHashFunctions, std::vector<std::unique_ptr<IHashFunction>> hashFunctions);

    // methodes

    // get string
    void addUrl(const std::string& url); // add url to the bloomFilter

    // get string
    // return bool value the string is in the bloomFilter
    bool isBlacklisted(const std::string& url); // check if url is in the bloomFilter

    // getters
    int getSizeArray();
    int getNumHashFunctions();
    std::vector<IHashFunction*> getHashFunctions();
    std::vector<bool> getBitArray();
};

#endif // BLOOM_FILTER_H