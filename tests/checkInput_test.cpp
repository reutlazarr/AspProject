// checkInput_test.cpp

#include <gtest/gtest.h>
#include "headers/CheckInput.h"
#include "headers/HashFunction1.h"
#include "headers/HashFunction2.h"

// tests for executeCommand in checkInput
TEST(CheckInputTest, ExecuteCommand) {
    CheckInput checkInput;
    std::stringstream input("1 example.com");
    bool result = checkInput.checkExecuteCommand(input);
    EXPECT_FALSE(result); // valid input {int 1/2, url}
}

// tests for executeCommandInvalidInput in checkInput
TEST(CheckInputTest, ExecuteCommandInvalidInput) {
    CheckInput checkInput;
    std::stringstream input("invalid_input");
    bool result = checkInput.checkExecuteCommand(input);
    EXPECT_TRUE(result); // invalid input, not {int 1/2, url}

    input.str("2");
    result = checkInput.checkExecuteCommand(input);
    EXPECT_TRUE(result); // invalid input, not {int 1/2, url}

    input.str("");
    result = checkInput.checkExecuteCommand(input);
    EXPECT_TRUE(result); // invalid input, not {int 1/2, url}
}

// tests for ArraySize in checkInput
TEST(CheckInputTest, ArraySize) {
    CheckInput checkInput;
    std::stringstream input("5 a");
    bool result = checkInput.checkArraySize(input);
    EXPECT_FALSE(result); // valid input {positive int........}

    input.str("8");
    result = checkInput.checkArraySize(input);
    EXPECT_FALSE(result); // valid input {positive int........}
}

// tests for ArraySizeInvalidInput in checkInput
TEST(CheckInputTest, ArraySizeInvalidInput) {
    CheckInput checkInput;
    std::stringstream input("invalid_input");

    bool result = checkInput.checkArraySize(input);
    EXPECT_TRUE(result); // invalid input, not {positive int........}

    input.str("0");
    result = checkInput.checkArraySize(input);
    EXPECT_TRUE(result); // invalid input, not {positive int........}
}

// tests for HashFunctions in checkInput
TEST(CheckInputTest, HashFunctions) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    CheckInput checkInput;
    std::stringstream input("1 2");

    bool result = checkInput.checkHashFunctions(input, hashFunctionsMap);
    EXPECT_FALSE(result); // valid input {int 1/2, int 1/2.....}

    input.str("");
    result = checkInput.checkHashFunctions(input, hashFunctionsMap);
    EXPECT_FALSE(result); // valid input for the function, it will faill in createBloomFilter()
}

// tests for HashFunctionsInvalidInput in checkInput
TEST(CheckInputTest, HashFunctionsInvalidInput) {
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    hashFunctionsMap[1] = std::make_unique<HashFunction1>();
    hashFunctionsMap[2] = std::make_unique<HashFunction2>();
    CheckInput checkInput;
    std::stringstream input("invalid_input");

    bool result = checkInput.checkHashFunctions(input, hashFunctionsMap);
    EXPECT_TRUE(result); // invalid input, not {int 1/2, int 1/2.....}

    input.str("5");
    result = checkInput.checkHashFunctions(input, hashFunctionsMap);
    EXPECT_TRUE(result); // invalid input, not {int 1/2, int 1/2.....}
}