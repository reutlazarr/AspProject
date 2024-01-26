// menu_test.cpp

#include<gtest/gtest.h>
#include <sstream>
#include "../headers/Menu.h"

Menu menu;

 // tests for nextCommand in menu
TEST(MenuTest, NextCommand) {
    std::istringstream userInput("0\n"); // string simulates the user input
    std::streambuf* originalInput = std::cin.rdbuf(); // stores the original stream buffer of std::cin in a pointer
    std::cin.rdbuf(userInput.rdbuf()); // replaces the stream buffer of std::cin with the stream buffer of the user input stringstream

    std::stringstream output = menu.nextCommand(); // Assuming nextCommand returns a std::stringstream
    std::string outputContent = output.str();
    EXPECT_EQ(outputContent, "0");
    EXPECT_NE(outputContent, "1");

    std::cin.clear();
    std::cin.rdbuf(originalInput);
}

// tests for executeCommand in menu
TEST(MenuTest, ExecuteCommand) {
    std::stringstream input("1 example.com");
    auto command = menu.executeCommand(input);
    EXPECT_EQ(command.first, 1);
    EXPECT_EQ(command.second, "example.com");
}

// tests for executeCommandFailed in menu
TEST(MenuTest, ExecuteCommandFailed) {
    std::stringstream input1("example.com");
    EXPECT_THROW(menu.executeCommand(input1), std::invalid_argument);

    std::stringstream input2("1");
    EXPECT_THROW(menu.executeCommand(input2), std::invalid_argument);

    std::stringstream input3("");
    EXPECT_THROW(menu.executeCommand(input3), std::invalid_argument);
}

// tests for displayError in menu
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