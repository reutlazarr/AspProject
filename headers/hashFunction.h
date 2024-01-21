
#ifndef HASHFUNCTION_H
#define HASHFUNCTION_H


#include<functional>
#include<string>


class HashFunction {
public:
    size_t operator()(const std::string& str) const;
};



#endif // HASHFUNCTION_H