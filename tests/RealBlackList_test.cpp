#include <gtest/gtest.h>
#include "../headers/RealBlackList.h"
#include "../headers/AddUrl.h"

TEST(RealBlackListTest, AddUrlCommand) {
    RealBlackList realBlackList({"www.example.com0"});
    AddUrl addUrlCommand(realBlackList);
    addUrlCommand.addUrlToRealList(realBlackList, "www.example.com000");
    std::size_t listSize = realBlackList.getRealList().size();
    EXPECT_EQ(listSize, 2);
    EXPECT_TRUE(realBlackList.isUrlInBlackList("www.example.com0"));

    //EXPECT_EQ()

}