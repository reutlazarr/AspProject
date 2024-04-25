#include <gtest/gtest.h>
#include "App.h"
#include "Menu.h"
#include "BloomFilterManager.h"
#include "BloomFilter.h"
#include "AddUrl.h"
#include "IsBlackList.h"
#include "ICommand.h"
#include <memory>
#include <map>

// Test the construction of the App class
TEST(AppTest, Constructor) {
    EXPECT_NO_THROW(App());
}

// Assuming setupServerSocket is now accessible
TEST(AppTest, ServerSetup) {
    App app;
    int invalidPort = -1; // Example of an invalid port
    EXPECT_EQ(app.setupServerSocket(invalidPort), -1);
    int validPort = 5555; // Assuming this is always valid in your tests
    EXPECT_GT(app.setupServerSocket(validPort), 0);
}

// Assuming initializeBloomFilter is accessible and refactored to be testable
TEST(AppTest, InitializeBloomFilter) {
    App app;
    int mockSocket = 123; // Dummy socket descriptor
    EXPECT_TRUE(app.initializeBloomFilter(mockSocket));
}
