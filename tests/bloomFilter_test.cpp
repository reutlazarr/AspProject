// bloomFilter_test.cpp

#include <gtest/gtest.h>
#include <memory>
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include "../headers/BloomFilter.h"


// tests for bloomFilter getters
TEST(BloomFilterTest, Getters) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions; //vector
    std::unique_ptr<HashFunction1> hashFunction1 = std::make_unique<HashFunction1>(); //hashFunction1
    const auto& test1 = hashFunction1.get(); // copy the pointer to hashFunction1
    hashFunctions.push_back(std::move(hashFunction1)); // add hashFunction1 to the vector and delete the origin pionter
    BloomFilter bloomFilter(8, std::move(hashFunctions)); // pointer of hashFunctions deleted and moveed
    // Check individual elements of the vectors
    EXPECT_EQ(bloomFilter.getSizeArray(), 8);
    // Check hashFunctions vectors
    EXPECT_EQ(bloomFilter.getHashFunctions().size(), 1);
    EXPECT_EQ(bloomFilter.getHashFunctions()[0].get(),test1);
}

// test for HashFunction1 in bloomFilter
TEST(BloomFilterTest, Case1) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    bloomFilter.addUrl("www.example.com0"); // add url to the bloomFilter
    // check if url is in the bloomFilter
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1111")); // not in the bloomFilter
}

// test for HashFunction2 in bloomFilter
TEST(BloomFilterTest, Case2) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    std::unique_ptr<HashFunction2> hashFunction2 = std::make_unique<HashFunction2>(); //hashFunction2
    const auto& test2 = hashFunction2.get(); // copy the pointer to hashFunction2
    hashFunctions.push_back(std::move(hashFunction2)); // add hashFunction2 to the vector and delete the origin pionter
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    bloomFilter.addUrl("www.example.com0"); // add url to the bloomFilter
    // check if url is in the bloomFilter
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1")); // not in the bloomFilter
    // Check hashFunctions vectors
    EXPECT_EQ(bloomFilter.getHashFunctions().size(), 1);
    EXPECT_EQ(bloomFilter.getHashFunctions()[0].get(),test2);
}

// test for both HashFunction1 and HashFunction2 in bloomFilter
TEST(BloomFilterTest, Case1_2) {
    // input- 8 1 2
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction2>()); // add HashFunction2 to the vector of hashFunctions
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    bloomFilter.addUrl("www.example.com0"); // add url to the bloomFilter
    // check if url is in the bloomFilter
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1")); // not in the bloomFilter
}
