// HashFunction2.cpp

#include "../headers/HashFunction2.h"

// hash of HashFunction2
size_t HashFunction2::operator()(const std::string& str) const {
    // do double hashing
    size_t hash1 = std::hash<std::string>{}(str);
    return std::hash<std::string>{}(std::to_string(hash1));
}