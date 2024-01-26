// BloomFilterManager.h

#ifndef BLOOMFILTERMANAGER_H
#define BLOOMFILTERMANAGER_H

#include <map>
#include <vector>
#include <set>
#include <memory>
#include <sstream>
#include "Menu.h"
#include "IHashFunction.h"
#include "BloomFilter.h"

class BloomFilterManager {

private:
    Menu& menu;
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap;
    //BloomFilter bloomFilter;

    int readArraySize(std::istream& input) const;
    std::vector<std::unique_ptr<IHashFunction>> readHashFunctions(std::istream& input,
                                                                  std::set<int>& uniqueHashFunctionIds) const;
    void handleHashFunctionId(int hashFunctionId, std::set<int>& uniqueHashFunctionIds,
                              std::vector<std::unique_ptr<IHashFunction>>& hashFunctions) const;

public:
    // constractor
    BloomFilterManager(Menu& menu, std::map<int, std::unique_ptr<IHashFunction>> hashFunctionsMap);
    BloomFilter createBloomFilter(); // create bloomFilter 
};

#endif // BLOOMFILTERMANAGER_H