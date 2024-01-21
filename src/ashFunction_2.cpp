#include "../headers/hashFunction_2.h"

size_t HashFunction2::operator()(const std::string& str) const {
    // do double hashing
    size_t hash1 = std::hash<std::string>{}(str);
    return hash2 = std::hash<std::string>{}(std::to_string(hash1));
}