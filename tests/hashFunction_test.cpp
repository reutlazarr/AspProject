// HashFunction_test.cpp

#include <gtest/gtest.h>
#include "HashFunction1.h"
#include "HashFunction2.h"


// Test Hashing
TEST(HashFunctions, Hashing) {
    HashFunction1 hashFunction1;
    EXPECT_EQ(hashFunction1("www.example.com0"), hashFunction1("www.example.com0"));
    EXPECT_EQ(hashFunction1("www.example.com0"), 8231510004620773819);
    EXPECT_FALSE(hashFunction1("www.example.com000") == hashFunction1("www.example.com0"));
    
    HashFunction2 hashFunction2;
    EXPECT_EQ(hashFunction2("www.example.com0"), hashFunction2("www.example.com0"));
    EXPECT_EQ(hashFunction2("www.example.com0"), 6657855685155196946);
    EXPECT_FALSE(hashFunction2("www.example.com000") == hashFunction2("www.example.com0"));
}


// Test getIdentifier of HashFunctions
TEST(HashFunctions, getIdentifier) {
    HashFunction1 hashFunction1;
    EXPECT_EQ(hashFunction1.getIdentifier(), 1);
    HashFunction2 hashFunction2;
    EXPECT_EQ(hashFunction2.getIdentifier(), 2);
}

// Test CloneFunction of HashFunctions
TEST(HashFunctions, CloneFunction) {
    HashFunction1 hashFunction1;
    std::unique_ptr<IHashFunction> clonedHashFunction1 = hashFunction1.clone();
    EXPECT_NE(&hashFunction1, clonedHashFunction1.get());
    EXPECT_EQ(hashFunction1.getIdentifier(), clonedHashFunction1->getIdentifier());

    HashFunction2 hashFunction2;
    std::unique_ptr<IHashFunction> clonedHashFunction2 = hashFunction2.clone();
    EXPECT_NE(&hashFunction2, clonedHashFunction2.get());
    EXPECT_EQ(hashFunction2.getIdentifier(), clonedHashFunction2->getIdentifier());
}