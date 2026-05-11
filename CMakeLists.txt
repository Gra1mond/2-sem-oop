cmake_minimum_required(VERSION 3.16)
project(lab_8)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")


set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/listNode.h
    ${CMAKE_CURRENT_SOURCE_DIR}/myStack.h
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

target_compile_options(${CMAKE_PROJECT_NAME} 
    PRIVATE -Wall -Wextra -Wpedantic -Werror
)


if(ENABLE_DEBUG)
    
    target_compile_options(${CMAKE_PROJECT_NAME} 
        PRIVATE -g
    )
endif()

add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run           
    -Werror
    ${SOURCES}
    ${HEADERS}
)