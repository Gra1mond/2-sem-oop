cmake_minimum_required(VERSION 3.20)

project(lab_2)


set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/menu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/wine_library.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/laba_2.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/wine_library.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/menu.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})

set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY
    CXX_STANDARD 20
)


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