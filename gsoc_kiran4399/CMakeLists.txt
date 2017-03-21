cmake_minimum_required (VERSION 2.6)
project (test CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
add_executable(test source.cpp)