// HashFunction1.h

#ifndef HASH_FUNCTION_1_H
#define HASH_FUNCTION_1_H

#include "IHashFunction.h"
#include <memory>

// header for HashFunction1
class HashFunction1 : public IHashFunction {
public:
    // get string,
    // return size_t after hashing the string
    size_t operator()(const std::string& str) const override;
    // clone the object
    std::unique_ptr<IHashFunction> clone() const override;
};

#endif // HASH_FUNCTION_1_H
