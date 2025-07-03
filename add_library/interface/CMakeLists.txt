cmake_minimum_required(VERSION 3.14)
project(add_library_example)


# set(CMAKE_PREFIX_PATH /mnt/workspace/cgz_workspace/Exercise/cmake_example/add_library/interface/Plus/install/lib)
set(CMAKE_PREFIX_PATH /mnt/workspace/cgz_workspace/Exercise/cmake_example/add_library/interface/Plus/install/lib/cmake)

find_package(Plus REQUIRED)

add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC Plus::Plus)

get_target_property(IID Plus::Plus INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "IID: ${IID}")