cmake_minimum_required(VERSION 3.21)
project(pkg_config_example)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# /usr/share/cmake-3.31/Modules/FindPkgConfig.cmake
find_package(PkgConfig REQUIRED)
message(STATUS "PkgConfig_FOUND: ${PkgConfig_FOUND}")
message(STATUS "PKG_CONFIG_EXECUTABLE: ${PKG_CONFIG_EXECUTABLE}")
message(STATUS "PKG_CONFIG_FOUND: ${PKG_CONFIG_FOUND}")
message(STATUS "PKG_CONFIG_VERSION_STRING: ${PKG_CONFIG_VERSION_STRING}")
message(STATUS "PKG_CONFIG_VERSION: ${PKG_CONFIG_VERSION}")
message(STATUS "PKG_CONFIG_ARGN: ${PKG_CONFIG_ARGN}")

pkg_search_module(FMT REQUIRED fmt)
message(STATUS "FMT_FOUND: ${FMT_FOUND}")
message(STATUS "FMT_INCLUDE_DIRS: ${FMT_INCLUDE_DIRS}")
message(STATUS "FMT_LIBRARIES: ${FMT_LIBRARIES}")
message(STATUS "FMT_VERSION: ${FMT_VERSION}")

add_executable(pkg_config_example example.cpp)