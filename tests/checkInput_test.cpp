// checkInput_test.cpp

#include <gtest/gtest.h>
#include "../headers/CheckInput.h"
#include "../headers/HashFunction1.h"
#include "../headers/HashFunction2.h"

TEST(CheckInputTest, ExecuteCommandValidInput) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    CheckInput checkInput(std::move(hashFunctionsMap));
    //std::stringstream input;
    std::stringstream input("1 example.com");

    bool result = checkInput.checkExecuteCommand(input);
    EXPECT_FALSE(result);
}

TEST(CheckInputTest, ExecuteCommandInvalidInput) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    CheckInput checkInput(std::move(hashFunctionsMap));
    std::stringstream input("invalid_input");

    bool result = checkInput.checkExecuteCommand(input);
    EXPECT_TRUE(result);
}

TEST(CheckInputTest, ArraySizeValidInput) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    CheckInput checkInput(std::move(hashFunctionsMap));
    std::stringstream input("5");

    bool result = checkInput.checkArraySize(input);
    EXPECT_TRUE(result);
}

TEST(CheckInputTest, ArraySizeInvalidInput) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    CheckInput checkInput(std::move(hashFunctionsMap));
    std::stringstream input("invalid_input");

    bool result = checkInput.checkArraySize(input);
    EXPECT_FALSE(result);
}