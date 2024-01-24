// HashFunction1.cpp

#include "../headers/HashFunction1.h"

// hash of HashFunction1
size_t HashFunction1::operator()(const std::string& str) const {
    // do hash only once
    return std::hash<std::string>{}(str);
}

// clone the object
std::unique_ptr<IHashFunction> HashFunction1::clone() const {
    return std::make_unique<HashFunction1>(*this);
}


