#include "../headers/hashFunction.h"

size_t HashFunction::operator()(const std::string& str) const {
    return std::hash<std::string>{}(str);
}


