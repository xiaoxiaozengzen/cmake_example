cmake_minimum_required(VERSION 3.23)
project(MyPlus)

file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(plus SHARED ${SRCS})
target_include_directories(
  plus PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
              $<INSTALL_INTERFACE:include>)

set_target_properties(plus PROPERTIES EXPORT_NAME Plus)

export(TARGETS plus
       NAMESPACE Plus::
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")
