#include <gtest/gtest.h>
#include "../headers/BloomFilter.h"

TEST(BloomFilterTest, Getters) {
    BloomFilter bloomFilter(8, 1);
    EXPECT_EQ(bloomFilter.SizeArray(), 8);
    EXPECT_EQ(bloomFilter.NumHashFunctions(), 1);
}