// isBlackList.cpp

#include "IsBlackList.h"
#include "AddUrl.h"
#include <iostream>

std::string IsBlackList::execute(BloomFilter& bloomFilter, const std::string& url) {
    // // Loop over all the hashFunctions
    // std::string finalResult = "true";
    // for (auto& hashFunction : bloomFilter.getHashFunctions()) {
    //     size_t hashValue = (*hashFunction)(url); // do hash to url and get it's value
    //     // Divide the value by the size of bitArray and get index number  
    //     size_t index = hashValue % bloomFilter.getBitArray().size();
    //     // Check the number index in bloomFilter
    //     if (!(bloomFilter.getBitArray()[index])) {
    //         // If any corresponding bit is not set, it's definitely not blacklisted
    //         finalResult = "false";
    //         break;
    //     }
    // }

    // if (finalResult == "true") {
    //     // All corresponding bits are set, might be blacklisted
    //     bool compareResultsStr = compareResults(url, bloomFilter.getRealBlackListRef());

    //     // The final result: "true" + result from compareResults (true or false)
    //     finalResult = finalResult + " " + compareResultsStr;
    // }
    // //std::cout << finalResult << std::endl;
    // return finalResult;

    bool isMalicious = bloomFilter.contains(url);
    std::string finalResult = "in: ";
    if (isMalicious) {
        // All corresponding bits are set, might be blacklisted
        finalResult = finalResult + "true ";
        bool compareResultsStr = compareResults(url, bloomFilter.getRealBlackListRef());
        if (compareResultsStr) {
            finalResult = finalResult + "true";
            std::cout << finalResult << std::endl;
            return "true";
        }
        // // The final result: "true" + result from compareResults (true or false)
        // finalResult = finalResult + " " + compareResultsStr;
    }
    finalResult = finalResult + "false";
    std::cout << finalResult << std::endl;
    //return finalResult;
    return "false";
}


// Function to compare results between the realBlackList and the bloomFilter
bool IsBlackList::compareResults(const std::string& url, RealBlackList& realBlackListRef) {
    // Check in RealBlackList
    bool isInRealBlackList = realBlackListRef.isUrlInBlackList(url);
    // std::string resultString = isInRealBlackList ? "true" : "false";
    // return resultString;
    if (isInRealBlackList) {
        return true;
    }
    return false;
    //return bloomFilter.getRealBlackListRef().isUrlInBlackList(url) ? "true" : "false";
}



// // IsBlacklist class implementing ICommand interface
// // Check if the url is found in the bloomFilter
// std::string IsBlackList::execute(BloomFilter &bloomFilter, const std::string &url) {
//     // std::cout << bloomFilter.toString() << std::endl;
//     if (!bloomFilter.contains(url)) {
//         std::cout << "bloomfilter says it is false" << std::endl;
//         return "false";
//     }
//     return bloomFilter.getRealBlackListRef().isUrlInBlackList(url) ? "true" : "false";
// }
