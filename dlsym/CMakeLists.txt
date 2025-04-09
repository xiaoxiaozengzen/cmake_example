cmake_minimum_required(VERSION 3.23)
project(strip_dlsym)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(strip_dlsym ${SOURCES})
target_include_directories(
    strip_dlsym PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(strip_dlsym dl)