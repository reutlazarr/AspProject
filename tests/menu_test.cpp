 // menu_test.cpp

#include <gtest/gtest.h>
#include <sstream>
#include "Menu.h"
#include "CheckInput.h"

Menu menu;

// Tests for nextCommand in menu
TEST(MenuTest, NextCommand) {
    std::istringstream userInput("0\n"); // String simulates the user input
    std::streambuf* originalInput = std::cin.rdbuf(); // Stores the original stream buffer of std::cin in a pointer
    std::cin.rdbuf(userInput.rdbuf()); // Replaces the stream buffer of std::cin with the stream buffer of the user input stringstream

    std::stringstream output = menu.nextCommand(); // Assuming nextCommand returns a std::stringstream
    std::string outputContent = output.str();
    EXPECT_EQ(outputContent, "0");
    EXPECT_NE(outputContent, "1");

    std::cin.clear();
    std::cin.rdbuf(originalInput); // Restoring the original stream buffer
}

// Tests for executeCommand in menu
TEST(MenuTest, ExecuteCommand) {
    std::stringstream input("1 example.com");
    auto command = menu.executeCommand(input);
    EXPECT_EQ(command.first, 1);
    EXPECT_EQ(command.second, "example.com");
}

// Tests for executeCommandFailed in menu
TEST(MenuTest, ExecuteCommandFailed) {
    std::stringstream input1("example.com");
    auto command1 = menu.executeCommand(input1);
    EXPECT_EQ(command1.first, -1); // Checking for -1 indicating invalid input

    std::stringstream input2("1");
    auto command2 = menu.executeCommand(input2);
    EXPECT_EQ(command2.first, -1); // Invalid input as URL is missing

    std::stringstream input3("");
    auto command3 = menu.executeCommand(input3);
    EXPECT_EQ(command3.first, -1); // Empty input
}

// Tests for displayError in menu
TEST(MenuTest, DisplayError) {
    std::stringstream errorStream;
    // Redirect std::cerr to a stringstream
    std::streambuf* originalCerrBuffer = std::cerr.rdbuf(errorStream.rdbuf()); 
    // Call the function that writes to std::cerr
    menu.displayError("Test error message");
    // Restore the original std::cerr
    std::cerr.rdbuf(originalCerrBuffer);
    EXPECT_EQ(errorStream.str(), "Test error message\n");
}
