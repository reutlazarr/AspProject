#include "../headers/IsBlacklist.h"
#include "../headers/AddUrl.h"
#include <iostream>

// Constructor
IsBlackList::IsBlackList(RealBlackList& initialList) : ICommand(initialList) {
}
// IsBlackList::IsBlackList(RealBlackList& initialList) : ICommand(initialList) {
// }

// IsBlacklist class implementing ICommand interface
// Check if the url is found in the bloomFilter
void IsBlackList::execute(BloomFilter& bloomFilter, const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
        // Divide the value by the size of bitArray and get index number  
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Check the number index in bloomFilter
        if (!(bloomFilter.getBitArray()[index])) {
            // If any corresponding bit is not set, it's definitely not blacklisted
            std::cout << "false";
            //execute over
        }
    }
    // All corresponding bits are set, might be blacklisted
    std::string firstResult = "true";
    std::string compareResultsStr = compareResults(url, bloomFilter);

    // The final result: "true" + result from compareResults (true/ false)
    std::string finalResult = firstResult + " "+ compareResultsStr;
    std::cout << finalResult;

}


// Function to compare results between the realBlackList and the bloomFilter
std::string IsBlackList::compareResults(const std::string& url, BloomFilter& bloomFilter) {
    // Check in RealBlackList
    bool isInRealBlackList = realBlackListRef.isUrlInBlackList(url);
    std::string resultString = isInRealBlackList ? "true" : "false";

    return resultString;

}