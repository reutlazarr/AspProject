cmake_minimum_required(VERSION 3.14)
project(bloomFilter) 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add pthread to compile options globally (affects both executables)
add_compile_options(-pthread)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add your source and header directories here
include_directories(headers)

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

# Create executables
add_executable(CalcMain src/main.cpp ${SOURCE_FILES})
add_executable(CalcTests ${TEST_FILES} ${SOURCE_FILES})

# Link Google Test to the test executable
target_link_libraries(CalcMain PRIVATE pthread)
target_link_libraries(CalcTests PRIVATE gtest gtest_main pthread)

# Include the source directory for tests
target_include_directories(CalcTests PRIVATE src)

include(GoogleTest)
add_test(NAME CalcTests COMMAND CalcTests)
