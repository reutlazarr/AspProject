// initialize_test.cpp

#include <gtest/gtest.h>
#include "../headers/Initialize.h"
#include "../headers/IHashFunction.h"
#include "../headers/ICommand.h"
#include "../headers/Menu.h"

// tests for initialize
TEST(Initialize, SeeterInitialized) {
    Initialize initialize;
    // test the setters
    EXPECT_FALSE(initialize.getCommands().empty());
    EXPECT_FALSE(initialize.getHashFunctions().empty());
    EXPECT_NE(&initialize.getMenu(), nullptr);

    // test initializeCommands
    const auto& commands = initialize.getCommands();
    EXPECT_EQ(commands.size(), 2);
    EXPECT_TRUE(commands.count(1) != 0);
    EXPECT_TRUE(commands.count(2) != 0);

    // test initializeHashFunctions
    const auto& hashFunctions = initialize.getHashFunctions();
    EXPECT_EQ(hashFunctions.size(), 2);
    EXPECT_TRUE(hashFunctions.count(1) != 0);
    EXPECT_TRUE(hashFunctions.count(2) != 0);
}
