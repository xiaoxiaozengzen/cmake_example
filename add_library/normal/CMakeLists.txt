cmake_minimum_required(VERSION 3.14)
project(add_library_normal_example)

# 生成的库类型：
#   - STATIC: 生成静态库
#   - SHARED: 生成动态库
#   - MODULE: 生成模块库，使用dlopen加载
# 注意：
#   1.默认是STATIC库
#   2.可以设置BUILD_SHARED_LIBS=ON来生默认生成动态库
#   3.对于SHARED和MODULE库，默认使用POSITION_INDEPENDENT_CODE属性
add_library(add_library_normal_example SHARED add.cpp)

add_executable(add_library_normal_example_exe main.cpp)
target_link_libraries(add_library_normal_example_exe PUBLIC add_library_normal_example)