cmake_minimum_required(VERSION 3.22)
project(EAVector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(EAVector
        EAVector.h
        main.cpp)
