#include<string>
#include<functional>

class HashFunction {
    size_t operator()(const std::string& str) const;
};