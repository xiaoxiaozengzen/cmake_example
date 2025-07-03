cmake_minimum_required(VERSION 3.14)
project(add_library_example)

set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install)

# INTERFACE库：改类型的库不包含任何源文件，也不会在磁盘上生成任何目标文件。
# 它们只包含头文件和编译选项。
# 可以使用以下命令将INTERFACE属性添加到目标上：
#   - add_library(Plus INTERFACE)
#   - target_include_directories(Plus INTERFACE include/plus.h)
#   - target_compile_definitions(Plus INTERFACE PLUS_VERSION=1.0)
#   - target_compile_options(Plus INTERFACE -Wall -Wextra)
# 之后，改目标可以通过target_link_libraries命令被其他目标链接。
add_library(Plus INTERFACE)
target_include_directories(Plus INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS Plus
  EXPORT PlusTargets
)

# 安装头文件
install(DIRECTORY include/ DESTINATION include)

# 导出 targets
install(EXPORT PlusTargets
    FILE PlusTargets.cmake
    NAMESPACE Plus::
    DESTINATION lib/cmake/Plus
)

# 生成和安装 Config 文件
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/PlusConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/PlusConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/PlusConfig.cmake"
    INSTALL_DESTINATION lib/cmake/Plus
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/PlusConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/PlusConfigVersion.cmake"
    DESTINATION lib/cmake/Plus
)
