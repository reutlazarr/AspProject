 // menu_test.cpp

#include <gtest/gtest.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include "Menu.h"
#include "CheckInput.h"

Menu menu;

// Helper function to create a pair of connected sockets
bool setupTestSockets(int &serverSock, int &clientSock) {
    int sockets[2];
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) != 0) {
        return false; // Failed to create a pair of sockets
    }
    serverSock = sockets[0];
    clientSock = sockets[1];
    return true;
}

// Tests for nextCommand in menu
TEST(MenuTest, NextCommand_ReceivesDataCorrectly) {
    int serverSock, clientSock;
    ASSERT_TRUE(setupTestSockets(serverSock, clientSock));

    Menu menu;
    const char* testData = "test data";
    write(serverSock, testData, strlen(testData)); // Write test data to one end of the socket

    std::stringstream output = menu.nextCommand(clientSock);
    std::string outputContent = output.str();
    EXPECT_EQ(outputContent, "test data"); // Check if the received data matches the sent data

    // Clean up
    close(serverSock);
    close(clientSock);
}

TEST(MenuTest, NextCommand_HandlesEmptyData) {
    int serverSock, clientSock;
    ASSERT_TRUE(setupTestSockets(serverSock, clientSock));

    Menu menu;
    close(serverSock); // Close the sending end of the socket to simulate a disconnection

    std::stringstream output = menu.nextCommand(clientSock);
    std::string outputContent = output.str();
    EXPECT_TRUE(outputContent.empty()); // Check if output is empty as expected when disconnected

    close(clientSock);
}

TEST(MenuTest, NextCommand_HandlesPartialData) {
    int serverSock, clientSock;
    ASSERT_TRUE(setupTestSockets(serverSock, clientSock));

    Menu menu;
    const char* testData = "partial data";
    write(serverSock, testData, 7); // Write only part of the data to simulate partial data transmission

    std::stringstream output = menu.nextCommand(clientSock);
    std::string outputContent = output.str();
    EXPECT_EQ(outputContent, std::string(testData, 7)); // Check if the received data matches the sent partial data

    close(serverSock);
    close(clientSock);
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
    EXPECT_EQ(command2.first, -1); // Invalid input,  as URL is missing

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
