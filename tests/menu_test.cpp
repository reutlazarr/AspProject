// menu_test.cpp

#include<gtest/gtest.h>
#include "../headers/Menu.h"

Menu menu;
// tests for displayError in menu
TEST(MenuTest, DisplayError) {
    testing::internal::CaptureStdout();  // Capture stdout
    testing::internal::CaptureStderr();  // Capture stderr
    menu.displayError("Test Error Message"); // call the displayError function with a test message
    std::string stdout_output = testing::internal::GetCapturedStdout();  // Get captured stdout
    std::string stderr_output = testing::internal::GetCapturedStderr();  // Get captured stderr
    std::cout << "Actual stdout: " << stdout_output << std::endl;  // Print actual stdout for debugging
    std::cout << "Actual stderr: " << stderr_output << std::endl;  // Print actual stderr for debugging
    // check if the printed output contains the expected error message
    EXPECT_TRUE(stderr_output.find("Error: Test Error Message") != std::string::npos);
}

// tests for nextCommand in menu
TEST(MenuTest, NextCommand) {
    auto command = menu.nextCommand(); // check if the returned pair is as expected
    // check if the returned pair is as expectedcheck if the returned command is not negative
    EXPECT_GE(command.first, 0);
}