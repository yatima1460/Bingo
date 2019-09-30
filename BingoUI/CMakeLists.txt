cmake_minimum_required(VERSION 3.5.1)


# Create project
project(BingoUI)
set(CMAKE_CXX_STANDARD 17)
include_directories(Include)
file(GLOB_RECURSE SOURCES Source/*.cpp)
add_executable(BingoUI ${SOURCES})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")


# Load BingoCore
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)
if (NOT TARGET BingoCore)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)
endif ()
target_link_libraries(BingoUI BingoCore)
file(COPY Settings.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


# Load SDL2
find_program(LSB_RELEASE_EXEC lsb_release)
execute_process(COMMAND ${LSB_RELEASE_EXEC} -is OUTPUT_VARIABLE LSB_RELEASE_ID_SHORT OUTPUT_STRIP_TRAILING_WHITESPACE)
message("Your distro is ${LSB_RELEASE_ID_SHORT}")
find_package(SDL2 REQUIRED)
if ("${LSB_RELEASE_ID_SHORT}" STREQUAL "Arch")
    message("Arch distro detected, using Arch CMake linkage")
    target_link_libraries(BingoUI SDL2::SDL2)
else ()
    message("Non-Arch distro detected, using normal linkage")
    string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES) # Fix because CMake is stupid, remove trailing spaces
    include_directories(BingoUI ${SDL2_INCLUDE_DIRS})
    target_link_libraries(BingoUI ${SDL2_LIBRARIES})
endif ()


# Load SDL2 extensions
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SDL2TTF REQUIRED)
include_directories(BingoUI ${SDL2TTF_LIBRARY})
target_link_libraries(BingoUI ${SDL2TTF_LIBRARY})


# Copy Assets folder to build directory
file(COPY Assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

