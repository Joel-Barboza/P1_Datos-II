cmake_minimum_required(VERSION 3.29)
# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp test2.cpp' are source files with tests
add_executable(Google_Tests_run MPtr_unittest.cpp test2.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main MPointer)
target_include_directories(Google_Tests_run PRIVATE ${CMAKE_SOURCE_DIR}/../MPointer)