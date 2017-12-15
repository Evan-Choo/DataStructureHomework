cmake_minimum_required(VERSION 3.8)
project(Task6)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MinimumHeap.cpp MinimumHeap.h Node.cpp Node.h)
add_executable(Task6 ${SOURCE_FILES})