cmake_minimum_required(VERSION 3.4)
project(Plus1)

SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
set(CMAKE_INSTALL_DATADIR ${CMAKE_INSTALL_PREFIX}/share)

install(DIRECTORY Plus DESTINATION ${CMAKE_INSTALL_PREFIX}/include COMPONENT Devel)

set(CMAKEPACKAGE_INSTALL_DIR ${CMAKE_INSTALL_DATADIR}/Plus/cmake)

include(CMakePackageConfigHelpers)

add_library(plus INTERFACE)
add_library(Plus1::Plus ALIAS plus)
target_include_directories(plus INTERFACE 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
	$<INSTALL_INTERFACE:${INCLUDE_INSTALL_DIR}>
)

set_target_properties(plus PROPERTIES EXPORT_NAME Plus)

install(
	TARGETS plus
	EXPORT Plus1Targets
)

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/Plus1Config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/Plus1Config.cmake
	INSTALL_DESTINATION ${CMAKEPACKAGE_INSTALL_DIR}
	NO_SET_AND_CHECK_MACRO # Eigen does not provide legacy style defines
	NO_CHECK_REQUIRED_COMPONENTS_MACRO # Eigen does not provide components
)
write_basic_package_version_file(
	Plus1ConfigVersion.cmake
	VERSION 1.1.1
	COMPATIBILITY SameMajorVersion
)

export(
	TARGETS plus
	NAMESPACE Plus1::
	FILE Plus1Targets.cmake
)

export(PACKAGE Plus1)

install(
	EXPORT Plus1Targets
	NAMESPACE Plus1::
	DESTINATION ${CMAKEPACKAGE_INSTALL_DIR}
)


install(
	FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
	DESTINATION ${CMAKEPACKAGE_INSTALL_DIR}
)

# uninstall target
if(NOT TARGET uninstall)
  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/PlusUninstall.cmake)
endif()


