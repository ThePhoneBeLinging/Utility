cmake_minimum_required(VERSION 3.25)
project(Utility)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_library(Utility STATIC
        src/Utility.cpp
        src/include/Utility/Utility.h
        src/Timer.cpp
        src/include/Utility/Timer.h
        src/TimeUtil.cpp
        src/include/Utility/TimeUtil.h
)

target_include_directories(Utility PUBLIC src/include)
target_include_directories(Utility PUBLIC src)