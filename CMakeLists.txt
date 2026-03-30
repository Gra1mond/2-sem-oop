cmake_minimum_required(VERSION 3.16)
project(MyProject)

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

add_subdirectory(part_1)
add_subdirectory(part_2)


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