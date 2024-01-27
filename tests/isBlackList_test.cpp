#include <gtest/gtest.h>
#include "../headers/IsBlackList.h"
#include "../headers/RealBlackList.h"
#include "../headers/AddUrl.h"

// Define a test case named CheckUrlNotInBlackList in the IsBlackListTest test suite
TEST(IsBlackListTest, CheckUrlNotInBlackList) {
    // Create a vector to hold unique pointers to IHashFunction objects
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    // Initialize a BloomFilter object with 100 slots and the hash function vector
    BloomFilter bloomFilter(100, std::move(hashFunctions));

    // Define a URL which is supposed to not be in the blacklist
    std::string urlToCheck = "http://notblacklisted.com";

    // Create a stringstream buffer to capture the output
    std::stringstream buffer;
    // Save the current buffer of std::cout
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Create an IsBlackList object and execute its main functionality
    IsBlackList isBlackListCommand;
    isBlackListCommand.execute(bloomFilter, urlToCheck);

    // Restore the original buffer of std::cout
    std::cout.rdbuf(prevcoutbuf);

    // Convert the contents of the buffer to a string
    std::string result = buffer.str();
    // If the last character of the result is a newline, remove it
    if (!result.empty() && result[result.size() - 1] == '\n') {
        result.erase(result.size() - 1);
    }

    // Check if the last 5 characters of the result are "false"
    // This is the expected outcome indicating the URL is not in the blacklist
    EXPECT_EQ(result.substr(result.size() - 5), "false") << "Actual output: " << result;
}

