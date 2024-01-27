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

// TEST(AppTest, ConstructorTest) {
//     // Arrange
//     Menu menu;
//     std::map<int, std::unique_ptr<ICommand>> commands;
//     RealBlackList realBlackList;
//     commands[1] = std::make_unique<AddUrl>(realBlackList);
//     const auto& commandsTest = commands;
//     std::map<int, std::unique_ptr<IHashFunction>> hashFunctions;
//     hashFunctions[1] = std::make_unique<HashFunction1>();
//     const auto& hashFunctionsTest = commands;

//     App app(menu, std::move(commands), std::move(hashFunctions));

//     EXPECT_EQ(commandsTest.size(), app.getCommands().size());
//     EXPECT_EQ(hashFunctionsTest.size(), app.getHashFunctions().size());
// }

// TEST(AppTest, CommandMapInitialization) {
//     App app;
//     Menu menu;
//     std::map<int, std::unique_ptr<ICommand>> commands;
//     app.setCommands();
//     auto commands = app.getCommands(); // This requires a getter in App
//     EXPECT_TRUE(commands.find(1) != commands.end());
//     EXPECT_TRUE(commands.find(2) != commands.end());
//     // Further, you can check if the commands are of the expected type
// }

// TEST(AppTest, RunValidCommand) {
//     MockMenu mockMenu; // You need to create a mock version of Menu
//     MockBloomFilterManager mockManager; // Mock version of BloomFilterManager
//     App app(mockMenu, mockManager); // Adjust constructor for dependency injection
//     EXPECT_CALL(mockMenu, nextCommand()).WillOnce(Return(/* Mocked valid command */));
//     EXPECT_NO_THROW(app.run());
// }
// TEST(AppTest, CommandMapInitialization) {
//     App app;
//     app.setCommands();
//     auto& commands = app.getCommands(); // This requires a getter in App
//     EXPECT_NE(commands.find(1), commands.end());
//     EXPECT_NE(commands.find(2), commands.end());
// }
