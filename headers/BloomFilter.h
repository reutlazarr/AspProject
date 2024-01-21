#include<string>
#include<vector>

// header for bloomFilter
class BloomFilter {
private:
    int sizeArray;
    int numHashFunctions;
    std::vector<bool> bitArray;
public:
    BloomFilter(int sizeArray, int numHashFunctions);

    void addUrl(const std::string& url);
    bool isBlacklisted(const std::string& url);

    int getSizeArray();
    int getNumHashFunctions();
    std::vector<bool> getBitArray();
};

