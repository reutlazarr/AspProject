// bloomFilterManager.cpp

#include "../headers/BloomFilterManager.h"
#include "../headers/Menu.h"
#include "../headers/BloomFilter.h"
#include "../headers/IHashFunction.h"
#include "../headers/CheckInput.h"

#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>

// constractor
BloomFilterManager::BloomFilterManager(Menu menu, std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap) : menu(menu), hashFunctionsMap(std::move(hashFunctionsMap)) {}

// create bloomFilter
BloomFilter BloomFilterManager::createBloomFilter() {
    CheckInput checkInput;
    while (true) {
        try {
            // read the first line of input
            std::string line;
            //std::cout << "Enter array size and hash function IDs: ";
            std::getline(std::cin, line);
            std::stringstream firstInput(line); // e.g first input = 8 1 2
            std::stringstream inputCopy(firstInput.str()); // copy std::stringstream

            if (checkInput.checkArraySize(inputCopy)) {
                throw std::invalid_argument("Invalid array size.");
            }
            int arraySize = readArraySize(firstInput);

            std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
            if (checkInput.checkHashFunctions(inputCopy, hashFunctionsMap)) {
                throw std::invalid_argument("Invalid hash functions.");
            }
            std::set<int> uniqueHashFunctionIds; // create a set to keep track of unique hash function IDs
            hashFunctions = readHashFunctions(firstInput, uniqueHashFunctionIds);
            
            if (!hashFunctions.empty()) {
                // Create BloomFilter
                return BloomFilter(arraySize, std::move(hashFunctions));
            }

        } catch (const std::invalid_argument& ex) {
                menu.displayError("Error: " + std::string(ex.what()));
        }
    }
}

// read and validate the array size
int BloomFilterManager::readArraySize(std::istream& input) const {
    int arraySize;
    input >> arraySize;
    return arraySize;
}

// read and validate the hash functions
std::vector<std::unique_ptr<IHashFunction>> BloomFilterManager::readHashFunctions(std::istream& input, std::set<int>& uniqueHashFunctionIds) const {
    std::vector<std::unique_ptr<IHashFunction>> hashFunctions;
    int hashFunctionId;
    while (input >> hashFunctionId) { // read hash function IDs
        handleHashFunctionId(hashFunctionId, uniqueHashFunctionIds, hashFunctions);
    }
    //if (input.eof()) { // Check for the end-of-file condition
    //    continue;
    //}
    return hashFunctions;
}

// validate the HashFunctionId and handle it
void BloomFilterManager::handleHashFunctionId(int hashFunctionId, std::set<int>& uniqueHashFunctionIds, std::vector<std::unique_ptr<IHashFunction>>& hashFunctions) const {
    auto it = hashFunctionsMap.find(hashFunctionId);
    // existing hash function ID found in the map
    if (it != hashFunctionsMap.end()) {        
        // unique hash function ID will add to the vector
        if (uniqueHashFunctionIds.insert(hashFunctionId).second) {
            auto clonedHashFunction = it->second->clone(); // create a new instance
            hashFunctions.push_back(std::move(clonedHashFunction)); // store the unique_ptr in the vector
        }
    }
}