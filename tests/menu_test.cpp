// menu_test.cpp

#include<gtest/gtest.h>
#include <sstream>
#include "../headers/Menu.h"

Menu menu;
// tests for nextCommand in menu
//TEST(MenuTest, NextCommand) {
 //  std::stringstream input = menu.nextCommand();
 //   std::string inputContent = input.str();
 //   EXPECT_EQ(inputContent, "0");
//}

// tests for executeCommand in menu
TEST(MenuTest, ExecuteCommand) {
    std::stringstream input("1 example.com");
    auto command = menu.executeCommand(input);
    EXPECT_EQ(command.first, 1);
    EXPECT_EQ(command.second, "example.com");
}

TEST(MenuTest, ExecuteCommandFailed) {
    std::stringstream input("example.com");
    EXPECT_THROW({
        auto command = menu.executeCommand(input);
    }, std::invalid_argument);
}

// tests for displayError in menu
TEST(MenuTest, DisplayError) {
    std::stringstream input("example.com");
    // Use EXPECT_THROW to check if executeCommand throws an exception
    EXPECT_THROW(menu.executeCommand(input), std::invalid_argument);
}