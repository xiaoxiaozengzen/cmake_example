cmake_minimum_required(VERSION 3.4)
project(PLUS)

SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

add_library(plus SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/plus.cpp)
target_include_directories(plus PUBLIC 
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>)

set_target_properties(plus PROPERTIES
					  VERSION 2.1.1
					  SOVERSION 2
					  PUBLIC_HEADER "include/plus.h")

install(
	TARGETS plus
	EXPORT ${PROJECT_NAME}Targets
	PUBLIC_HEADER DESTINATION include
	ARCHIVE DESTINATION lib
 	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
)

install(
	EXPORT ${PROJECT_NAME}Targets
	FILE ${PROJECT_NAME}Targets.cmake
	DESTINATION lib/cmake/mylib
)

set(INCLUDE_DIRS include)
set(LIBRARIES plus)
set(LIB_DIR lib)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
	${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	VERSION 1.1.1
	COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
	${PROJECT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in
	${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
	INSTALL_DESTINATION lib/cmake/mylib
	PATH_VARS INCLUDE_DIRS LIBRARIES LIB_DIR
	INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}
)

install(
	FILES ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	DESTINATION lib/cmake/mylib
)

# uninstall target
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()


