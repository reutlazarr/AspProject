// HashFunction2.h

#ifndef HASH_FUNCTION_2_H
#define HASH_FUNCTION_2_H

#include "IHashFunction.h"

// header for HashFunction2
class HashFunction2 : public IHashFunction {
public:
    // get string,
    // return size_t after hashing the string
    size_t operator()(const std::string& str) const override;
};

#endif // HASH_FUNCTION_2_H
