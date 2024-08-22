cmake_minimum_required(VERSION 3.29)
project(MyProject)

set(CMAKE_CXX_STANDARD 26)

# Add subdirectories for the library and executable
add_subdirectory(MPointer)
add_subdirectory(MPtrSorting)
add_subdirectory(Google_tests)
