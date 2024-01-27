cmake_minimum_required(VERSION 3.14)
project("bloomFilter")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
googletest
URL
https://github.com/google/googletest/archive/03597a01ee50ed
33e9dfd640b249b4be3799d395.zip
DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

enable_testing()
set(SOURCE_FILES
    #src/calc.cpp # this is where the code we want to test
    /app/src/hashFunction1.cpp
    /app/src/hashFunction2.cpp
    /app/src/bloomFilter.cpp
    /app/src/addUrl.cpp
    /app/src/isBlackList.cpp
    /app/src/menu.cpp
    /app/src/bloomFilterManager.cpp
    /app/src/realBlackList.cpp
    /app/src/app.cpp
    /app/src/checkInput.cpp
)

set(TEST_FILES
    tests/test_main.cpp # this is the main for tests
    #tests/calc_test.cpp # this file contain the tests
    tests/bloomFilter_test.cpp # this file contain the tests
    tests/hashFunction_test.cpp # this file contain the tests
    tests/menu_test.cpp
    tests/bloomFilterManager_test.cpp
    tests/addUrl_test.cpp
    tests/isBlackList_test.cpp
    tests/app_test.cpp

)

add_executable(CalcTests ${TEST_FILES} ${SOURCE_FILES})

# Link Google Test to the test executable
target_link_libraries(CalcTests PRIVATE gtest gtest_main pthread)

# Include the source directory for tests
target_include_directories(CalcTests PRIVATE src)

include(GoogleTest)
add_test(NAME CalcTests COMMAND CalcTests)

# Explicitly link pthread at the end
target_link_libraries(CalcTests PRIVATE pthread)