cmake_minimum_required(VERSION 3.29)
project(MPointer)

set(CMAKE_CXX_STANDARD 26)

add_library(MPointer STATIC MPointer.cpp MPointer.h
        MPointerCG.cpp
        MPointerGC.h)
target_include_directories(MPointer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

