#include "../headers/AddUrl.h"
#include <iostream>
 // Include the <algorithm> header for std::find
#include <algorithm> 

// Implementation of execute method
bool AddUrl::execute(BloomFilter& bloomFilter, const std::string& url) {
    // Loop over all the hashFunctions
    for (auto& hashFunction : bloomFilter.getHashFunctions()) {
        size_t hashValue = (*hashFunction)(url);
        size_t index = hashValue % bloomFilter.getBitArray().size();
        // Add url to bloomFilter by making the index number to true
        bloomFilter.getBitArray()[index] = true;
        std::cout << "the index that become 1 is: " << index << std::endl;
        std::cout << bloomFilter.getBitArray()[index]<< std::endl;
        return bloomFilter.getBitArray()[index];
    }

    return false;
}

// Add a new URL to the blacklist
void AddUrl::addUrlToRealList(std::vector<std::string>& blacklistedUrls, const std::string& url) {
    // Use std::find to check if the URL is already in the blacklist
    // Returns an iterator pointing to the first occurrence of the specified value in the range
    // or the end iterator if the value is not found.
    auto check = std::find(blacklistedUrls.begin(), blacklistedUrls.end(), url);
    // Check if the URL was not found
    if (check == blacklistedUrls.end()) {
        // URL is not in the blacklist, so add it
        blacklistedUrls.push_back(url);
        std::cout << "URL added to the blacklist: " << url << std::endl;
    } 
    else {
        // URL is already in the blacklist
        std::cout << "URL is already in the blacklist: " << url << std::endl;
    }
}