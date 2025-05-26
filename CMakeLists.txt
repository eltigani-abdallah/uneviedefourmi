cmake_minimum_required(VERSION 3.31)
project(uneviedefourmi)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(uneviedefourmi
        colony.cpp
        colony.hpp
        room.cpp
        room.hpp
        testyboi.cpp
        errcodes.h
        algo.cpp
        algo.h)
