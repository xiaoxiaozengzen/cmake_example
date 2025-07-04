cmake_minimum_required(VERSION 3.23)
project(add_library_example)

# add_library(imported_plus SHARED IMPORTED)
# 作用是：在当前cmake项目中，声明一个外部已有的库目标。
#        这样你就可以像在本地使用库一样使用这个外部库。

# 例如：
# add_library(MyLib SHARED IMPORTED)
# set_target_properties(MyLib PROPERTIES
#     IMPORTED_LOCATION "/path/to/libmylib.so"
#     INTERFACE_INCLUDE_DIRECTORIES "/path/to/include"
# )
# target_link_libraries(myexe PRIVATE MyLib)

set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/plus/install/lib/cmake)
find_package(MyPlus REQUIRED)
message(STATUS "MyPlus_FOUND: ${MyPlus_FOUND}")
message(STATUS "MyPlus_DIR: ${MyPlus_DIR}")
message(STATUS "MyPlus_INCLUDE_DIRS: ${MyPlus_INCLUDE_DIRS}")
message(STATUS "MyPlus_LIBRARIES: ${MyPlus_LIBRARIES}")

add_executable(main_exe main.cpp)
target_link_libraries(main_exe PUBLIC Plus::Plus)
# target_include_directories(main_exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/plus/include)

# get_target_property(IID Plus1::Plus INTERFACE_INCLUDE_DIRECTORIES)
# message(STATUS "IID: ${IID}")
