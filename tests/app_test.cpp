#include <gtest/gtest.h>
#include "App.h"
#include "Menu.h"
#include "BloomFilterManager.h"
#include "BloomFilter.h"
#include "AddUrl.h"
#include "IsBlackList.h"
#include "ICommand.h"
#include <memory>
#include <map>

// Test the construction of the App class
TEST(AppTest, Constructor) {
    EXPECT_NO_THROW(App());
}

