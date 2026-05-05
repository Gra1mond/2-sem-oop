cmake_minimum_required(VERSION 3.16)
project(lab_7)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

file(GLOB SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/containers/*.cpp
)

file(GLOB HEADERS CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/containers/*.h
)

add_library(poly STATIC
    containers/Term.cpp
    containers/Polynomial.cpp
)

target_include_directories(poly PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/containers
)
target_compile_options(poly PRIVATE -Wall -Wextra -Wpedantic -Werror)

add_executable(lab_7
    main.cpp
)

target_link_libraries(lab_7 PRIVATE poly)
target_compile_options(lab_7 PRIVATE -Wall -Wextra -Wpedantic -Werror)


if(ENABLE_DEBUG)
    target_compile_options(poly PRIVATE -g)
    target_compile_options(lab_7 PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run
    -Werror
    ${SOURCES}
    ${HEADERS}
)
