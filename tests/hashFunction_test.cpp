#include<gtest/gtest.h>
#include "../headers/hashFunction.h"


//tests for hashFunction
TEST(hashFunctionTest, hashing) {
    HashFunction hashFunction;
    EXPECT_EQ(hashFunction("www.example.com0"), std::hash<std::string>{}("www.example.com0"));
}
