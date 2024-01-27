cmake_minimum_required(VERSION 3.14)
project("bloomFilter")

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch and make GoogleTest available
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Define source and test files
set(SOURCE_FILES
    src/hashFunction1.cpp
    src/hashFunction2.cpp
    src/bloomFilter.cpp
    src/addUrl.cpp
    src/isBlackList.cpp
    src/menu.cpp
    src/bloomFilterManager.cpp
    src/realBlackList.cpp
    src/app.cpp
    src/checkInput.cpp
)

set(TEST_FILES
    tests/test_main.cpp
    tests/bloomFilter_test.cpp
    tests/hashFunction_test.cpp
    tests/menu_test.cpp
    tests/bloomFilterManager_test.cpp
    tests/addUrl_test.cpp
    tests/isBlackList_test.cpp
    tests/app_test.cpp
)

# Create test executable
add_executable(CalcTests ${TEST_FILES} ${SOURCE_FILES})

# Link GoogleTest and pthread libraries
target_link_libraries(CalcTests PRIVATE gtest gtest_main pthread)

# Include directories
target_include_directories(CalcTests PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Discover and register tests
include(GoogleTest)
gtest_discover_tests(CalcTests)
