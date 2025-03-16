ConfigCmakeGenerate
===================

# Overview

用于生成自己的xxxConfig.cmake文件，可以作为第三方package让其他项目使用

# 使用方式

## 生成plusConfig.cmake

进到 `ConfigCmakeGenerate/plus`，该文件会生成 `plusConfig.cmake`文件，主要作用时提供一个加法
操作步骤如下:

```bash
mkdir build
cd build

cmake ..
make
make install

```

生成后的 `plusConfig.cmake`文件在 `ConfigCmakeGenerate/plus/install/lib/mylib/`下，你可以在编译其他项目的时候使用

## 使用plusConfig.cmake

进到 `ConfigCmakeGenerate`,在其 `CMakeLists.txt`写入以下语句

```bash
add_executable(ppp ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

target_link_directories(${TARGET_NAME} PUBLIC ${PLUS_LIBRARY_DIRS})
target_link_libraries(${TARGET_NAME} ${PLUS_LIBRARIES})
target_include_directories(${TARGET_NAME} PUBLIC ${PLUS_INCLUDE_DIRS})find_package(PLUS REQUIRED)

```
