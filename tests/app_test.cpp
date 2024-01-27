//app_test.cpp

#include <gtest/gtest.h>
#include "App.h"
#include "Menu.h"
#include "ICommand.h"
#include "IHashFunction.h"
#include "HashFunction1.h"
#include "RealBlackList.h"
#include "AddUrl.h"
#include <map>
#include<memory>

TEST(AppTest, ConstructorTest) {
    // Arrange
    Menu menu;
    std::map<int, std::unique_ptr<ICommand>> commands;
    RealBlackList realBlackList;
    commands[1] = std::make_unique<AddUrl>(realBlackList);
    const auto& commandsTest = commands;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
    hashFunctions[1] = std::make_unique<HashFunction1>();
    const auto& hashFunctionsTest = commands;

    App app(menu, std::move(commands), std::move(hashFunctions));

    EXPECT_EQ(commandsTest.size(), app.getCommands().size());
    EXPECT_EQ(hashFunctionsTest.size(), app.getHashFunctions().size());
}