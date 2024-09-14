cmake_minimum_required(VERSION 3.29)
project(MPtrSorting)

set(CMAKE_CXX_STANDARD 26)

add_executable(MPtrSorting main.cpp
        DoublyLinkedList.h
        BubbleSort.h
        QuickSort.h
        InsertionSort.h
)

target_link_libraries(MPtrSorting PRIVATE MPointer)

target_include_directories(MPtrSorting PRIVATE ${CMAKE_SOURCE_DIR}/../MPointer)



