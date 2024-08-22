cmake_minimum_required(VERSION 3.29)
project(MPointer)

set(CMAKE_CXX_STANDARD 26)

add_library(MPointer STATIC MPointer.cpp MPointer.h
        ../Google_tests/test1.cpp
        ../Google_tests/test1.h
        ../Google_tests/test2.cpp
        ../Google_tests/test2.h)
target_include_directories(MPointer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

