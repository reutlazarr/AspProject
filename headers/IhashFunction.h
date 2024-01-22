// IHashFunction.h
#ifndef I_HASH_FUNCTION_H
#define I_HASH_FUNCTION_H

#include<string>


class IHashFunction {
public:
    // get string, and return size_t after hashing the string
    virtual size_t operator()(const std::string& str) const = 0;
};

#endif // I_HASH_FUNCTION_H
