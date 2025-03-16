cmake_minimum_required(VERSION 3.23)
project(my_library)

add_library(my_library SHARED src/my_library.cpp)
target_include_directories(
    my_library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)