cmake_minimum_required(VERSION 3.5.1)

# Create project
project(BingoUI)

# Set the C++17 standard
set(CMAKE_CXX_STANDARD 17)

# Load BingoCore project
include_directories(Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)
file(GLOB_RECURSE SOURCES Source/*.cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)

# Load SDL2
find_package(SDL2 REQUIRED)
if (NOT DEFINED ${SDL2_INCLUDE_DIRS})
    message(FATAL_ERROR "Can't find SDL2 include dirs")
endif ()
if (NOT DEFINED ${SDL2_LIBRARIES})
    message(FATAL_ERROR "Can't find SDL2 libraries")
endif ()
include_directories(BingoUI ${SDL2_INCLUDE_DIRS})

# Load SDL2 extensions
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
find_package(SDL2TTF REQUIRED)
if (NOT DEFINED ${SDL2TTF_LIBRARY})
    message(FATAL_ERROR "Can't find SDL2_TTF include dirs")
endif ()
include_directories(BingoUI ${SDL2TTF_LIBRARY})

# Link everything
link_libraries(BingoCore)
add_executable(BingoUI ${SOURCES})
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES) # Fix because CMake is stupid, remove trailing spaces
target_link_libraries(BingoUI ${SDL2_LIBRARIES})
target_link_libraries(BingoUI ${SDL2TTF_LIBRARY})

# Copy Assets folder to build directory
file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})
