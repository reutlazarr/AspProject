// bloomFilterManager_test.cpp

#include <gtest/gtest.h>
#include "BloomFilterManager.h"
#include "CheckInput.h"
#include "BloomFilter.h"
#include "IHashFunction.h"
#include "HashFunction1.h"
#include "HashFunction2.h"

// Test for the createBloomFilter with two hashFunctions
TEST(BloomFilterManagerTest, TwoHashInBloomFilter) {
    Menu menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    auto hashFunction1 = std::make_unique<HashFunction1>(); 
    auto hashFunction2 = std::make_unique<HashFunction2>();
    hashFunctionsMap[1] = std::move(hashFunction1);
    hashFunctionsMap[2] = std::move(hashFunction2);
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctionsMap));

    std::stringstream input("8 1 2\n"); // string simulates the user input

    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter(input);
    EXPECT_EQ(8, bloomFilter.getSizeArray());
    EXPECT_TRUE(bloomFilter.getHashFunctions().size() == 2);
}

// Test for the createBloomFilter with one hashFunction
TEST(BloomFilterManagerTest, OneHashInBloomFilter) {
    Menu menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    auto hashFunction1 = std::make_unique<HashFunction1>(); 
    hashFunctionsMap[1] = std::move(hashFunction1);
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctionsMap));

    std::stringstream input("8 1\n"); // string simulates the user input

    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter(input);
    EXPECT_EQ(8, bloomFilter.getSizeArray());
    EXPECT_EQ(1, bloomFilter.getHashFunctions().size());
}