cmake_minimum_required(VERSION 3.21)
project(add_custom)

# output必须用于构建一个target, 否则不会被生成
# 生成的文件在默认在build目录下
add_custom_command(
    OUTPUT input.cpp
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/input.cpp.in input.cpp
    COMMENT "Generating input.cpp"
)

# 1.方式一
# add_custom_command()生成的文件必须用于构建一个target, 否则不会被生成
# add_executable(add_custom $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/input.cpp>)

# 2.方式二
# add_custom_target()不会生成文件, 只是一个target
# 但是可以用于构建其他target
# 例如下面的例子, my_target依赖于input.cpp, 所以input.cpp会被生成
# 但是my_target不会生成任何文件
add_custom_target(
  my_target ALL
  DEPENDS input.cpp
)
add_executable(add_custom ${CMAKE_CURRENT_BINARY_DIR}/input.cpp)