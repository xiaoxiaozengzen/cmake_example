cmake_minimum_required(VERSION 3.23)
project(release_debug)

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(release_debug ${SOURCES})
target_include_directories(release_debug PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)