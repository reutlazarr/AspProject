// HashFunction_test.cpp

#include<gtest/gtest.h>
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"


// Test HashFunction1
TEST(HashFunction1Test, HashFunction1Hashing) {
    HashFunction1 hashFunction1;
    EXPECT_EQ(hashFunction1("www.example.com0"), hashFunction1("www.example.com0"));
    EXPECT_EQ(hashFunction1("www.example.com0"), 8231510004620773819);
}

// Test HashFunction2
TEST(HashFunction2Test, HashFunction2Hashing) {
    HashFunction2 hashFunction2;
    EXPECT_EQ(hashFunction2("www.example.com0"), hashFunction2("www.example.com0"));
    EXPECT_EQ(hashFunction2("www.example.com0"), 6657855685155196946);
}