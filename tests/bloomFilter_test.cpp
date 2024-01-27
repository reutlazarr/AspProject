// bloomFilter_test.cpp

#include <gtest/gtest.h>
#include <memory>
#include "HashFunction1.h"
#include "HashFunction2.h"
#include "BloomFilter.h"
#include "RealBlackList.h"
#include "AddUrl.h"

// Tests for bloomFilter getters
TEST(BloomFilterTest, Getters) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions; //vector
    std::unique_ptr<HashFunction1> hashFunction1 = std::make_unique<HashFunction1>(); //hashFunction1
    const auto& test1 = hashFunction1.get(); // copy the pointer to hashFunction1
    hashFunctions.push_back(std::move(hashFunction1)); // add hashFunction1 to the vector and delete the origin pionter
    BloomFilter bloomFilter(8, std::move(hashFunctions)); // pointer of hashFunctions deleted and moved
    // Check individual elements of the vectors
    EXPECT_EQ(bloomFilter.getSizeArray(), 8);
    // Check hashFunctions vectors
    EXPECT_EQ(bloomFilter.getHashFunctions().size(), 1);
    EXPECT_EQ(bloomFilter.getHashFunctions()[0].get(),test1);
    
}

TEST(BloomFilterTest, BitArrayInitialization) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    BloomFilter bloomFilter(10, std::move(hashFunctions));
    auto bitArray = bloomFilter.getBitArray();
    for (bool bit : bitArray) {
        EXPECT_FALSE(bit);
    }
}

// Test for HashFunction1 in bloomFilter
TEST(BloomFilterTest, Case1) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    BloomFilter bloomFilter(8, std::move(hashFunctions));

}

// Test for HashFunction2 in bloomFilter
TEST(BloomFilterTest, Case2) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    std::unique_ptr<HashFunction2> hashFunction2 = std::make_unique<HashFunction2>(); //hashFunction2
    const auto& test2 = hashFunction2.get(); // copy the pointer to hashFunction2
    hashFunctions.push_back(std::move(hashFunction2)); // add hashFunction2 to the vector and delete the origin pionter
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    // Check hashFunctions vectors
    EXPECT_EQ(bloomFilter.getHashFunctions().size(), 1);
    EXPECT_EQ(bloomFilter.getHashFunctions()[0].get(),test2);
}

// Test for both HashFunction1 and HashFunction2 in bloomFilter
TEST(BloomFilterTest, Case1_2) {
    // input- 8 1 2
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction2>()); // add HashFunction2 to the vector of hashFunctions
    BloomFilter bloomFilter(8, std::move(hashFunctions));
}


// Test to check if adding URL to RealBlackList reflects correctly
TEST(BloomFilterBlackList, AddUrlUpdatesBlackListCheck) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>());
    BloomFilter bloomFilter(100, std::move(hashFunctions));

    AddUrl addUrlCommand;
    std::string testUrl = "http://example.com";
    addUrlCommand.execute(bloomFilter, testUrl);

    // Check if the URL is correctly added to the real blacklist
    EXPECT_TRUE(bloomFilter.getRealBlackListRef().isUrlInBlackList(testUrl));

    // Check if the Bloom Filter's bit array is updated correctly
    for (const auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(testUrl);
        size_t index = hashValue % bloomFilter.getBitArray().size();
        EXPECT_TRUE(bloomFilter.getBitArray()[index]) << "Bit not set for index " << index;
    }
}

