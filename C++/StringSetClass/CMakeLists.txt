cmake_minimum_required(VERSION 3.22)
project(DocumentSimilarity)

set(CMAKE_CXX_STANDARD 14)

add_executable(DocumentSimilarity main.cpp StringSet.cpp StringSet.h)
