cmake_minimum_required(VERSION 3.23)
project(add_library_example)


include("${CMAKE_CURRENT_SOURCE_DIR}/plus/build/MyPlusTargets.cmake")

add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC Plus::Plus)
