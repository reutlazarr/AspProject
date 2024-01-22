// HashFunction2.h
#ifndef HASH_FUNCTION_2_H
#define HASH_FUNCTION_2_H


#include "IHashFunction.h"

class HashFunction_2 : public IHashFunction {
public:
    size_t operator()(const std::string& str) const override;
};

#endif // HASH_FUNCTION_2_H