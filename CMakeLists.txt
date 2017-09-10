cmake_minimum_required(VERSION 3.8)
project(variant)

set(CMAKE_CXX_STANDARD 17)

find_package (Boost)

set(SOURCE_FILES main.cpp)
add_executable(variant ${SOURCE_FILES})