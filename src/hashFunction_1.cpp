#include "../headers/hashFunction_1.h"

size_t HashFunction1::operator()(const std::string& str) const {
    // do hash just once
    return std::hash<std::string>{}(str);
}


