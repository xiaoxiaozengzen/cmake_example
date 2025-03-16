cmake_minimum_required(VERSION 3.14)
project(main)

# add_definitions("-g")
# add_definitions("-DMy_D")

# add_compile_definitions(My_D)

# add_compile_options(-g)

# set(MY_DEFINE "My_DA") 不可以被cmake -DMY_DEFINE 覆盖。
# 可以被cmake -DMY_DEFINE 覆盖。
set(MY_DEFINE "My_DA" CACHE STRING "Define for conditional compilation")
message(STATUS "MY_DEFINE: ${MY_DEFINE}")
if(${MY_DEFINE} STREQUAL "My_DA")
    add_definitions(-DMy_DA)
elseif(${MY_DEFINE} STREQUAL "My_DB")
    add_definitions(-DMy_DB)
endif()

add_executable(main main.cpp)


