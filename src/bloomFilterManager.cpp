// bloomFilterManager.cpp

#include "../headers/BloomFilterManager.h"
#include "../headers/Menu.h"
#include "../headers/BloomFilter.h"
#include "../headers/IHashFunction.h"

#include<limits>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <stdexcept>
#include <iostream>

// constractor
BloomFilterManager::BloomFilterManager(Menu* menu, std::map<int, std::unique_ptr<IHashFunction>> hashFunctionMap) : menu(menu), hashFunctionMap(std::move(hashFunctionMap)) {}

// create bloomFilter
BloomFilter BloomFilterManager::createBloomFilter() {
    std::cout << "inside createBloomFilter" << std::endl;
    while (true) {
        try {
            std::cout << "inside try" << std::endl;
            // read the first line of input
            std::string line;
            std::cout << "Enter array size and hash function IDs: ";
            std::getline(std::cin, line);
            std::stringstream firstInput(line); // e.g first input = 8 1 2
            std::cout << "get output" << std::endl;
            int arraySize = readArraySize(firstInput);
            std::set<int> uniqueHashFunctionIds; // create a set to keep track of unique hash function IDs
            std::vector<std::unique_ptr<IHashFunction>> hashFunctions = readHashFunctions(firstInput, uniqueHashFunctionIds);
            
            if (!hashFunctions.empty()) {
                std::cout << "Create BloomFilter" << std::endl;
                // Create BloomFilter
                return BloomFilter(arraySize, std::move(hashFunctions));
            }

        } catch (const std::invalid_argument& ex) {
            std::cout << "inside catch" << std::endl;
            menu->displayError("Error: " + std::string(ex.what()));
            //firstInput.clear();  // Clear the fail state
            //firstInput.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            //hashFunctions.clear();
            //uniqueHashFunctionIds.clear();
        }
    }
}

// read and validate the array size
int BloomFilterManager::readArraySize(std::istream& input) const {
    std::cout << "inside readArraySize" << std::endl;
    int arraySize;
    input >> arraySize;
    if (input.fail() || arraySize <= 0) { // when the extraction of arraySize fails
        throw std::invalid_argument("Invalid array size.");
    }
    return arraySize;
}

// read and validate the hash functions
std::vector<std::unique_ptr<IHashFunction>> BloomFilterManager::readHashFunctions(std::istream& input, std::set<int>& uniqueHashFunctionIds) const {
    std::cout << "inside readHashFunctions" << std::endl;
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    int hashFunctionId;
    while (input >> hashFunctionId) { // read hash function IDs
        std::cout << "inside loooop" << std::endl;
        handleHashFunctionId(hashFunctionId, uniqueHashFunctionIds, hashFunctions);
    }
    if (input.eof()) { // Check for the end-of-file condition
        std::cout << "End of file reached." << std::endl;
        return hashFunctions;
    }
    if (input.fail()) { // when the extraction of hashFunctionId fails
        throw std::invalid_argument("Invalid input for hash function IDs.");
    }
}

// validate the HashFunctionId and handle it
void BloomFilterManager::handleHashFunctionId(int hashFunctionId, std::set<int>& uniqueHashFunctionIds, std::vector<std::unique_ptr<IHashFunction>>& hashFunctions) const {
    std::cout << "inside readHashFunctions" << std::endl;
    auto it = hashFunctionMap.find(hashFunctionId);
    // existing hash function ID found in the map
    if (it != hashFunctionMap.end()) {
        // unique hash function ID will add to the vector
        if (uniqueHashFunctionIds.insert(hashFunctionId).second) {
            auto clonedHashFunction = it->second->clone(); // create a new instance
            hashFunctions.push_back(std::move(clonedHashFunction)); // store the unique_ptr in the vector
        }
    } else { // hash function ID not found in the map
        throw std::invalid_argument("Invalid hash function ID.");
    }
}
