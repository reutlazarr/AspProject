#include "../headers/HashFunction1.h"

size_t HashFunction1::operator()(const std::string& str) const override {
    // do hash just once
    return std::hash<std::string>{}(str);
}


