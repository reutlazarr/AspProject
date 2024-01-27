#include <gtest/gtest.h>
#include "../headers/AddUrl.h"
#include "../headers/RealBlackList.h"

TEST(AddUrlTest, AddUrlToBlackList) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // ... Initialize hashFunctions with mock or real hash functions
    BloomFilter bloomFilter(100, std::move(hashFunctions));

    AddUrl addUrlCommand;
    std::string urlToAdd = "http://example.com";
    addUrlCommand.execute(bloomFilter, urlToAdd);

    // Check if URL is added to the real blacklist
    EXPECT_TRUE(bloomFilter.getRealBlackListRef().isUrlInBlackList(urlToAdd));
}

TEST(AddUrlTest, UpdateBloomFilter) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // ... Initialize hashFunctions with mock or real hash functions
    BloomFilter bloomFilter(100, std::move(hashFunctions));

    AddUrl addUrlCommand;
    std::string urlToAdd = "http://example.com";
    addUrlCommand.execute(bloomFilter, urlToAdd);

    // Check if the correct bits are set in the Bloom Filter
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(urlToAdd);
        size_t index = hashValue % bloomFilter.getBitArray().size();
        EXPECT_TRUE(bloomFilter.getBitArray()[index]);
    }
}
