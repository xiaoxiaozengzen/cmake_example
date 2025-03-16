cmake_minimum_required(VERSION 3.23)
project(arguments)

macro(PRINT para)
    # 可以使用 "" 来表示不使用的部分，如果没有 optionk，可以对应位置支撑",例如：cmake_parse_arguments(ARG "" "DIRECTORY" "TARGET" ${ARGN})
    cmake_parse_arguments(ARG
        "STATIC;SHARED;MODULE;INTERFACE;EXCLUDE_FROM_ALL;NO_TARGET_LINK_LIBRARIES"
        "DIRECTORY"
        "TARGET"
        ${ARGN}
        )

        if(ARG_UNPARSED_ARGUMENTS)
            message(FATAL_ERROR "ament_auto_find_build_dependencies() called with " "unused arguments: ${ARG_UNPARSED_ARGUMENTS}")
        endif()

        if(ARG_DIRECTORY)
            message("Directory: ${ARG_DIRECTORY}")
        else()
            message("No directory")
        endif()

        if(ARG_STATIC)
            message("Static: " ${ARG_STATIC})
        else()
            message("No static")
        endif()

        if(ARG_TARGET)
            message("TARGET: " ${ARG_TARGET})
            foreach(tar ${ARG_TARGET})
                message("Target: ${tar}")                
            endforeach()            
        else()
            message("No TARGET")
        endif()

        message("Arguments: ${para}")
        message("ARGN: ${ARGN}")
        message("ARGC: ${ARGC}")
        message("ARGV: ${ARGV}")
        message("ARG0: ${ARG0}")
        message("ARG1: ${ARG1}")
endmacro()

PRINT(nihaoa TARGET hello world DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} STATIC)

# 会报错，因为参数hahah未被解析
# PRINT(nihaoa hahah TARGET hello world DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} STATIC)

add_executable(arguments main.cpp)