#include <gtest/gtest.h>
#include "../headers/IsBlackList.h"
#include "../headers/AddUrl.h"

TEST(IsBlackListTest, IsBlackListCommand) {
    // test for HashFunction1
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    AddUrl addUrlCommand;
    ASSERT_TRUE(addUrlCommand.execute(bloomFilter, "www.example.com0"));
    IsBlacklist isBlackListCommand;
    // check if url is in the bloomFilter
    EXPECT_TRUE(isBlackListCommand.execute(bloomFilter, "www.example.com0"));
    EXPECT_FALSE(isBlackListCommand.execute(bloomFilter,"www.example.com1111")); // not in the bloomFilter
}