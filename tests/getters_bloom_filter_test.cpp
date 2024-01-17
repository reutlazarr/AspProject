#include <gtest/gtest.h>
#include "BloomFilter.h"

Test(BloomFilterTest, Getters)
    BloomFilter bloomFilter(8, 1)
    Except_EQ(bloomFilter.getSizeArray(), 8)
    Except_EQ(bloomFilter.getNumHashFunctions(), 1)