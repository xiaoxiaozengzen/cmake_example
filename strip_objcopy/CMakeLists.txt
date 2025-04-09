cmake_minimum_required(VERSION 3.21)
project(strip_objcopy)

set(CMAKE_VERBOSE_MAKEFILE ON)

file(GLOB_RECURSE FUN_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(
    fun SHARED ${FUN_SRCS}
)
target_include_directories(
    fun PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME}_exe main.cpp)
target_include_directories(
    ${PROJECT_NAME}_exe PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include  
)
target_link_libraries(
    ${PROJECT_NAME}_exe PUBLIC
    fun 
)