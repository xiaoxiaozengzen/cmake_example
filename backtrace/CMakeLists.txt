cmake_minimum_required(VERSION 3.23)
project(backtrace)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB SOURCES "src/*.cpp")
add_executable(backtrace_example ${SOURCES})
target_compile_options(backtrace_example PRIVATE -rdynamic)

# 必须加上这个选项，要不然链接阶段不会加rdynamic选项，程序运行的时候不会有符号信息
target_link_options(backtrace_example PRIVATE -rdynamic)