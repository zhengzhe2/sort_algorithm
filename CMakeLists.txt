CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

project(Doip)

add_definitions(-D LINUX_OS)

SET(SRC_FILES
        "sort.c")

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_executable(sort main.c ${SRC_FILES})
