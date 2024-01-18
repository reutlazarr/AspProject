#include<string>
#include<vector>

class BloomFilter
{
private:
    int sizeArray;
    int numHashFunctions;
    std::vector<bool> bitArray;
public:
    BloomFilter(int sizeArray, int numHashFunctions);
    ~BloomFilter();
    void addUrl(const std::string& url);
    bool isBlacklisted(const std::string& url);
    int getSizeArray();
    int getNumHashFunctions();
    std::vector<bool> getBitArray();
};

