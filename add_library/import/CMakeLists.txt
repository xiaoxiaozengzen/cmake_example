cmake_minimum_required(VERSION 3.23)
project(add_library_example)

set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/plus/install/lib/cmake)
find_package(MyPlus REQUIRED)
message(STATUS "MyPlus_FOUND: ${MyPlus_FOUND}")
message(STATUS "MyPlus_DIR: ${MyPlus_DIR}")
message(STATUS "MyPlus_INCLUDE_DIRS: ${MyPlus_INCLUDE_DIRS}")
message(STATUS "MyPlus_LIBRARIES: ${MyPlus_LIBRARIES}")
message(STATUS "MyPlus_LIBRARY_DIRS: ${MyPlus_LIBRARY_DIRS}")

add_library(PLUS SHARED IMPORTED)
set_target_properties(PLUS PROPERTIES
    IMPORTED_LOCATION "${MyPlus_LIBRARY_DIRS}/libplus.so"  # Path to the shared library
    INTERFACE_INCLUDE_DIRECTORIES "${MyPlus_INCLUDE_DIRS}"  # Path to the header files
)

add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC PLUS)

