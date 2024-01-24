#include <gtest/gtest.h>
#include "../headers/IsBlackList.h"
#include "../headers/AddUrl.h"

TEST(IsBlackListTest, IsBlackListCommand) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // Add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction1>()); 
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    AddUrl addUrlCommand;
    EXPECT_TRUE(addUrlCommand.execute(bloomFilter, "www.example.com0"));
    IsBlacklist isBlackListCommand;
    // Check if url is in the bloomFilter
    EXPECT_TRUE(isBlackListCommand.execute(bloomFilter, "www.example.com0"));
    // Check if url is not in the bloomFilter
    EXPECT_FALSE(isBlackListCommand.execute(bloomFilter,"www.example.com1111")); 
}