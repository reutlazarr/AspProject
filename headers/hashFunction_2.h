#include "IhashFunction.h"

class hashFunction_2 : public IHashFunction {
public:
    size_t operator()(const std::string& str) const;
};