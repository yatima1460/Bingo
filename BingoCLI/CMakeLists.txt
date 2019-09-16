# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(BingoCLI)

# creates the variable EXEC and sets it to hello
set(EXEC BingoCLI)

# set the C++14 standard
set(CMAKE_CXX_STANDARD 17)

# I../includes
include_directories(Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)


# puts all .cpp files inside Source to the SOURCES variable
file(GLOB SOURCES Source/*.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)

link_libraries(BingoCore)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})