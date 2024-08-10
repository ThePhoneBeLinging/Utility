cmake_minimum_required(VERSION 3.28)
project(Utility)

set(CMAKE_CXX_STANDARD 26)

add_library(Utility STATIC
        src/Utility.cpp
        src/include/Utility.h)

target_include_directories(Utility PUBLIC src/include)
target_include_directories(Utility PUBLIC src)