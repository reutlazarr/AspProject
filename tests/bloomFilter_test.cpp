#include <gtest/gtest.h>
#include <memory>
#include "../headers/BloomFilter.h"
#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"

// tests for bloomFilter
TEST(BloomFilterTest, Getters) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>());
    BloomFilter bloomFilter(8, 1, hashFunctions);
    EXPECT_EQ(bloomFilter.getSizeArray(), 8);
    EXPECT_EQ(bloomFilter.getNumHashFunctions(), 1);
}

TEST(BloomFilterTest, Case1) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>());
    BloomFilter bloomFilter(8, 1, hashFunctions1);
    bloomFilter.addUrl("www.example.com0");
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1111"));
}

