cmake_minimum_required(VERSION 2.8.2)

project(DP_Example)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

include(CTest)
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else ()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif ()

include(DownloadProject.cmake)
download_project(PROJ googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

# When using CMake 2.8.11 or later, header path dependencies
# are automatically added to the gtest and gmock targets.
# For earlier CMake versions, we have to explicitly add the
# required directories to the header search path ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif ()


file(GLOB SOURCES *.cpp)

# Trivial example using gtest and gmock
add_executable(BingoTest ${SOURCES})


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore/Include)
if (NOT TARGET BingoCore)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../BingoCore ${CMAKE_CURRENT_BINARY_DIR}/BingoCore)
endif ()
target_link_libraries(BingoTest BingoCore)


target_link_libraries(BingoTest gtest gmock_main)
add_test(NAME test COMMAND BingoTest)

file(COPY Settings.ini DESTINATION ${CMAKE_CURRENT_BINARY_DIR})