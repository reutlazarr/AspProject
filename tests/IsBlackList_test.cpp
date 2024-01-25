#include <gtest/gtest.h>
#include "../headers/IsBlackList.h"
#include "../headers/RealBlackList.h"
#include "../headers/AddUrl.h"

TEST(IsBlackListTest, IsBlackListCommand) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // Add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction1>()); 
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    RealBlackList realBlackList({"www.example.com0","www.example.com111","www.example.com11111"});
    AddUrl addUrlCommand(realBlackList);
    EXPECT_EQ(addUrlCommand.execute(bloomFilter, "www.example.com0"), "true");
    addUrlCommand.execute(bloomFilter, "www.example.com111");
    IsBlackList isBlackListCommand(realBlackList);
    // Check if url is in the bloomFilter
    //EXPECT_TRUE(isBlackListCommand.execute(bloomFilter, "www.example.com0"));
    // Check if url is not in the bloomFilter
    //EXPECT_FALSE(isBlackListCommand.execute(bloomFilter,"www.example.com1111"));
    //EXPECT_TRUE(isBlackListCommand.compareResults("www.example.com11",realBlackList ,bloomFilter));
    //EXPECT_TRUE(isBlackListCommand.compareResults("www.example.com111",realBlackList ,bloomFilter));
}