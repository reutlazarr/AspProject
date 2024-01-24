#include <string>
#include <vector>
#include "../headers/RealBlackList.h"

// constractor
RealBlackList::RealBlackList(std::vector<std::string> initialList) : realBlackList(initialList) {}

// getters
std::vector<std::string>& RealBlackList::getRealList() {
    return realBlackList;
}