#include "../headers/hashFunction_1.h"

size_t HashFunction1::operator()(const std::string& str) const {
    return std::hash<std::string>{}(str);
}


