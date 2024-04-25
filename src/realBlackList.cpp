#include <string>
#include <vector>
#include "RealBlackList.h"
#include <algorithm>
#include <iostream>

// getters
std::vector<std::string> &RealBlackList::getRealList()
{
    return realBlackList;
}

bool RealBlackList::isUrlInBlackList(const std::string &url) const
{
    for (const std::string &item : realBlackList)
    {
        if (item == url)
        {
            return true;
        }
    }
    return false;
}
