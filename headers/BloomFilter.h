#include<string>
#include<vector>
#include "hashFunction.h"

// header for bloomFilter
class BloomFilter {
private:
    int sizeArray;
    int numHashFunctions;
    std::vector<HashFunction> hashFunctions;
    std::vector<bool> bitArray;
public:
    // constractor
    // get std::vector<HashFunction> of hashFunctions, the number of hashFunctions in the vector, and the size of the array
    BloomFilter(int sizeArray, int numHashFunctions, std::vector<HashFunction> hashFunctions);

    void addUrl(const std::string& url);
    bool isBlacklisted(const std::string& url);

    int getSizeArray();
    int getNumHashFunctions();
    std::vector<HashFunction> getHashFunctions();
    std::vector<bool> getBitArray();
};

