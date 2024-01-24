#include <gtest/gtest.h>
#include "../headers/AddUrl.h"

TEST(AddUrlTest, AddUrlCommand) {
    //bloomfiltercreation
    //hashfunction's vector creation
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions.push_back(std::make_unique<HashFunction1>()); // add HashFunction1 to the vector of hashFunctions
    BloomFilter bloomFilter(8, 1, std::move(hashFunctions));
    AddUrl addUrlCommand;
    addUrlCommand.execute(bloomFilter, "www.example.com0");
    bool addedSuccessfully = addUrlCommand.execute(bloomFilter, "www.example.com0");
    // Check if the URL was added successfully
    ASSERT_TRUE(addedSuccessfully);}
