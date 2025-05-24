cmake_minimum_required(VERSION 3.31)
project(uneviedefourmi)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(anthill
        include/AntHillConfig.h
        include/ants.h
        include/menu.h
        source/AntHillConfig.cpp
        source/ants.cpp
        source/main.cpp
        source/menu.cpp)
