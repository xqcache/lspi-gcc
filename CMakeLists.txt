cmake_minimum_required(VERSION 3.23.0 FATAL_ERROR)

string(REGEX REPLACE "[/\\]$" "" PROJECT_PATH ${CMAKE_SOURCE_DIR})
string(REGEX REPLACE ".*/(.*)$" "\\1" TARGET_NAME ${PROJECT_PATH})

project(${TARGET_NAME} VERSION 0.0.1 LANGUAGES C CXX ASM)

set(CMAKE_EXECUTABLE_SUFFIX ".elf")

add_executable(${TARGET_NAME})
target_compile_definitions(${TARGET_NAME} PRIVATE "${COMPILER_DEFINES}")

add_subdirectory(src)
add_subdirectory(lib)

set(CROSS_COMPILER_PREFIX "arm-none-eabi-")
set(TOOL_OBJCOPY ${CROSS_COMPILER_PREFIX}objcopy)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${TOOL_OBJCOPY} -O ihex $<TARGET_FILE:${TARGET_NAME}> $<TARGET_FILE_DIR:${TARGET_NAME}>/$<TARGET_FILE_BASE_NAME:${TARGET_NAME}>.hex
)
