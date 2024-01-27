// app_test.cpp

#include <gtest/gtest.h>
#include "App.h"
#include "Menu.h"
#include "BloomFilterManager.h"
#include "HashFunction1.h"
#include "HashFunction2.h"
#include <memory>
#include <map>

// Test the construction of the App class
TEST(AppTest, Constructor) {
    Menu menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions[1] = std::make_unique<HashFunction1>();
    hashFunctions[2] = std::make_unique<HashFunction2>();
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctions));

    EXPECT_NO_THROW(App(menu, bloomFilterManager));
}

// Test the run method of the App class
// Note: The actual behavior of run depends on user input, which is not tested here
TEST(AppTest, RunMethod) {
    Menu menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions[1] = std::make_unique<HashFunction1>();
    hashFunctions[2] = std::make_unique<HashFunction2>();
    BloomFilterManager bloomFilterManager(menu, std::move(hashFunctions));
    App app(menu, bloomFilterManager);

    // Assuming run method doesn't return a value and just starts the application loop
    // Testing actual behavior might require more complex setup or refactoring of the App class
    EXPECT_NO_THROW(app.run());
}

// Additional tests can be added here as needed
