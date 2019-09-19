cmake_minimum_required(VERSION 3.5.1)



project(BingoUI)

# set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

include_directories(Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)
file(GLOB SOURCES Source/*.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)


find_package(SDL2 REQUIRED)
include_directories(BingoUI ${SDL2_INCLUDE_DIRS})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SDL2TTF REQUIRED)
include_directories(BingoUI ${SDL2TTF_LIBRARY})
#[[set(SDL_STATIC ON)
add_subdirectory(Vendor/SDL2-2.0.10 ${CMAKE_CURRENT_BINARY_DIR}/SDL2-2.0.10)
add_subdirectory(Vendor/SDL2_ttf-2.0.15 ${CMAKE_CURRENT_BINARY_DIR}/SDL2_ttf-2.0.15)]]



link_libraries(BingoCore)
add_executable(BingoUI ${SOURCES})
target_link_libraries(BingoUI ${SDL2_LIBRARIES})
target_link_libraries(BingoUI ${SDL2TTF_LIBRARY})
#link_libraries(SDL2-static)



file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})