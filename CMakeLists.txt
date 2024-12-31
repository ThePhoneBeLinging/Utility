cmake_minimum_required(VERSION 3.25)
project(Utility)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

add_library(Utility STATIC
        src/Utility.cpp
        src/include/Utility/Utility.h
        src/Timer.cpp
        src/include/Utility/Timer.h
        src/TimeUtil.cpp
        src/include/Utility/TimeUtil.h
        src/ConfigController.cpp
        src/include/Utility/ConfigController.h
)

target_include_directories(Utility PUBLIC src/include)
target_include_directories(Utility PUBLIC src)
target_link_libraries(Utility PRIVATE nlohmann_json)