cmake_minimum_required(VERSION 3.14)
project(add_library_example)

set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/plus/install/share)
find_package(Plus1 REQUIRED)


add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC Plus1::Plus)

get_target_property(IID Plus1::Plus INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "IID: ${IID}")