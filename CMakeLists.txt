cmake_minimum_required(VERSION 3.21)
project(OSdispatch)

set(CMAKE_CXX_STANDARD 14)

add_executable(OSdispatch main.cpp common/utils.h common/utils.cpp)
