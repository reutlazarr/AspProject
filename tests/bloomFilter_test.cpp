#include <gtest/gtest.h>
#include "../headers/bloomFilter.h"

// tests for bloomFilter
TEST(BloomFilterTest, Getters) {
    std::vector<HashFunction> hashFunctions;
    BloomFilter bloomFilter(8, 1, hashFunctions);
    EXPECT_EQ(bloomFilter.getSizeArray(), 8);
    EXPECT_EQ(bloomFilter.getNumHashFunctions(), 1);
}

TEST(BloomFilterTest, Case1) {
    std::vector<HashFunction> hashFunctions1;
    BloomFilter bloomFilter(8, 1, hashFunctions1);
    bloomFilter.addUrl("www.example.com0");
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1"));
}

TEST(BloomFilterTest, Case2) {
    std::vector<HashFunction> hashFunctions2;
    BloomFilter bloomFilter(8, 1, hashFunctions2);
    bloomFilter.addUrl("www.example.com0");
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1"));
}

TEST(BloomFilterTest, Case1_2) {
    std::vector<HashFunction> hashFunctions1_2;
    BloomFilter bloomFilter(8, 2, hashFunctions1_2);
    bloomFilter.addUrl("www.example.com0");
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
    EXPECT_FALSE(bloomFilter.isBlacklisted("www.example.com1"));
}