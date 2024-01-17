#include <gtest/gtest.h>
#include "../tests/getters_bloom_filter_test.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
