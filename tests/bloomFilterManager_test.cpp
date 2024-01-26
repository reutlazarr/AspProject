// bloomFilterManager_test.cpp

#include <gtest/gtest.h>
#include "../headers/BloomFilterManager.h"
#include "../headers/BloomFilter.h"
#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include<iostream>

// Test for the createBloomFilter with tow hashFunctions
TEST(BloomFilterManagerTest, TowHashInBloomFilter) {
    Menu menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    std::unique_ptr<HashFunction1> hashFunction1 = std::make_unique<HashFunction1>(); 
    const auto& testHash1 = hashFunction1.get(); // copy the pointer to hashFunction1
    std::unique_ptr<HashFunction2> hashFunction2 = std::make_unique<HashFunction2>(); 
    const auto& testHash2 = hashFunction2.get(); // copy the pointer to hashFunction2
    hashFunctionsMap[1] = std::move(hashFunction1);
    hashFunctionsMap[2] = std::move(hashFunction2);
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctionsMap));

    std::istringstream input("8 1 2\n"); // string simulates the user input
    std::streambuf* originalInput = std::cin.rdbuf(); // stores the original stream buffer of std::cin in a pointer
    std::cin.rdbuf(input.rdbuf()); // replaces the stream buffer of std::cin with the stream buffer of the input stringstream

    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter();
    EXPECT_EQ(8, bloomFilter.getSizeArray());
    EXPECT_EQ(bloomFilter.getHashFunctions()[0]->getIdentifier(), testHash1->getIdentifier());
    EXPECT_EQ(bloomFilter.getHashFunctions()[1]->getIdentifier(), testHash2->getIdentifier());
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Test for the createBloomFilter with one hashFunctions
TEST(BloomFilterManagerTest, OneHashInBloomFilter) {
    Menu menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    std::unique_ptr<HashFunction2> hashFunction2 = std::make_unique<HashFunction2>(); 
    const auto& testHash2 = hashFunction2.get(); // copy the pointer to hashFunction2
    hashFunctionsMap[2] = std::move(hashFunction2);
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctionsMap));

    std::istringstream input("8 2 \n"); // string simulates the user input
    std::streambuf* originalInput = std::cin.rdbuf(); // stores the original stream buffer of std::cin in a pointer
    std::cin.rdbuf(input.rdbuf()); // replaces the stream buffer of std::cin with the stream buffer of the input stringstream

    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter();
    //std::cin.rdbuf(originalInput); // restore the original state
    EXPECT_EQ(bloomFilter.getHashFunctions().size(), 1);
    EXPECT_EQ(bloomFilter.getHashFunctions()[0]->getIdentifier(), testHash2->getIdentifier());
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}