cmake_minimum_required(VERSION 3.5.1)
project(BingoUI)

set(EXEC BingoUI)

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

include_directories(Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)
file(GLOB SOURCES Source/*.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)
set(SDL_STATIC ON)
add_subdirectory(Vendor/SDL2-2.0.10 ${CMAKE_CURRENT_BINARY_DIR}/SDL2-2.0.10)
add_subdirectory(Vendor/SDL2_ttf-2.0.15 ${CMAKE_CURRENT_BINARY_DIR}/SDL2_ttf-2.0.15)

link_libraries(BingoCore)
link_libraries(SDL2-static)

add_executable(${EXEC} ${SOURCES})

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})