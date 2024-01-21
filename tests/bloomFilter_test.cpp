#include <gtest/gtest.h>
#include "../headers/bloomFilter.h"
//#include "../src/bloomFilter.cpp"

// tests for bloomFilter
TEST(BloomFilterTest, Getters) {
    BloomFilter bloomFilter(8, 1);
    EXPECT_EQ(bloomFilter.getSizeArray(), 8);
    EXPECT_EQ(bloomFilter.getNumHashFunctions(), 1);
}
TEST(BloomFilterTest, Functions) {
    BloomFilter bloomFilter(8, 1);
    bloomFilter.addUrl("www.example.com0");
    EXPECT_TRUE(bloomFilter.isBlacklisted("www.example.com0"));
}