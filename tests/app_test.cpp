//app_test.cpp

#include <gtest/gtest.h>
#include "../headers/App.h"
#include "../headers/Menu.h"
#include "../headers/ICommand.h"
#include "../headers/IHashFunction.h"
#include "../headers/HashFunction1.h"
#include "../headers/RealBlackList.h"
#include "../headers/AddUrl.h"
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

