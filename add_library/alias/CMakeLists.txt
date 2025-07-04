cmake_minimum_required(VERSION 3.14)
project(add_library_example)

add_library(Plus SHARED Plus/src/plus.cpp)
target_include_directories(Plus PUBLIC Plus/include)

# 可以将库的别名设置为 Upstream::Plus
# 这样在其他地方引用时可以使用 Upstream::Plus 来代替 Plus
# 这对于大型项目或库的组织结构很有用
# 注意：别名的库本身不能被install或者export
add_library(Upstream::Plus ALIAS Plus)

add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC Upstream::Plus)

get_target_property(IID Upstream::Plus INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "IID: ${IID}")