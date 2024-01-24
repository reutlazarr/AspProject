// BloomFilterManager.h

#include <map>
#include <vector>

#include "BloomFilter.h"
#include "IHashFunction.h"

class BloomFilterManager {

private:
    std::map<int, std::unique_ptr<IHashFunction>> hashFunctionMap;
    BloomFilter bloomFilter;

    int readArraySize(std::istream& input) const;
    std::vector<std::unique_ptr<IHashFunction>> readHashFunctions(std::istream& input,
                                                                  std::set<int>& uniqueHashFunctionIds) const;
    void handleHashFunctionId(int hashFunctionId, std::set<int>& uniqueHashFunctionIds,
                              std::vector<std::unique_ptr<IHashFunction>>& hashFunctions) const;

public:
    // constractor
    BloomFilterManager(std::map<int, std::unique_ptr<IHashFunction>> hashFunctionMap);
    BloomFilter createBloomFilter(); // create bloomFilter 

};