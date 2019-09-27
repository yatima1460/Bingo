cmake_minimum_required(VERSION 3.5.1)

# Create project
project(BingoCLI)
set(CMAKE_CXX_STANDARD 17)
include_directories(Include)
file(GLOB SOURCES Source/*.cpp)
add_executable(BingoCLI ${SOURCES})

# Load BingoCore
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)
target_link_libraries(BingoCLI BingoCore)
