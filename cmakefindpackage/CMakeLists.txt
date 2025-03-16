cmake_minimum_required(VERSION 3.4)
project(Te)

set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/plus/install/lib/cmake/mylib)
link_directories(${PLUS_LIBRARY_DIRS})

find_package(PLUS REQUIRED)
if(PLUS_FOUND)
	message(STATUS "PLUS_FOUND = ${PLUS_FOUND}")
	message(STATUS "PLUS_INCLUDE_DIRS = ${PLUS_INCLUDE_DIRS}")
	message(STATUS "PLUS_LIBRARIES = ${PLUS_LIBRARIES}")
	message(STATUS "PLUS_LIBRARY_DIRS = ${PLUS_LIBRARY_DIRS}")
endif()


add_executable(ppp ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_directories(ppp PUBLIC ${PLUS_LIBRARY_DIRS})
target_link_libraries(ppp ${PLUS_LIBRARIES})
target_include_directories(ppp PUBLIC ${PLUS_INCLUDE_DIRS})
