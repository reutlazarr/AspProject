#ifndef REAL_BLACK_LIST_H
#define REAL_BLACK_LIST_H
#include <string>
#include <vector>
#include <memory>

class RealBlackList {
    private:
    std::vector<std::string> realBlackList;

    public:
    // constractor
    RealBlackList(std::vector<std::string> realBlackList);
    // defaulte constractor
    RealBlackList();
    
    // getters
    std::vector<std::string>& getRealList();

     // Check if the given URL is in the real blacklist
    bool isUrlInBlackList(const std::string& url) const;
};
#endif // REAL_BLACK_LIST_H


