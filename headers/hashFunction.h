#include<string>
#include<functional>

class HashFunction {
public:
    size_t hash(const std::string& url) const;
};