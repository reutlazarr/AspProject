#include <string>
#include <vector>
#include "../headers/RealBlackList.h"
#include <algorithm> 


// constractor
RealBlackList::RealBlackList(std::vector<std::string> realBlackList) : realBlackList(realBlackList) {}

// getters
std::vector<std::string>& RealBlackList::getRealList() {
    return realBlackList;
}

bool RealBlackList::isUrlInBlackList(const std::string& url) const {
    // Use std::find to check if the URL is in the real blacklist
    auto check = std::find(realBlackList.begin(), realBlackList.end(), url);
    
    // Return true if the URL is found, false otherwise
    return check != realBlackList.end();
}  