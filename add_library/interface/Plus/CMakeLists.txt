cmake_minimum_required(VERSION 3.14)
project(add_library_example)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

add_library(Plus INTERFACE include/plus.h)
target_include_directories(Plus INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include/Plus>
)

install(TARGETS Plus EXPORT plusExport)
install(EXPORT plusExport NAMESPACE Upstream::
  DESTINATION lib/cmake/Plus
)
install(FILES include/plus.h
  DESTINATION include/Plus
)