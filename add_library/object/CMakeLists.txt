cmake_minimum_required(VERSION 3.14)
project(add_library_object_example)

# OBJECT库不直接生成动态或者静态库，而是用于其他add_library或add_executable的目标
# 其他add_library或add_executable可以使用$<TARGET_OBJECTS:target_name>来引用OBJECT库的对象文件，类似源码一样
add_library(add_library_object_example OBJECT add.cpp)

add_executable(main_exe main.cpp $<TARGET_OBJECTS:add_library_object_example>)