# Overview

`pkg-config` 通过一个统一的接口以及一组 `.pc` 文件，使得查询库相关的信息变得简单。

```bash

# which pkg-config
/usr/bin/pkg-config

# pkg-config --list-all
gl                                          GL - Legacy OpenGL and GLX library and headers.
pcl_visualization-1.10                      pcl_visualization - Point cloud visualization library
pcl_in_hand_scanner-1.10                    pcl_in_hand_scanner - In-hand scanner for small objects
nppim-12.4                                  nppim - NVIDIA Performance Primitives - Image Processing - Morphological
icu-io                                      icu-io - International Components for Unicode: Stream and I/O Library
pcl_io-1.10                                 pcl_io - Point cloud IO library
absl_synchronization                        absl_synchronization - Abseil synchronization library
nvToolsExt-12.5                             nvToolsExt - NVIDIA Tools Extension
absl_compare                                absl_compare - Abseil compare library
absl_meta                                   absl_meta - Abseil meta library
xi                                          Xi - X Input Extension Library

```

# 命令行工具

pkg-config是一个命令行工具，用于提供库（libraries）的编译和链接信息。
当你在项目中使用外部库时，通常需要知道这些库的头文件（header files）和库文件（library files）的位置。
pkg-config通过读取特定的.pc（Package Config）文件来提供这些信息。

工作流程：
* 查询库信息: 当你执行pkg-config命令时，它首先会在预定义的目录（通常是/usr/lib/pkgconfig/或/usr/share/pkgconfig/）中查找与指定库相关的.pc文件。
* 读取.pc文件: 找到.pc文件后，pkg-config会解析其中的字段，这些字段包括但不限于Cflags（编译选项）和Libs（链接选项）。
* 输出信息: 根据你的命令选项（如--cflags或--libs），pkg-config会输出相应的信息，这些信息可以直接用于编译和链接

## 环境变量

可以通过环境变量影响 `pkg-config` 的行为：
* PKG_CONFIG_PATH：用于指定.pc文件的搜索路径，会在默认路径下添加改路径
* PKG_CONFIG_LIBDIR：这个环境变量用于覆盖默认的.pc文件搜索路径。

## pc文件内容

.pc（Package Config）文件是pkg-config工具的核心，它包含了库的元数据，如头文件路径、库文件路径、编译和链接选项等。

一个典型的.pc文件包括以下几个部分：

```bash
# /usr/lib/pkgconfig/cublas-11.pc 

# 自定义变量，并且可以在编译和链接字段使用
cudaroot=/usr/local/cuda-11.4/
libdir=${cudaroot}/targets/x86_64-linux/lib
includedir=${cudaroot}/targets/x86_64-linux/include

# 基础字段
Name: cublas
Description: CUDA Basic Linear Algebra Subprograms
Version: 11

# 编译和链接字段
Libs: -L${libdir} -lcublas
Cflags: -I${includedir}

```

# 与cmake配合使用