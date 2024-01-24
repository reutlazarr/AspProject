#include <gtest/gtest.h>
#include "../headers/AddUrl.h"
#include "../headers/RealBlackList.h"

TEST(AddUrlTest, AddUrlCommand) {
    // Hashfunction's vector creation
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // Add HashFunction1 to the vector of hashFunctions
    hashFunctions.push_back(std::make_unique<HashFunction1>()); 
    // BloomFilter Creation
    BloomFilter bloomFilter(8, std::move(hashFunctions));
    AddUrl addUrlCommand;
    bool addedSuccessfully = addUrlCommand.execute(bloomFilter, "www.example.com0");
    // Check if the URL was added successfully
    ASSERT_TRUE(addedSuccessfully);
    }
    