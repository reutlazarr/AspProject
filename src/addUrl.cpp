// addUrl.cpp

#include "AddUrl.h"
#include "RealBlackList.h"
#include "BloomFilter.h"
#include <iostream>
#include <algorithm> 

// Implementation of execute method of ICommand
// Add Url to the BloomFilter and to the black list
void AddUrl::execute(BloomFilter& bloomFilter, const std::string& url) {
    addUrlToRealList(url, bloomFilter.getRealBlackListRef());
    // Loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url);
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Add url to bloomFilter by making the index number to true
        bloomFilter.getBitArray()[index] = true;
    }

}


// Add a new URL to the real black list
void AddUrl::addUrlToRealList(const std::string& url, RealBlackList& realBlackListRef) {
    // Use std::find to check if the URL is already in the blacklist
    auto check = std::find(realBlackListRef.getRealList().begin(), realBlackListRef.getRealList().end(), url);

    // Check if the URL was not found
    if (check == realBlackListRef.getRealList().end()) {
        // URL is not in the blacklist, so add it
        realBlackListRef.getRealList().push_back(url); //URL added to the blacklist
    } else {
        // URL is already in the blacklist
    }
}
