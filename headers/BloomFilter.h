#include<string>
#include<vector>
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
    // get std::vector<HashFunction> of hashFunctions, the number of hashFunctions in the vector, and the size of the array
    BloomFilter(int sizeArray, int numHashFunctions, std::vector<std::unique_ptr<IHashFunction>> hashFunctions);

    void addUrl(const std::string& url);
    bool isBlacklisted(const std::string& url);

    int getSizeArray();
    int getNumHashFunctions();
    std::vector<IHashFunction> getHashFunctions();
    std::vector<bool> getBitArray();
};

