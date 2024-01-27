#include <gtest/gtest.h>
#include "../headers/IsBlackList.h"
#include "../headers/RealBlackList.h"
#include "../headers/AddUrl.h"

TEST(IsBlackListTest, IsBlackListCommand) {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // Add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction1>()); 
    BloomFilter bloomFilter(8, std::move(hashFunctions));

    RealBlackList realBlackList({""});
    AddUrl addUrlCommand(realBlackList);
    //every new url will store in the RealList and in the bloomFilter
    addUrlCommand.execute(bloomFilter, "www.example.com0");

    addUrlCommand.execute(bloomFilter, "www.example.com111");

    addUrlCommand.execute(bloomFilter, "www.example.com11111");
    IsBlackList isBlackListCommand(realBlackList);

    // execute of IsBlackList is checking if the URL is found both in bloomfilter and realList
    isBlackListCommand.execute(bloomFilter, "www.example.com11");
    //std::cout<<"the reault is"<<result;
    //EXPECT_EQ(result, "true false");
    

    // Check if url is in the bloomFilter
    //EXPECT_TRUE(isBlackListCommand.execute(bloomFilter, "www.example.com0"));
    // Check if url is not in the bloomFilter
    //EXPECT_FALSE(isBlackListCommand.execute(bloomFilter,"www.example.com1111"));
    //EXPECT_TRUE(isBlackListCommand.compareResults("www.example.com11",realBlackList ,bloomFilter));
    //EXPECT_TRUE(isBlackListCommand.compareResults("www.example.com111",realBlackList ,bloomFilter));
}
