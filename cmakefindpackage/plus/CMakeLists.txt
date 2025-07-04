cmake_minimum_required(VERSION 3.23)
project(MyPlus)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)

include(CMakePackageConfigHelpers)

file(GLOB_RECURSE SRCS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(plus SHARED ${SRCS})
target_include_directories(
  plus PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
              $<INSTALL_INTERFACE:include>)

# 改名了会在你install(EXPORT ...)时候，将倒出的目标名改为Plus
set_target_properties(plus PROPERTIES EXPORT_NAME Plus)

# 第一步：告诉cmake将目标plus导出到MyPlusTargets文件中
install(TARGETS plus EXPORT ${PROJECT_NAME}Targets)

# 第二步：1.这一步会真正的将MyPlusTargets导出为cmake文件，并安装到指定位置 2.这样第三方才能通过find_package来找到这个库
install(
  EXPORT ${PROJECT_NAME}Targets
  NAMESPACE Plus::
  DESTINATION lib/cmake/${PROJECT_NAME})

set(PACKAGE_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include")
set(PACKAGE_LIB_DIR "${CMAKE_INSTALL_PREFIX}/lib")
set(PACKAGE_LIB "Plus::Plus")

# 用于生成第三方可以使用的find_package寻找的xxxConfig.cmake文件
configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
  INSTALL_DESTINATION
    lib/cmake/${PROJECT_NAME} # 不会进行实际安装，只是替换@PACKAGE_INSTALL_DESTINATION@变量
  NO_SET_AND_CHECK_MACRO # Eigen does not provide legacy style defines
  NO_CHECK_REQUIRED_COMPONENTS_MACRO # Eigen does not provide components
)
write_basic_package_version_file(
  ${PROJECT_NAME}ConfigVersion.cmake
  VERSION 1.1.1
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
        DESTINATION lib/cmake/MyPlus)

# 表示当前安装组件是Devel，可以在cmake --install . --component Devel时使用
# 记得加“include/”中的斜杠，否则会将include安装到include目录下
install(
  DIRECTORY include/
  DESTINATION include
  COMPONENT Devel)

# uninstall target
if(NOT TARGET uninstall)
  add_custom_target(
    uninstall COMMAND ${CMAKE_COMMAND} -P
                      ${CMAKE_CURRENT_SOURCE_DIR}/cmake/MyPlusUninstall.cmake)
endif()
