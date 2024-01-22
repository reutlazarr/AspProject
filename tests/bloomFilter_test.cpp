// bloomFilter_test.cpp

#include <gtest/gtest.h>
#include <memory>
#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include "../headers/BloomFilter.h"

// tests for bloomFilter
TEST(BloomFilterTest, Getters) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>());
    BloomFilter bloomFilter(8, 1, std::move(hashFunctions));
    EXPECT_EQ(bloomFilter.getSizeArray(), 8);
    EXPECT_EQ(bloomFilter.getNumHashFunctions(), 1);
}

// test for HashFunction1
TEST(BloomFilterTest, Case1) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    BloomFilter bloomFilter(8, 1, std::move(hashFunctions));
    bloomFilter.addUrl("www.example.com0"); // add url to the bloomFilter
    // check if url is in the bloomFilter
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1111")); // not in the bloomFilter
}

// test for HashFunction2
TEST(BloomFilterTest, Case2) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction2>()); // add HashFunction2 to the vector of hashFunctions
    BloomFilter bloomFilter(8, 1, std::move(hashFunctions));
    bloomFilter.addUrl("www.example.com0"); // add url to the bloomFilter
    // check if url is in the bloomFilter
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1")); // not in the bloomFilter
}

// test for both HashFunction1 and HashFunction2
TEST(BloomFilterTest, Case1_2) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction2>()); // add HashFunction2 to the vector of hashFunctions
    BloomFilter bloomFilter(8, 2,std::move(hashFunctions));
    bloomFilter.addUrl("www.example.com0"); // add url to the bloomFilter
    // check if url is in the bloomFilter
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1")); // not in the bloomFilter
}
