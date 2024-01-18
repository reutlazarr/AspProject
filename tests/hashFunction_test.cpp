#include<gtest/gtest.h>
#include "../headers/hashFunction.h"
#include<functional>

//tests for hashFunction
TEST(hashFunctionTest, hashing) {
    HashFunction hashFunction;
    EXPECT_EQ(hashFunction.hash("www.example.com0"), std::hash<std::string>{}("www.example.com0"));
}