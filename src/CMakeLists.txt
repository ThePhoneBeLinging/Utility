cmake_minimum_required(VERSION 3.28)
project(Utility)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(Utility STATIC
        Utility.cpp
        include/Utility/Utility.h
        Timer.cpp
        include/Utility/Timer.h
)

target_include_directories(Utility PUBLIC src/include)
target_include_directories(Utility PUBLIC src)