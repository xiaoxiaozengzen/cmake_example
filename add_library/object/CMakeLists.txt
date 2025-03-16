cmake_minimum_required(VERSION 3.14)
project(add_library_example)

add_library(add_library_example OBJECT add.cpp)

add_executable(main_exe main.cpp $<TARGET_OBJECTS:add_library_example>)