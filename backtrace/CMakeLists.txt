cmake_minimum_required(VERSION 3.23)
project(backtrace)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-rdynamic)

file(GLOB SOURCES "src/*.cpp")
add_executable(backtrace_example ${SOURCES})