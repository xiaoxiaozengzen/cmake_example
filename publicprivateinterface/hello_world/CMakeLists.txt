cmake_minimum_required(VERSION 3.14)

add_subdirectory(hello)

if(${OPT} STREQUAL "PUBLIC")
    message(STATUS "-------------------------helloworld OPT: PUBLIC")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp.public ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp.public ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp)
elseif(${OPT} STREQUAL "PRIVATE")
    message(STATUS "-------------------------helloworld OPT: PRIVATE")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp.private ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp.private ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp)
elseif(${OPT} STREQUAL "INTERFACE")
    message(STATUS "-------------------------helloworld OPT: INTERFACE")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp.interface ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp.interface ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp)
else()
    message(STATUS "-------------------------helloworld OPT: DEFAULT(PUBLIC)")
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp.public ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.cpp)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp.public ${CMAKE_CURRENT_SOURCE_DIR}/hello_world.hpp)
endif()

add_library(hello_world SHARED hello_world.cpp)

if(${OPT} STREQUAL "PUBLIC")
    target_link_libraries(hello_world PUBLIC hello)
    target_include_directories(hello_world PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hello)
elseif(${OPT} STREQUAL "PRIVATE")
    target_link_libraries(hello_world PRIVATE hello)
    target_include_directories(hello_world PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/hello)
elseif(${OPT} STREQUAL "INTERFACE")
    target_link_libraries(hello_world INTERFACE hello)
    target_include_directories(hello_world INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/hello)
else()
    target_link_libraries(hello_world PUBLIC hello)
    target_include_directories(hello_world PUBLIC hello)
endif()

get_target_property(TARGET_INCLUDE_DIRS_PUBLIC hello_world PUBLIC_INCLUDE_DIRECTORIES)
get_target_property(TARGET_INCLUDE_DIRS_PRIVATE hello_world PRIVATE_INCLUDE_DIRECTORIES)
get_target_property(TARGET_INCLUDE_DIRS_INTERFACE hello_world INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(TARGET_INCLUDE_DIRS hello_world INCLUDE_DIRECTORIES)

message(STATUS "hello_world PUBLIC_INCLUDE_DIRECTORIES: ${TARGET_INCLUDE_DIRS_PUBLIC}")
message(STATUS "hello_world PRIVATE_INCLUDE_DIRECTORIES: ${TARGET_INCLUDE_DIRS_PRIVATE}")
message(STATUS "hello_world INTERFACE_INCLUDE_DIRECTORIES: ${TARGET_INCLUDE_DIRS_INTERFACE}")
message(STATUS "hello_world INCLUDE_DIRECTORIES: ${TARGET_INCLUDE_DIRS}")

