// bloomFilterManager_test.cpp

#include <gtest/gtest.h>
#include "../headers/BloomFilterManager.h"
#include "../headers/BloomFilter.h"
#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"
#include<iostream>



// Test for the createBloomFilter method
TEST(BloomFilterManagerTest, CreateBloomFilter) {
    Menu* menu = new Menu();
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctionsMap));

    std::istringstream input("8 1 2\n"); // string simulates the user input
    std::streambuf* originalInput = std::cin.rdbuf(); // stores the original stream buffer of std::cin in a pointer
    std::cin.rdbuf(input.rdbuf()); // replaces the stream buffer of std::cin with the stream buffer of the input stringstream

    BloomFilter bloomFilter = bloomFilterManager.createBloomFilter();

    std::cin.rdbuf(originalInput); // restore the original state

    EXPECT_EQ(8, bloomFilter.getSizeArray());
    
    delete menu;
}