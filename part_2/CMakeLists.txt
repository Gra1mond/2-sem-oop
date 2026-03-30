set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/fraction.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/string.hpp
)

add_executable(MyProject_part2 ${SOURCES} ${HEADERS})

set_target_properties(MyProject_part2 PROPERTIES
    CXX_STANDARD 20
)

target_compile_options(MyProject_part2 
    PRIVATE -Wall -Wextra -Wpedantic -Werror
)