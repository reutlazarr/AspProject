// menu_test.cpp

#include<gtest/gtest.h>
#include "../headers/Menu.h"

// tests for nextCommand in menu
TEST_F(MenuTest, NextCommand) {
    auto command = menu.nextCommand(); // check if the returned pair is as expected
    // // check if the returned pair is as expectedcheck if the returned command is not negative
    EXPECT_GE(command.first, 0);
}

// tests for displayError in menu
TEST_F(MenuTest, DisplayError) {
    testing::internal::CaptureStdout(); // redirect cout to a stringstream to capture the printed output
    menu.displayEror("Test Error Message"); // call the displayError function with a test message
    std::string output = testing::internal::GetCapturedStdout(); // get the printed output
    // check if the printed output contains the expected error message
    EXPECT_NE(output.find("Error: Test Error Message"), std::string::npos);
}