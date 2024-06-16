cmake_minimum_required(VERSION 2.8)

project(mysort)

set(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")

add_executable(mysort mysort.cpp)

