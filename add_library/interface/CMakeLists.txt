cmake_minimum_required(VERSION 3.14)
project(add_library_example)


# 简单使用interfcae
# add_library(Plus INTERFACE Plus/plus.h)
# target_include_directories(Plus INTERFACE 
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Plus>
#     $<INSTALL_INTERFACE:include>
# )

include(Plus/install/lib/cmake/Plus/plusExport.cmake)

add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC Upstream::Plus)

get_target_property(IID Upstream::Plus INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "IID: ${IID}")