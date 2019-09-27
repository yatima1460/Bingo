cmake_minimum_required(VERSION 3.5.1)

# Create project
project(BingoCore)
set(CMAKE_CXX_STANDARD 17)
include_directories(Include)
file(GLOB_RECURSE SOURCES Source/*.cpp)
add_library(BingoCore ${SOURCES})



