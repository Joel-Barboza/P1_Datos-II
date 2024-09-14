cmake_minimum_required(VERSION 3.29)
project(Google_tests)

# Add Google Test subdirectory
add_subdirectory(lib/googletest)

# Include Google Test headers
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Define the test executable
add_executable(Google_Tests_run MPtr_unittest.cpp MPtrGC_unittest.cpp)

# Link Google Test libraries and your own MPointer library
target_link_libraries(Google_Tests_run gtest gtest_main MPointer)

# Include directories for your own library
target_include_directories(Google_Tests_run PRIVATE ${CMAKE_SOURCE_DIR}/../MPointer)

# Add test to CTest
add_test(NAME Google_Tests_run COMMAND Google_Tests_run)
