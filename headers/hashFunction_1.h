#include "IhashFunction.h"

class hashFunction_1 : public IHashFunction {
public:
    size_t operator()(const std::string& str) const;
};

