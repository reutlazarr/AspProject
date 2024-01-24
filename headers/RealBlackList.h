#include <string>
#include <vector>

class RealBlackList {
    private:
    std::vector<std::string> realBlackList;

    public:
    // constractor
    RealBlackList(std::vector<std::string> realBlackList);
    // getters
    std::vector<std::string>& getRealList();
};

