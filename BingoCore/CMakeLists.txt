# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(BingoCore)

# creates the variable EXEC and sets it to hello
set(EXEC BingoCore)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 14)

# I../includes
include_directories(Include)

# puts all .cpp files inside Source to the SOURCES variable
file(GLOB SOURCES Source/*.cpp)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_library(${EXEC} ${SOURCES})