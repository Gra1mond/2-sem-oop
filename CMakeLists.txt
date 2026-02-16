cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

project(laba_1)

set(SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/laba_1.cpp
${CMAKE_CURRENT_SOURCE_DIR}/datelib.cpp
)

set(HEADERS
${CMAKE_CURRENT_SOURCE_DIR}/datelib.h
)
add_library(dateDifference STATIC datelib.cpp)
add_executable(${CMAKE_PROJECT_NAME} laba_1.cpp)

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

target_link_libraries(${CMAKE_PROJECT_NAME} dateDifference)

add_custom_target(
    clang-format
    COMMAND
    clang-format
    --dry-run
    --WError
    ${SOURCES}
    ${HEADERS}
)