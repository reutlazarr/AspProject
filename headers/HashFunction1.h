// HashFunction1.h
#ifndef HASH_FUNCTION_1_H
#define HASH_FUNCTION_1_H

#include "IHashFunction.h"

class HashFunction_1 : public IHashFunction {
public:
    size_t operator()(const std::string& str) const override;
};

#endif // HASH_FUNCTION_1_H
